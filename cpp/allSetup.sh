#!/bin/bash
set -eu
TEMPLATE_NAME="allTemplate"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    pushd "$item"
    cp -r "$TEMPLATE_DIR/test" .
    cp "$TEMPLATE_DIR/CmakeLists.txt" .
    popd
done
