/*
 * test-flight.c
 * 再帰構造体
 * p281...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start)
{
    island *i = start;

    for (; i != NULL; i = i->next) {
        printf("名前：%s 営業時間：%s-%s\n", i->name, i->opens, i->closes);
    }
}

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}


int main()
{
    char name[80];
    fgets(name, 80, stdin);
    island *p_island0 = create(name);

    fgets(name, 80, stdin);
    island *p_island1 = create(name);
    p_island0->next = p_island1;

    display(p_island0);
}


 /*
int main()
{
    island *amity = create("アミティ");
    island *craggy = create("クラッギー");
    island *isla_nublar = create("イスラヌブラル");
    island *shutter = create("シャッター");

    amity->next = craggy;
    craggy->next = isla_nublar;
    isla_nublar->next = shutter;


    island *skull = create("スカル");

    isla_nublar->next = skull;
    skull->next = shutter;

    
    display(amity);
    
    return 0;
}
*/
 
