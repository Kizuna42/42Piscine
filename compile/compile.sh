#!/bin/bash
set -e
cc -Wall -Wextra -Werror -o /tmp/compiled.out "$@"
cd /tmp
./compiled.out
rm compiled.out
