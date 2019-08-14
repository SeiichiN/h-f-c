/*
 * kaikei.c
 * p169
 */

#include <stdio.h>
#include "totaller.h"

float total = 0.0;
short count = 0;
/* これは 6%。僕のエージェントの取り分より少ない・・・。 */
short tax_percent = 6;

int main()
{
  /* ねえ、僕はパル・キルマーとの映画に乗り気だったのに */
  float val;
  printf("品目の値段：");
  while (scanf("%f", &val) == 1) {
    printf("ここまでの合計：%.2f\n", add_with_tax(val));
    printf("品目の値段：");
  }
  printf("\n最終合計：%.2f\n", total);
  printf("品目数：%hi\n", count);

  return 0;
}

