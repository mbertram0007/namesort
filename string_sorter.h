//This is the string sorter class.


//Library List
#include <cstring>
#include <string>
#include <ctime>
#include <iostream>
#include <sys/timeb.h>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

//Constants

//Max amount of strings program allows
const int MAX_NUM_OF_STRINGS = 1000; 

//How long a string can be
const int MAX_LEN_OF_STRING = 80;

class string_sorter {

private:
	char *strPtrs[MAX_NUM_OF_STRINGS];
	string strObjects[MAX_NUM_OF_STRINGS];
	int partCPP(int, int);
	int partC(int, int);
	unsigned int cpptimediff;
	unsigned int ctimediff;
	void Clear();
public:
	int CurrentStrings;
	string_sorter();
	~string_sorter();
	void readInput();
	void readFile();
	void sortCPP(int, int);
	void sortC(int, int);
	void display();
};
