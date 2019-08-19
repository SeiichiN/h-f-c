/*
 * str_count.c
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char *name = "ロレッタ・バーンスワース";

    printf("name: %s\n", name);
    printf("sizeof(name): %li バイト\n", sizeof(name));   /* 8バイト */
    printf("strlen(name): %li バイト\n", strlen(name));   /* 36バイト */
}
