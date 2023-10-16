#!/bin/bash
wget -p /tmp https://github.com/KHALID185/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libdynamic.so
export LD_PRELOAD=/tmp/libgiga.so
