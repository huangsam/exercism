#!/bin/bash
set -eu
TEMPLATE_NAME=".bootstrap"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
CATCH_VERSION="v2.11.3"
CATCH_URL="https://github.com/catchorg/Catch2/releases/download/$CATCH_VERSION/catch.hpp"
CATCH_PATH="$TEMPLATE_DIR/test/catch.hpp"
if [[ ! -f $CATCH_PATH ]]; then
    curl -sSL "$CATCH_URL" -o "$CATCH_PATH"
fi
for item in *; do
    if [[ ! -d $item ]]; then
        continue
    fi
    if [[ $item == "$TEMPLATE_NAME" ]]; then
        continue
    fi
    pushd "$item"
    cp -r "$TEMPLATE_DIR/test" .
    cp "$TEMPLATE_DIR/CmakeLists.txt" .
    popd
done
