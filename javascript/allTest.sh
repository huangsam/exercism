#!/bin/bash
set -eu
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    pushd "$item"
    if [[ ! -d node_modules ]]; then
        npm install
    fi
    npm test
    popd
done
