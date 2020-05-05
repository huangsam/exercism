#!/bin/bash
set -eu
START_FROM="${1:-}"
TEMPLATE_NAME="allTemplate"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
for item in *; do
    if [[ -d $item ]]; then
        if [[ $item == "$TEMPLATE_NAME" ]]; then
            continue
        fi
        if [[ $item < $START_FROM ]]; then
            continue
        fi
        pushd $item
        cmake .
        make
        popd
    fi
done
