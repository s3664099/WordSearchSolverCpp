#include <iostream>
#include "wordSearchPuzzle.h"

void WordSearchPuzzle::addLines(string line, int position) {

	linesOfPuzzle[position] = line;
	numberLines++;
}

void WordSearchPuzzle::addWords (string word, int position) {

	wordsToFind[position] = word;
	numberWords++;
}


string* WordSearchPuzzle::getLines() {
	return linesOfPuzzle;
}

string* WordSearchPuzzle::getWords() {
	return wordsToFind;

}

int WordSearchPuzzle::getNumberWords() {
	return numberWords;
}

int WordSearchPuzzle::getNumberLines() {
	return numberLines;
}

string WordSearchPuzzle::getWord(int position) {
	return wordsToFind[position];
}


void WordSearchPuzzle::printPuzzle() {

	for (int i=0;i<numberLines;++i) {
		std::cout<<linesOfPuzzle[i]<<std::endl;
	}

}