#!/bin/bash
set -eu
TEMPLATE_NAME="allTemplate"
START_FROM="${1:-}"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    if [[ $item < $START_FROM ]]; then
        continue
    fi
    pushd "$item"
    cmake .
    make
    popd
done
