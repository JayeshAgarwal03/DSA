#!/usr/bin/env bash
set -euo pipefail

# Build helper: compiles a single .cpp source using the repository root
# as an include path so #include <bits/stdc++.h> resolves.

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
INCLUDE_DIR="$ROOT_DIR"
CXX="${CXX:-g++}"
CXXFLAGS=( -std=gnu++17 -I"$INCLUDE_DIR" -O2 -Wall -Wextra )

if [ $# -lt 1 ]; then
  echo "Usage: $0 <source.cpp> [output_binary]"
  exit 1
fi

SRC="$1"
OUT="${2:-${SRC%.*}}"
mkdir -p "$(dirname "$OUT")"

echo "Compiling $SRC -> $OUT"
"$CXX" "${CXXFLAGS[@]}" -o "$OUT" "$SRC"
echo "Built $OUT"
