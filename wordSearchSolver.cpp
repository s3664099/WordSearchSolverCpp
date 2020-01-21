#include <string>
#include "wordSearchPuzzle.h"

using std::string;

#define EXIT_SUCCESS 0

WordSearchPuzzle* puzzle = new WordSearchPuzzle();
WordSearchPuzzle* loadWordSearch(string file, WordSearchPuzzle* puzzle);
void searchPuzzle(WordSearchPuzzle* puzzle);

int main (int argc, char** argv) {

	string file = argv[1];
	
	puzzle = loadWordSearch(file, puzzle);

	searchPuzzle(puzzle);

	return EXIT_SUCCESS;
}

