CC=cc
CFLAGS=-g -Wall
SRC=newshound2.c
OBJ=newshound2.o

all: newshound2

newshound: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o newshound2

newshound.o: newshound2.c
	$(CC) $(CFLAGS) -c newshound2.c -o newshound2.o

clear:
	rm -rf newshound2 $(OBJ)
 
