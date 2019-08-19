/*
 * pointer2.c
 * https://daeudaeu.com/programming/c-language/pointerofpointer/
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *data[] = {"dog", "cat", "bear"};



    printf("data[0] = 0x%x\n", data[0]);
    printf("data[0] = %s\n", data[0]);

    printf("data[1] = 0x%x\n", data[1]);
    printf("data[1] = %s\n", data[1]);

    printf("data[2] = 0x%x\n", data[2]);
    printf("data[2] = %s\n", data[2]);

    return 0;
}
