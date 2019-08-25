CC=cc
CFLAGS=-g -Wall
SRC=newshound.c
OBJ=newshound.o

all: newshound

newshound: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o newshound

newshound.o: newshound.c
	$(CC) $(CFLAGS) -c newshound.c -o newshound.o

clear:
	rm -rf newshound $(OBJ)
 
