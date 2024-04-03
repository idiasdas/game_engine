#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Debug -B ../build/debug -S ..

cd ../build/debug

make
