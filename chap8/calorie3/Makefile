# Makefile
# p367

elliptical: elliptical.o hfcal.a
	gcc hfcal.o elliptical.o -I ./includes -L ./libs -o elliptical

hfcal.o: hfcal.c
	gcc -c hfcal.c -I ./includes -o hfcal.o

elliptical.o: elliptical.c
	gcc -c elliptical.c -I ./includes  -o elliptical.o

hfcal.a: hfcal.o
	ar -rcs ./libs/hfcal.a hfcal.o
