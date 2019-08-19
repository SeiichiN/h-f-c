/*
 * automail.c
 * p334
 */

#include <stdio.h>

enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };
typedef struct {
    char *name;
    enum response_type type;
} response;

void dump( response r )
{
    printf("%s さんへ。\n", r.name);
    puts("残念ながら、前回のデートの結果、");
    puts("再度お会いすることはないとの連絡を受けました。");
}

void second_chance(response r)
{
    printf("%s さんへ。\n", r.name);
    puts("よいお知らせです。前回のデートの結果、");
    puts("もう一度お会いしたいとの連絡を受けました。至急ご連絡ください。");
}

void marriage(response r)
{
    printf("%s さんへ。\n", r.name);
    puts("おめでとうございます。前回のデートの結果、");
    puts("結婚を申し込みたいとの連絡を受けました。");
}

int main()
{
    response r[] = {
        {"マイク", DUMP}, {"ルイス", SECOND_CHANCE},
        {"マット", SECOND_CHANCE}, {"ウィリアム", MARRIAGE}
    };

    int i;
    for (i = 0; i < 4; i++) {
        switch( r[i].type ) {
        case DUMP :
            dump( r[i] );
            break;
        case SECOND_CHANCE :
            second_chance( r[i] );
            break;
        default:
            marriage( r[i] );
        }
    }
    return 0;
}

