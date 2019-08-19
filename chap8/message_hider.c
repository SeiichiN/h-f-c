/*
 * message_hider.s
 * p186
 *
 * for compile
 * $ gcc -c encrypt.c -o encrypt.o
 * $ gcc message_hider.c enctypt.o -o message_hider
 */

#include <stdio.h>
#include "encrypt.h"

int main()
{
	char msg[80];
	while (fgets(msg, 80, stdin)) {
		encrypt(msg);
		printf("%s\n", msg);
	}

	return 0;
}
