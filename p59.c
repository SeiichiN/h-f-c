/*
 * p59.c
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char s[] = "How big is it?";
  char *t = s;

  int ss = sizeof(s);
  int tt = sizeof(t);

  printf("s-> %li\n", sizeof(s));
  printf("t-> %li\n", sizeof(t));

}
