#!/bin/bash
for item in *; do
    if [[ -d $item ]]; then
        pushd $item
        cmake .
        make
        make clean
        popd
    fi
done
