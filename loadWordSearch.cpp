#include "wordSearchPuzzle.h"
#include <fstream>
#include <string>

using std::string;

int numberLines = 0;
int numberWords = 0;

WordSearchPuzzle* loadWordSearch(string file, WordSearchPuzzle* puzzle) {

	std::ifstream fileToLoad;
	fileToLoad.open (file);
	string line;

	if (fileToLoad.is_open()) {

		bool finishedPuzzle = false;

		while (getline (fileToLoad, line))
		{

			if (line == "") {
				finishedPuzzle = true;
			}

			if (!finishedPuzzle) {

				puzzle->addLines(line, numberLines);
				++numberLines;

			} else if (finishedPuzzle && line !="") {
				puzzle->addWords(line, numberWords);
				++numberWords;
			} 
		}
	}

	fileToLoad.close();

	return puzzle;
}