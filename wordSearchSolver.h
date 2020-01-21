#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string puzzleLines[50];
string wordsToFind[50];
int numberLines =0;
int numberWords =0;

#define EXIT_SUCCESS 0

void loadWordSearch(string file);