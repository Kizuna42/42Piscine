#!/bin/bash
# 引数の C ファイルを 42 の警告フラグでコンパイルし、/tmp 上で実行して削除する
# 使い方: bash compile/compile.sh file1.c [file2.c ...]
set -e
bin="$(mktemp /tmp/compiled.XXXXXX)"
trap 'rm -f "$bin"' EXIT
cc -Wall -Wextra -Werror -o "$bin" "$@"
cd /tmp
"$bin"
