#!/bin/bash
set -eu
TEMPLATE_NAME="allBootstrap"
TEMPLATE_DIR="$(pwd)/$TEMPLATE_NAME"
CATCH_VERSION="v2.11.3"
CATCH_URL="https://github.com/catchorg/Catch2/releases/download/$CATCH_VERSION/catch.hpp"
curl -sSL "$CATCH_URL" -o "$TEMPLATE_DIR/test/catch.hpp"
