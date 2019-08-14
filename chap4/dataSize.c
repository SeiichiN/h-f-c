/*
 * dataSize.c
 * p167
 */

#include <stdio.h>
#include <limits.h>  /* int, char, ... 整数型 */
#include <float.h>   /* float, double ...浮動小数点型 */

int main()
{
  printf("DBL_MAX の値は %f\n", DBL_MAX);
  printf("DBL_MIN の値は %.50f\n", DBL_MIN);
  printf("double は %lu バイトを占めます\n", sizeof(double));

  printf("FLT_MAX の値は %f\n", FLT_MAX);
  printf("FLT_MIN の値は %.50f\n", FLT_MIN);
  printf("float は %lu バイトを占めます\n", sizeof(float));
  
  return 0;
}
