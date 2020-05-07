#!/bin/bash
set -eu
COPY_NAME="$1"
COPY_DIR="$(pwd)/$COPY_NAME"
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == $COPY_NAME ]]; then
        continue
    fi
    pushd "$item"
    cp "$COPY_DIR/.eslintrc" .
    cp "$COPY_DIR/babel.config.js" .
    cp "$COPY_DIR/package-lock.json" .
    cp "$COPY_DIR/package.json" .
    popd
done
