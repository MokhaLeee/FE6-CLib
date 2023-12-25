
# FE6-Clib

C header files for **fe6** port from [decomp](https://github.com/MokhaLeee/fe6)

## Usage (for WSL & ubuntu):

1. Suppose you have a **.c** file (named as *test.c*), put it to repo directory and then:

2. **.c** to **.o**
    ```sh
    make -f wizardry.mk test.o
    ```
    Now you get the obj file *test.o* and then:

3. **.o** to **.lyn.event**

    Get [lyn](https://github.com/StanHash/lyn) and then:

    ```bash
    ./lyn test.o reference/fe6.ref.o > test.lyn.event
    ```

## See also
