/*
 * hfcal.c
 * p366
 */

#include <stdio.h>
#include <hfcal.h>

void display_calories( float weight, float distance, float coeff)
{
    printf("体重：%3.2f ポンド\n", weight);
    printf("距離：%3.2f マイル\n", distance);
    printf("消費カロリー：%4.2f カロリー\n", coeff *weight * distance);
}
