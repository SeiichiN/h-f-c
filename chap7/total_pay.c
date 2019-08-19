/*
 * total_pay.c
 * p343, p347
 */

#include <stdio.h>
#include <stdarg.h>

enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d)
{
    switch(d) {
    case MUDSLIDE:
        return 6.79;
    case FUZZY_NAVEL:
        return 5.31;
    case MONKEY_GLAND:
        return 4.82;
    case ZOMBIE:
        return 5.89;
    }
    return 0;
}

double total(int args, ...)
{
    double total = 0;
    int i;
    double thisPrice;

    va_list ap;
    va_start(ap, args);
    for (i = 0; i < args; i++) {
        thisPrice = price(va_arg(ap, int));
        total = total + thisPrice;
    }
    va_end(ap);
    return total;
}

int main()
{
    printf("価格は $%.2f です。\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("価格は $%.2f です。\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("価格は $%.2f です。\n", total(1, ZOMBIE));
}

        
