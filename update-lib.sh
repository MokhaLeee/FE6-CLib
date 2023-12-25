#!/bin/bash
DECOMP_DIR=~/fe6
BASE_NAME=fe6

# update header
rm -rf include
cp -r $DECOMP_DIR/include/ ./

# update refs
cp $DECOMP_DIR/$BASE_NAME.elf utility/
cd utility && make -j
rm $BASE_NAME.elf

cd ..
rm -rf reference/
mkdir reference
mv utility/$BASE_NAME.* reference/
make -f wizardry.mk reference/$BASE_NAME.ref.o
