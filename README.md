# 42Piscine

42 Piscine（入学試験プール）で取り組んだ課題のアーカイブです。

## ディレクトリ構成

| パス | 内容 |
| --- | --- |
| `Shell/` | Shell00 / Shell01 の課題 |
| `C/` | C00〜C11 の課題（C10 は未収録） |
| `Rush/` | Rush00（四角形の描画）、Rush01（4x4 のスカイスクレイパーパズル）、Rush02（数字を英語に変換） |
| `subject/` | 課題 PDF（日本語版） |
| `compile/compile.sh` | 指定した C ファイルを `-Wall -Wextra -Werror` でコンパイルして実行するヘルパー |
| `tests/` | ビルド確認とテスト（CI でも実行） |

## ビルドと実行

```sh
# 単体の課題を試す（main を含むファイルを一緒に渡す）
bash compile/compile.sh C/C06/ex00/ft_print_program_name.c

# Rush00（rush00.c〜rush04.c のいずれか 1 つを選ぶ）
cc -Wall -Wextra -Werror Rush/Rush00/ex00/main.c Rush/Rush00/ex00/ft_putchar.c Rush/Rush00/ex00/rush00.c

# Rush01
cc -Wall -Wextra -Werror Rush/Rush01/ex00/*.c -o rush-01
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

# Rush02
make -C Rush/Rush02/ex00
cd Rush/Rush02/ex00 && ./rush-02 42
```

## テスト

```sh
bash tests/run.sh
```

次の 3 段階を実行します。GitHub Actions（`.github/workflows/ci.yml`）でも push / PR ごとに同じスクリプトが動きます。

1. `C/` 以下のすべての `.c` を `-Wall -Wextra -Werror` でコンパイル
2. `tests/unit/` のユニットテストを AddressSanitizer / UndefinedBehaviorSanitizer 付きで実行
3. `ft_print_combn` と Rush00〜02 の出力を期待値と比較

ユニットテストを追加するときは、`tests/unit/test_*.c` の 1 行目に
`/* SOURCES: C/Cxx/exyy/foo.c ... */` の形式でリンクする課題ファイルを書きます。
同名の補助関数（`ft_strlen` など）を定義しているファイル同士は同じテストにまとめられません。

C08 ex04 / ex05 が使う `ft_stock_str.h` は課題で配布されるヘッダのため、
コンパイル確認用のものを `tests/include/` に置いています。
