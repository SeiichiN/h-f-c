/*
 * margarita_p250.c
 * p250
 */

#include <stdio.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

void recipe1()
{
    margarita m = {2.0, 1.0, {2.0}};

    printf("%2.1f 単位のテキーラ\n%2.1f 単位のコアントロー\n%2.1f 単位のジュース\n",
           m.tequila, m.cointreau, m.citrus.lemon);
}

void recipe2()
{
    margarita m = {2.0, 1.0, {0.5}};

    printf("%2.1f 単位のテキーラ\n%2.1f 単位のコアントロー\n%2.1f 単位のジュース\n",
           m.tequila, m.cointreau, m.citrus.lemon);
}

void recipe3()
{
    margarita m = {2.0, 1.0, {.lime_pieces=1}};

    printf("%2.1f 単位のテキーラ\n%2.1f 単位のコアントロー\n%i 切れのライム\n",
           m.tequila, m.cointreau, m.citrus.lime_pieces);
}
    

   

int main()
{
    recipe1(); printf("\n");
    recipe2(); printf("\n");
    recipe3(); printf("\n");

    return 0;
}

