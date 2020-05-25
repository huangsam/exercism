#!/bin/bash
set -eu
TEMPLATE_NAME=".bootstrap"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    pushd "$item"
    test -f Makefile && make clean
    popd
done
