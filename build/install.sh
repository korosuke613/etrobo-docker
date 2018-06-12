#!/bin/sh

cd src
mkdir build
cd build
cmake ..
cmake --build .
ctest -VV