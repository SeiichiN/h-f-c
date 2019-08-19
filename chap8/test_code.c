/*
 * test_code.c
 * p353
 *
 * for compile
 * $ gcc -c encrype.c -o encrypt.o
 * $ gcc -c checksum.c -o checksum.o
 * $ gcc test_code.c encrypt.o checksum.o -o test_code
 */

#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main()
{
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("'%s' に暗号化しました\n", s);
    printf("チェックサムは %i です\n", checksum(s));
    encrypt(s);
    printf("'%s' に復号化しました\n", s);
    printf("チェックサムは %i です\n", checksum(s));

    return 0;
}
