#!/bin/bash

mkdir -p .artifacts
cmake -S . -B .artifacts -DBoost_LIBRARY_DIRS="/home/runner/work/csc-system-design/csc-system-design/boost/boost/lib"
make -C .artifacts
mv .artifacts/src/shell ./
mv .artifacts/test/shell_tests ./
