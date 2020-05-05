#!/bin/bash
set -eu
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    pushd "$item"
    gradle test
    popd
done
