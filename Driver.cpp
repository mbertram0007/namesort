
#include "string_sorter.h"


//Global Constants
int EXIT = 5;

//Function delcarations
int getChoice();


int main() {
	//Local Variables
	int choice = 1;
	string_sorter List;

	cout << "Welcome to the String Sorter Program. Select from the choices below." << endl
		 << "Press " << EXIT << " to exit the program." << endl << endl;
	
	//Loop to allow user to enter selectons.
	do
	{
		cout << "Choose one of the following options:" << endl;
		cout << "       1. Input text from keyboard" << endl;
		cout << "       2. Input text from file" << endl;
		cout << "       3. Sort both C and C++ strings" << endl;
		cout << "       4. Show C and C++ strings/efficiencies" << endl;
		cout << "       5. Exit Program" << endl;
		cout << "Enter: ";
		cin.clear();
		choice = getChoice();
		cin.ignore();
		switch (choice)
		{
		   case 1: //Input from the keyboard
				List.readInput();
				cout << "Strings were read successfully." << endl << endl;
				break;
           case 2: //Input from file
			    cout << endl;
				List.readFile();
                break;
           case 3: //Sort using quicksort
				List.sortC(0, List.CurrentStrings - 1);
				List.sortCPP(0, List.CurrentStrings - 1);
				cout << endl << "Strings were sorted successfully." << endl << endl;
                break;
           case 4: // Output C and C++ efficiencies
				List.display();
                break;
		}
	} while (choice != EXIT);
	


	return 0;
}

int getChoice() {
	//This function does type and range checking for the user's 
	//command choice
	int num;

	cin >> num;

	while ((!cin.good()) || num < 1 || num > EXIT) {
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid type, must be an Integer and the numbers 1 - " << EXIT << "." << endl;
		cout << "Try again: ";
		cin >> num;
	}

	return num;
}
