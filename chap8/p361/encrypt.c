/*
 * encrypt.c
 * p186
 */

#include "encrypt.h"

void encrypt(char *message)
{
  while (*message) {
    *message = *message ^ 31;
    message++;
  }
}
