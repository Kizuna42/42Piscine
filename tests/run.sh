#!/bin/bash
# リポジトリ全体のビルド確認とテストを行うスクリプト（CI からも実行される）
# 使い方: bash tests/run.sh
set -u

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
CC="${CC:-cc}"
CFLAGS=(-Wall -Wextra -Werror)
SAN=(-g -fsanitize=address,undefined -fno-sanitize-recover=all)
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
FAILED=0

pass() { printf '  OK   %s\n' "$1"; }
fail() { printf '  FAIL %s\n' "$1"; FAILED=1; }

cd "$ROOT" || exit 1

echo "== 1. C 課題のコンパイル確認 (${CFLAGS[*]})"
while IFS= read -r -d '' src; do
	if out=$("$CC" "${CFLAGS[@]}" -I tests/include -c "$src" -o "$WORK/obj.o" 2>&1); then
		pass "$src"
	else
		fail "$src"
		printf '%s\n' "$out"
	fi
done < <(find C -name '*.c' -print0 | sort -z)

echo "== 2. ユニットテスト (AddressSanitizer / UBSan)"
for test in tests/unit/test_*.c; do
	read -r -a sources <<< "$(sed -n '1s|^/\* SOURCES: \(.*\) \*/$|\1|p' "$test")"
	if [ "${#sources[@]}" -eq 0 ]; then
		fail "$test (SOURCES 行がありません)"
		continue
	fi
	bin="$WORK/$(basename "$test" .c)"
	if ! out=$("$CC" "${CFLAGS[@]}" "${SAN[@]}" -I tests/unit \
			"$test" "${sources[@]}" -o "$bin" 2>&1); then
		fail "$test (ビルド失敗)"
		printf '%s\n' "$out"
	elif ! out=$("$bin" 2>&1); then
		fail "$test"
		printf '%s\n' "$out"
	else
		pass "$test"
	fi
done

# $1: 名前, $2: 期待する出力, 以降: 実行するコマンド
expect_output() {
	local name="$1" expected="$2" actual
	shift 2
	if actual=$("$@" 2>&1) && [ "$actual" = "$expected" ]; then
		pass "$name"
	else
		fail "$name"
		printf '    expected: %q\n    actual:   %q\n' "$expected" "$actual"
	fi
}

echo "== 3. 出力を伴うプログラムの実行確認"
cat > "$WORK/combn_main.c" <<'C'
#include <stdlib.h>

void	ft_print_combn(int n);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(atoi(argv[1]));
	return (0);
}
C
if "$CC" "${CFLAGS[@]}" "${SAN[@]}" "$WORK/combn_main.c" \
		C/C00/ex08/ft_print_combn.c -o "$WORK/combn"; then
	expect_output "ft_print_combn(1)" "0, 1, 2, 3, 4, 5, 6, 7, 8, 9" "$WORK/combn" 1
	expect_output "ft_print_combn(9)" "$(printf '%s, ' 012345678 012345679 012345689 \
		012345789 012346789 012356789 012456789 013456789 023456789)123456789" \
		"$WORK/combn" 9
	expect_output "ft_print_combn(10)" "0123456789" "$WORK/combn" 10
else
	fail "ft_print_combn (ビルド失敗)"
fi

expected_rush00=(
	$'o---o\n|   |\n|   |\n|   |\no---o'
	$'/***\\\n*   *\n*   *\n*   *\n\\***/'
	$'ABBBA\nB   B\nB   B\nB   B\nCBBBC'
	$'ABBBC\nB   B\nB   B\nB   B\nABBBC'
	$'ABBBC\nB   B\nB   B\nB   B\nCBBBA'
)
for n in 0 1 2 3 4; do
	bin="$WORK/rush0$n"
	if "$CC" "${CFLAGS[@]}" Rush/Rush00/ex00/main.c Rush/Rush00/ex00/ft_putchar.c \
			"Rush/Rush00/ex00/rush0$n.c" -o "$bin"; then
		expect_output "Rush00 rush0$n" "${expected_rush00[$n]}" "$bin"
	else
		fail "Rush00 rush0$n (ビルド失敗)"
	fi
done

if "$CC" "${CFLAGS[@]}" Rush/Rush01/ex00/*.c -o "$WORK/rush01"; then
	expect_output "Rush01 4x4" $'1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3' \
		"$WORK/rush01" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
else
	fail "Rush01 (ビルド失敗)"
fi
if "$CC" "${CFLAGS[@]}" Rush/Rush01/ex00/5/*.c -o "$WORK/rush01_5"; then
	pass "Rush01/5 (ビルドのみ)"
else
	fail "Rush01/5 (ビルド失敗)"
fi

rm -rf "$WORK/rush02" && cp -R Rush/Rush02/ex00 "$WORK/rush02"
if make -s -C "$WORK/rush02" >/dev/null; then
	(
		cd "$WORK/rush02" || exit 1
		expect_output "Rush02 42" "forty two" ./rush-02 42
		expect_output "Rush02 1000000" "one million" ./rush-02 1000000
		expect_output "Rush02 -1" "Error" ./rush-02 -1
	) || FAILED=1
else
	fail "Rush02 (make 失敗)"
fi

echo
if [ "$FAILED" -ne 0 ]; then
	echo "失敗したチェックがあります"
	exit 1
fi
echo "すべてのチェックに成功しました"
