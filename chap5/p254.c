/*
 * p254.c
 * p254
 */

#include <stdio.h>

typedef union {
    float weight;
    int count;
} cupcake;

int main()
{
    cupcake order = {2};
    printf("カップケーキの星：%i\n", order.count);
    return 0;
}
