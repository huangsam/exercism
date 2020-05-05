#!/bin/bash
set -eu
TEMPLATE_NAME="allTemplate"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
for item in *; do
    if [[ -d $item ]]; then
        if [[ $item == "$TEMPLATE_NAME" ]]; then
            continue
        fi
        pushd $item
        make clean
        popd
    fi
done
