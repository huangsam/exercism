#!/bin/bash
set -eu
shopt -s dotglob
TEMPLATE_DIR="$(pwd)"
EXERCISM_BASE="https://raw.githubusercontent.com/exercism/javascript/main"
EXERCISM_FILES=("package.json" "package-lock.json" "babel.config.js")
for file in "${EXERCISM_FILES[@]}"; do
    curl "$EXERCISM_BASE/$file" -fsSo "$TEMPLATE_DIR/$file"
done
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    pushd "$item"
    for file in "${EXERCISM_FILES[@]}"; do
        cp "$TEMPLATE_DIR/$file" .
    done
    popd
done
