#include<string>
using std::string;

class WordSearchPuzzle {
	private:
		string linesOfPuzzle[50];
		string wordsToFind[50];
		int numberLines = 0;
		int numberWords = 0;
	public:
		~WordSearchPuzzle();
		void addLines(string line, int position);
		void addWords (string word, int position);
		string* getLines();
		string* getWords();
		void printPuzzle();
		int getNumberWords();
		int getNumberLines();
		string getWord(int position);
};
