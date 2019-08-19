/*
 * str_arr.c
 */

#include <stdio.h>

void disp_arr(const void* a)
{
    char* str_a = (char*)a;
    printf("%s\n", str_a);
}

int main()
{
    char *names[] = {
        "James",
        "Amargam",
        "Thomas",
        "Jacson",
        "Robert",
        "Wize"
    };

    int i = 0;
    int length = sizeof(names) / sizeof(names[0]);
    
    for (i=0; i < length; i++) {
        disp_arr(names[i]);
    }

    return 0;
}
