
.default: all

CC = g++
CFLAGS = -Wall -Werror
OBJ = -g -O -c
SOURCES = loadWordSearch.o locateWords.o word.o wordSearchPuzzle.o wordSearchSolver.o

all: wordSearchSolver

clean:
	rm -rf wordSearchSolver *.o *.dSYM

wordSearchSolver: ${SOURCES}
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -std=c++14 $(CFLAGS) $(OBJ) $^