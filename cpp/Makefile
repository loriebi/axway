#		Makefile for shuffling

CC = g++
CFLAGS = -W -Wall -ansi -pedantic
LFLAGS =
EXEC=$(BIN)shuffle

BIN =bin/
OBJ =obj/
INCLUDE =include/
LIB =lib/
SRC =src/


H=

clean:
	rm -rf $(OBJ)*.o $(BIN)*


all: $(EXEC)
$(BIN)shuffle: $(OBJ)shuffling.o $(OBJ)shuffle.o
	$(CC) $(LFLAGS) -o $@ $^
$(OBJ)shuffling.o: $(SRC)shuffling.cpp
	$(CC) $(LFLAGS) -o $@ -c $< $(CFLAGS)
$(OBJ)shuffle.o: $(SRC)shuffle.cpp $(INCLUDE)shuffling.h
	$(CC) $(LFLAGS) -o $@ -c $< $(CFLAGS)
