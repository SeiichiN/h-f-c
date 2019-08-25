CC=cc
CFLAGS=-g -Wall
SRC=news_opener.c
OBJ=news_opener.o
TARGET=news_opener

all: $(TARGET)

newshound: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

newshound.o: newshound2.c
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clear:
	rm -rf $(TARGET) $(OBJ)
 
