#!/bin/bash
set -eu
shopt -s dotglob
TEMPLATE_NAME=".bootstrap"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    pushd "$item"
    cp "$TEMPLATE_DIR/"* .
    popd
done
