#!/bin/bash
set -eu
for fl in *; do
    if [[ -d "$fl" ]]; then
        bash -c "cd $fl && pwd && go fmt"
    fi
done
