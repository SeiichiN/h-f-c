/*
 * p256.c
 * p256
 */

#include <stdio.h>

typedef enum {
    COUNT, POUNDS, PINTS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order)
{
    printf("この注文に含まれるものは");

    if (order.units == PINTS)
        printf("%2.2f パイントの %s です\n",
               order.amount.volume, order.name);
    else if (order.units == POUNDS)
        printf("%2.2f ポンドの %s です\n",
               order.amount.weight, order.name);
    else
        printf("%i 個の %s です\n",
               order.amount.count, order.name);
}

int main()
{
    fruit_order apples = {"リンゴ", "イギリス", .amount.count=144, COUNT};

    fruit_order strawberries = {"いちご", "スペイン", .amount.weight=17.6, POUNDS};
    
    fruit_order oj = {"オレンジジュース", "アメリカ", .amount.volume=10.5, PINTS};

    display(apples);
    display(strawberries);
    display(oj);

    return 0;
}
