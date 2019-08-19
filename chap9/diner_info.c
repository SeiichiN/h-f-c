/*
 * diner_info.c
 * p407
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("食堂：%s\n", argv[1]);
    printf("ジュース：%s\n", getenv("JUICE"));
    return 0;
}
