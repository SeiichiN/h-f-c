# Makefile
# p362

bank_vault: bank_vault.c libhfsecirity.a
	gcc bank_vault.c -I . -L . -lhfsecirity -o bank_vault

encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o

checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o

libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o

