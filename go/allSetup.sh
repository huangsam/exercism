#!/bin/bash
set -eu
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    pushd "$item"
    if [[ -f go.mod ]]; then
        continue
    fi
    go mod init "exercism.io/${item}"
    popd
done
