#!/bin/bash
set -eu
EXERCISE="$1"
CATCH_VERSION="v2.11.3"
CATCH_URL="https://github.com/catchorg/Catch2/releases/download/$CATCH_VERSION/catch.hpp"
curl -sSL "$CATCH_URL" -o "$EXERCISE/test/catch.hpp"