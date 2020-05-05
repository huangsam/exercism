#!/bin/bash
set -eu
TEMPLATE_NAME="allTemplate"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    pushd "$item"
    make clean
    popd
done
