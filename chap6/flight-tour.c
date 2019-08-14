/*
 * flight-tour.c
 * プールパズル
 * p287...
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
    char *this_name = strdup(name);
    printf("島の name に %li バイト確保した。\n", sizeof(this_name));
    
    island *i = malloc(sizeof(island));
    i->name = this_name;
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;

    printf("island構造体を %li バイト確保した。\n", sizeof(island));
    
    return i;
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);  /* i->name は、island 構造体とは別の空間に確保されている。 */
        free(i);
    }
}

int main()
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];

    for (; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }

    display(start);
    release(start);
    
    return 0;
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
 
