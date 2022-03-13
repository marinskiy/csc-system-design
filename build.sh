#!/bin/bash

mkdir -p .artifacts
cmake -S . -B .artifacts
make -C .artifacts
mv .artifacts/src/shell ./
mv .artifacts/test/shell_tests ./
