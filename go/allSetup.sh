#!/bin/bash
set -eu
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ -f "$item/go.mod" ]]; then
        continue
    fi
    pushd "$item"
    go mod init "exercism.io/${item}"
    popd
done
