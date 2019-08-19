/*
 * pointer.c
 * https://daeudaeu.com/programming/c-language/pointerofpointer/
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **dptr;
    int *ptr;
    int data;

    data = 123;

    ptr = &data;
    dptr = &ptr;

    printf("prt = 0x%x\n", ptr);
    printf("*ptr = %d\n", *ptr);

    printf("dptr = 0x%x\n", dptr);   /* *dptrのアドレス */
    printf("*dptr = 0x%x\n", *dptr); /* **dptrのアドレス = *ptrのアドレス */
    printf("**dptr = %d\n", **dptr);

    return 0;
}
