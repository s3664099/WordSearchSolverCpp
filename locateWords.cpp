#include "word.h"
#include "wordSearchPuzzle.h"
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

std::vector<Word> wordList;

Word traversePuzzle (string word, WordSearchPuzzle* puzzle);
int findMatch(string word, string row);
Word diagonalSearch(Word word, string* lines, string wordToFind, bool leftRight, 
	string direction, int numberLines);

void searchPuzzle(WordSearchPuzzle* puzzle) {

	puzzle->printPuzzle();

	for (int i=0;i<puzzle->getNumberWords();i++) {

		Word word = traversePuzzle(puzzle->getWord(i), puzzle);

		wordList.push_back(word);
	}

	int listSize =wordList.size();

	for (int i=0; i<listSize; ++i) {
		cout<<wordList.at(i).printWord()<<endl;
	}

}

//This function traverses the puzzle looking for the word. It starts by checking each
//of the rows, and then checks each of the columns. If the word isn't found, it then
//check each of the diagonals, left and right.
//As soon as the word is found, the result is returned and the loop is exited.
Word traversePuzzle (string wordToFind, WordSearchPuzzle* puzzle) {

	int numberOfLines = puzzle->getNumberLines();
	int numberLines = numberOfLines;
	int result = -1;
	string* lines = puzzle->getLines();
	string direction = "Across";
	string stringToSearch = "";
	int stringIteration = 0;
	Word word(wordToFind);

	//Taverses the puzzle, and continues as long as the word
	//hasn't been found
	while (result == -1) {

		while (result == -1 && stringIteration<numberLines) {

			//Checks across and down by grabbing the row or column to be checked
			//And places it into a temporary string
			if (direction == "Across") {

				stringToSearch = *(lines+stringIteration);
			} else if (direction == "Down") {

				for (int j=0; j<numberOfLines; j++) {

					string tempString = *(lines+j);

					stringToSearch+=tempString.at(stringIteration);
				}
			}

			//The method that compares the strings is then called and the result
			//if returned. A -1 indicates that no result has been returned. Any
			//other number indicates that it has. If a result has been returned
			//the results are stored in an object and returned to the main program
			result = findMatch(wordToFind, stringToSearch);

			if (result != -1) {

				if (direction == "Down") {

					word.foundWord(stringIteration+1, result+1, direction);
					return word;

				} else {

					word.foundWord(result+1, stringIteration+1, direction);
					return word;
				}
			}

			stringToSearch="";
			stringIteration++;
			
		}

		//Checks to see whether we have reached the end of the rows/columms.
		//if it has, the word hasn't been found and then moves onto the next
		//iteration
		if (direction == "Across") {

			stringIteration = 0;
			numberLines = lines->length();
			direction = "Down";

		} else if (direction == "Down") {

			direction = "Diagonal Right";
			word = diagonalSearch(word, lines, wordToFind, false, direction, numberOfLines);

			if (word.checkFound() != -1) {
				return word;
			}

		} else if (direction == "Diagonal Right") {

			direction = "Diagonal Left";
			word = diagonalSearch(word, lines, wordToFind, true, direction, numberOfLines);

			if (word.checkFound()!= -1) {
				return word;
			}

		} else {
			result = 0;
		}

	}

	return word;
}

//This checks the right shifting diagonals.
Word diagonalSearch(Word word, string* lines, string wordToFind, bool leftRight, 
	string direction, int numberOfLines) {

	int diagonalRow = 0;
	int diagonalColumn = 0;
	int endPoint = lines->length();
	int lineLength = lines->length();
	int wordLength = wordToFind.length();
	bool finishedSearch = false;

	if(!leftRight) {
		diagonalRow = numberOfLines;
	}

	while (!finishedSearch) {

		int i = diagonalRow;
		int j = diagonalColumn;
		string stringToCheck = "";
		bool reachedEnd = false;
		bool tooSmall = false;

		//This is designed to make the algorithm more efficient. The idea is
		//that if the length of the word is too small, then there is no point
		//constructing it, so it will be skipped.
		if (leftRight) {

			if (diagonalRow+wordLength>numberOfLines || diagonalColumn-wordLength+1<0) {
				tooSmall = true;
			}
		} else {

			if (diagonalRow+wordLength>numberOfLines || diagonalColumn+wordLength>endPoint) {
				tooSmall = true;
			}
		}

		//creates the string for the diagonal columns the bottom left corner
		//to the top right corner and the top left corner to the bottom right
		//corner This part of the function builds the string
		//from the letters in the quiz.

		while (!reachedEnd && !tooSmall) {

			string tempString = *(lines+i);

			stringToCheck+=tempString.at(j);

			//These two if statements iterate through the array of strings
			if (leftRight) {
				i++;

				if (j>-1) {
					j--;
				}

				if (i>=numberOfLines || j<0) {
					reachedEnd = true;
				}
			} else {
				i++;

				if (j<lineLength) {
					j++;
				}

				if (i>numberOfLines-1 || j>=lineLength) {
					reachedEnd = true;
				}
			}
		}

		//checks to see if there is a match, and if there is
		//updates the object with the word location and returns it
		int wordLocation = findMatch(wordToFind,stringToCheck);

		if (wordLocation != -1) {

			if (!leftRight) {
				word.foundWord(diagonalColumn+wordLocation+1, diagonalRow+wordLocation+1, direction);
			} else {
				word.foundWord(diagonalColumn+wordLocation+1, diagonalRow+wordLocation+1, direction);
			}

			return word;
		}

		//This part moves through to the next diagonal to then construct the string

		if (leftRight) {

			diagonalColumn++;

			if (diagonalColumn == endPoint) {
				diagonalColumn = endPoint-1;
				diagonalRow++;
				
			} else {
				
				diagonalRow = 0;
			}
		} else {
			diagonalRow --;

			if (diagonalRow == -1) {
				diagonalRow = 0;
				diagonalColumn ++;
			} else {
				diagonalColumn = 0;
			}
		}

		i = diagonalRow;
		j = diagonalColumn;
		reachedEnd = false;

		if (!leftRight && diagonalColumn == endPoint) {
			finishedSearch = true;
		} else if (leftRight && diagonalRow == endPoint) {
			finishedSearch = true;
		}
	}

	return word;

}

/*
		string *lines = puzzle->getLines();

		for (int i=0;i<puzzle->getNumberLines(); i++)
			cout<<*(lines+i)<<" "<<i<<endl;
*/

int findMatch(string word, string row) {
				
	//We need to know the length of the row
	int stringLength = row.length();
	int patternLength = word.length();
			
	int lengthToCheck = stringLength-patternLength+1;
				
	for (int i=0;i<lengthToCheck; i++) {
			
		int j=0;
			
		//Gets the character at the specific point in the sentance
		char a = word.at(j);
		char b = row.at(i+j);
						
		while (j<patternLength && a==b) {
											
			//if a match with the characters is found, it continues to search
			j=j+1;
				
			//once a match is found, it returns the result
			if (j == patternLength)
				return i;
				
			a = word.at(j);
			b = row.at(i+j);

		}			
	}
	
	return -1;
}

