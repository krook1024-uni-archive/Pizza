#!/usr/bin/env bash

export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/share/pkgconfig"
mkdir -p build
cd build
cmake ..
make
cp pizza ../pizza
