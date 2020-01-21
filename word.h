#include <string>

using std::string;

class Word {
	private:
		string word;
		int xCoord=-1;
		int yCoord=-1;
		string direction="";
	public:
		Word(string word);
		~Word();
		void foundWord(int xCoord, int yCoord, string direction);
		int checkFound();
		string printWord();
};
