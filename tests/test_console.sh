#!/usr/bin/env bash

set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$(mktemp -d)"
trap 'rm -rf "$BUILD_DIR"' EXIT

g++ -std=c++17 -Wall -Wextra -pedantic "$PROJECT_DIR/main.cpp" -o "$BUILD_DIR/volleyball_tracker"
output="$($BUILD_DIR/volleyball_tracker)"

grep -Fq "Player One" <<<"$output"
grep -Fq "90.0%" <<<"$output"
grep -Fq "2.27" <<<"$output"
grep -Fq "Player Two" <<<"$output"
grep -Fq "93.8%" <<<"$output"
grep -Fq "2.33" <<<"$output"
grep -Fq "Player Three" <<<"$output"
grep -Fq "83.3%" <<<"$output"
grep -Fq "2.10" <<<"$output"

echo "PASS: strict C++17 compilation"
echo "PASS: player rows rendered"
echo "PASS: serve percentages verified"
echo "PASS: receive averages verified"
