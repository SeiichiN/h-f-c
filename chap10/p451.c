/*
 * p451.c
 * p451
 */

#include <stdio.h>

int main()
{
  char name[30];
  printf("名前を入力してください：");
  fgets(name, 30, stdin);
  printf("こんにちは、%s さん\n", name);
  return 0;
}

