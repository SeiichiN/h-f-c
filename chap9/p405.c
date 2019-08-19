/*
 * p405.c
 * p405 & p407
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    /* execl("/bin/cat", "", "reports.log", NULL); */

    char *my_env[] = {"JUICE=桃とリンゴ", NULL};
    
    /* execl("/bin/echo", "/bin/echo", path, NULL); */
    
    execle("diner_info", "diner_info", "4", NULL, my_env);

    puts("diner_infoコードは壊れているにちがいありません");
    
    return 0;
}
