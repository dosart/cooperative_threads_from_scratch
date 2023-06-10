#ifndef _COMPARE_AND_SWAP_
#define _COMPARE_AND_SWAP_

/*
int char compare_and_swap(int *ptr, int expected, int new) {
    int actual = *ptr;
    if (actual == expected)
        *ptr = new;
    return actual;
}
*/
char compare_and_swap(int *ptr, int old, int new);

#endif