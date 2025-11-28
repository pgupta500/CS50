#include <stdio.h>

// Dereferencing means accessing the value stored at the memory location a pointer refers to.
// p stores the address of x but when we dereference p using *p, we get the value of x.
// If u ask "so why int *p = &x; and not int p = &x;", it's because p is supposed to store a memory address, not an ordinary integer.

// malloc() is used to assign memory
// Three golden rules:
// 1. Every block of memory that you malloc() must subsequently be free()d.
// 2. Only memory that you malloc() should be free()d.
// 3. Do not free() a block of memory more than once.

int main(void){
    int x = 4;
    int *p = &x;
    printf("%i\n", *p);
    return 0;
}

