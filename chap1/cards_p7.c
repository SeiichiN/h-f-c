/*
 * cards.c
 * p7
 * コードマグネット
 * カードの値を評価するプログラム
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
  char card_name[3];
  puts("カード名を入力してください");
  scanf("%2s", card_name);
  int val = 0;
  if (card_name[0] == 'K') {
	val = 10;
  } else if (card_name[0] == 'Q') {
	val = 10;
  } else if (card_name[0] == 'J') {
	val = 10;
  } else if (card_name[0] == 'A') {
	val = 11;
  } else {
	val = atoi(card_name);
  }
  printf("カードの値：%i\n", val);

  return 0;
}
