//These are the functions for the string_sorter class

#include "string_sorter.h"


//Constructor
string_sorter::string_sorter() {

	CurrentStrings = 0;
	cpptimediff = 0;
	ctimediff = 0;

}

//Destructor
string_sorter::~string_sorter() {

	for (int i = 0; i < CurrentStrings;i++) {
		strObjects[i] = "";
		delete [] strPtrs[i];
	}

}


void string_sorter::readInput() {
	//This function reads users input from the keyboard
	
	//count is used to keep track of how many strings the user
	//has entered
	int count = 0;

	//Runs the Clear function
	Clear();

	cout << "The max number of strings you can enter is: " << MAX_NUM_OF_STRINGS;
	cout << "." << endl;
	cout << "Start entering strings, one line equals one string." << endl;
	cout << "Enter CTRL+D (CTRL-Z for Windows) to finish." << endl << endl;

	//First string enter
	strPtrs[count] = new char[MAX_LEN_OF_STRING];
	cin.getline(strPtrs[count], MAX_LEN_OF_STRING);

	//While the user has not entered the combination to finish, and if
	//the user has not reached the max amount of strings, enter data
	while (!cin.eof() && count < MAX_NUM_OF_STRINGS) {
		
		count++;
		strPtrs[count] = new char[MAX_LEN_OF_STRING];
		cin.getline(strPtrs[count],MAX_LEN_OF_STRING);

		//If the maximum is reached, stop processing strings
		if (count == MAX_NUM_OF_STRINGS) {
			cout << endl << "You have entered the maximum amount of strings." << endl << endl;
			break;
		}
	}

	//Copies everything the user entered from the C string to the C++
	int i = 0;
	while (i < count) {
		strObjects[i].insert(0,strPtrs[i]);
		i++;
	}

	//Sets CurrentStrings
	CurrentStrings = count;
}

void string_sorter::readFile() {
	//This function is used to read strings from a file

	//Used to keep track of how many strings are in the list
	int count = 0;

	
	ifstream infile;
	string fname;

	//Runs the Clear function
	Clear();
	
	//User enters a filename and program attempts to open
	cout << "Enter a file name: ";
	cin >> fname;

	infile.open(fname.c_str());

	//If the file isn't valid, it'll prompt the user.
	//Else, continue processing
	if (!infile.good()) 
		cout << endl << "Invalid file." << endl << endl;
	else {

		strPtrs[count] = new char[MAX_LEN_OF_STRING];
		infile.getline(strPtrs[count], MAX_LEN_OF_STRING);

		//While it's not the end of file, keep processing strings
		while(!infile.eof()) {
			
			count++;
			//If the limit is reached, stop the loop
			if (count == MAX_NUM_OF_STRINGS) {
				cout << "Max number of strings reached." << endl << endl;
				break;
			}
			strPtrs[count] = new char[MAX_LEN_OF_STRING];
			infile.getline(strPtrs[count], MAX_LEN_OF_STRING);
		}

	//Copies input from C list to C++ list
	int i = 0;
	while (i < count) {
		strObjects[i].insert(0,strPtrs[i]);
		i++;
	}
	//Sets CurrentStrings
	CurrentStrings = count;
	cout << endl;
	cout << "File was read successfully." << endl << endl;
	}


}


void string_sorter::sortC(int left, int right) {
	//This is the recursive part of the quicksort
	//for the C list

	int pos;
	timeb time_ms;
	unsigned int timestart, timeend;

	//Starts the timer
	ftime(&time_ms);
	timestart = time_ms.millitm + (time_ms.time & 0xfffff) * 1000;

	//Recursive case for quicksort
	if (left < right) {

		pos = partC(left, right);
		sortC(left, pos - 1);
		sortC(pos + 1, right);
	}
	//Base case for quicksort
	else
		;

	//Ends the timer and records the difference
	ftime(&time_ms);
	timeend = time_ms.millitm + (time_ms.time & 0xfffff) * 1000;
	ctimediff = timeend - timestart;

}



int string_sorter::partC(int left, int right) {
	//This is the sorting part of the quicksort
	//for the C list

	char * pivot; // pointer to keep track of pivot
	char * temp;  // pointer used to swap pointers


	
	pivot = strPtrs[left];

	while (left < right) {
		while ((left < right) && (strcmp(strPtrs[right], pivot) >= 0))
			right--;

		if (left < right) {
			temp = strPtrs[left];
			strPtrs[left] = strPtrs[right];
			strPtrs[right] = temp;
			left++;
		}
		else
			;

	while ((left < right) && (strcmp(strPtrs[left], pivot) < 0))
		left++;

	if (left < right) {
		temp = strPtrs[right];
		strPtrs[right] = strPtrs[left];
		strPtrs[left] = temp;
		right--;
	}
	else
		;

	}

	strPtrs[left] = pivot;

	return left;



}



void string_sorter::sortCPP(int left, int right) {
	//This is the recursive part of the quicksort
	//for the C++ list

	int pos;
	timeb time_ms;
	unsigned int timestart, timeend;

	//Start timing
	ftime(&time_ms);
	timestart = time_ms.millitm + (time_ms.time & 0xfffff) * 1000;

	//Recursive case
	if (left < right) {

		pos = partCPP(left, right);
		sortCPP(left, pos - 1);
		sortCPP(pos + 1, right);

	}
	//Base case
	else
		;

	//End timing and calculate the difference
	ftime(&time_ms);
	timeend = time_ms.millitm + (time_ms.time & 0xfffff) * 1000;
	cpptimediff = timeend - timestart;
}


int string_sorter::partCPP(int left, int right) {
	//This is the sorting part of the quicksort
	//for the C++ list

	string pivot; //string to keep track of the pivot

	pivot = strObjects[left];

	while (left < right) {
		while ((left < right) && (strObjects[right].compare(pivot) >= 0))
			right--;

		if (left < right) {
			strObjects[left] = strObjects[right];
			left++;
		}
		else
			;

	while ((left < right) && (strObjects[left].compare(pivot) < 0))
		left++;

	if (left < right) {
		strObjects[right] = strObjects[left];
		right--;
	}
	else
		;

	}

	strObjects[left] = pivot;
	
	return left;
}


void string_sorter::display() {
	//This fuction displays the conclusion of the sorting
	//to the user

	int count = 0;

	cout << "----------------------------------------" << endl;
	cout << "------------C RESULTS-------------------" << endl;
	cout << "----------------------------------------" << endl;
	while (count <= CurrentStrings - 1) {
		cout << strPtrs[count] << endl;
		count++;
	}
	count = 0;
	cout << "----------------------------------------" << endl;
	cout << "----------CPP RESULTS-------------------" << endl;
	cout << "----------------------------------------" << endl;
	while (count <= CurrentStrings - 1) {
		cout << strObjects[count] << endl;
		count++;
	}
	cout << "----------------------------------------" << endl;
	cout << "-------------TIMES----------------------" << endl;
	cout << "----------------------------------------" << endl;
	cout << "CPP : " << setw(6) << cpptimediff << endl;
	cout << "  C : " << setw(6) << ctimediff << endl;
	cout << endl;
}

void string_sorter::Clear() {
	//This function will clear both lists if they are currently 
	//filled with previous data


	for (int i = 0; i < CurrentStrings;i++) {
		strPtrs[i] = "";
		strObjects[i] = "";
	}

	CurrentStrings = 0;
	cpptimediff = 0;
	ctimediff = 0;


}
