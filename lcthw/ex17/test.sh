#!/bin/bash
set -e

echo "Creating database ..."
./ex17-4 data.dat c
echo ""

echo "Saving zed, frank, joe to database ..."
./ex17-4 data.dat s 1 1 zyf zyf1116
./ex17-4 data.dat s 2 2 dxj dxjzyf
./ex17-4 data.dat s 3 1 joe joe@zedshaw.com
echo ""

echo "Printing all records ..."
./ex17 db.dat l
