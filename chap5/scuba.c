/*
 * scuba.c
 * p233
 */

#include <stdio.h>

typedef struct {
    float tank_capacity;
    int tank_psi;
    const char *suit_material;
} equipment;

typedef struct scuba {
    const char *name;
    equipment kit;
} diver;

void badge( diver d )
{
    printf("名前：%s タンク：%2.2f(%i) スーツ：%s\n",
           d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);
}

int main()
{
    diver randy = {"ランディ", {5.5, 3500, "ネオプレン"}};
    badge(randy);

    return 0;
}
