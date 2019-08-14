/*
 * rec_struct.c
 * 再帰構造体
 * p271...
 */

#include <stdio.h>

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
    i->name = name;
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

int main()
{
    island amity = {"アミティ", "09:00", "17:00", NULL};
    island craggy = {"クラッギー", "09:00", "17:00", NULL};
    island isla_nublar = {"イスラヌブラル", "09:00", "17:00", NULL};
    island shutter = {"シャッター", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    /*
    island skull = {"スカル", "09:00", "17:00", NULL};

    isla_nublar.next = &skull;
    skull.next = &shutter;
    */
    
    display(&amity);
    
    return 0;
}
