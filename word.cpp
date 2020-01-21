#include "word.h"
#include <string>
#include <iostream>


Word::Word(string word) {

	this->word = word;
}

Word::~Word() {}

void Word::foundWord(int xCoord, int yCoord, string direction) {
		
		this->xCoord = xCoord;
		this->yCoord = yCoord;
		this->direction = direction;
	}

int Word::checkFound() {
	return xCoord;
}

string Word::printWord() {

	string wordLocation = "";

	if (direction == "") {
		wordLocation = word+" not found";
	} else {
		wordLocation = word+" x:"+std::to_string(xCoord)+" y:"+std::to_string(yCoord)+" direction: "+direction;
	}

	return wordLocation;

}