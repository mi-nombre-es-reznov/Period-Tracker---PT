#include <iostream>	// For input/output
#include <fstream>	// For reading/writing from/to external text files
#include <string>	 // For string variables
#include "Greetings_intro.h"	// For Greetings_intro class
#include <time.h>	// For random number generator
using namespace std;	// Used to declare namespace as standard

void check_name();

int main()
{
	string first_name;	// Get female first name
	int loc_gs, loc_ge;	// Variables to hold randomized numbers for array search
	Greetings_intro female_obj;	// Object of class Greetings_intro
	string greeting_starter[7] = {"Greetings ", "Good day ", "Salutations ", "Hello ", "Welcome ", "Hi ", "Howdy "};	// Array for beginning of greetings message
	string greeting_ending[7] = {", I hope all is well today.", ", I hope you are well today.", ", it is always a great day when you are around.", ", it is always a great day when you are around.", ", nice to have you back.", ", I'm glad you are here."}; // Array for ending of greetings message

	// Setup to initialize rand() function
	srand(time(NULL));

	// Used to get random numbers from generator and assign to variables
	loc_gs = rand() % 6;
	loc_ge = rand() % 6;
	//cout << "test num: " << test_num << endl << endl;

	check_name();
	// Get user name if it's their first time using the software
	cout << "Please enter your FIRST name ONLY: ";
	cin >> first_name;
	female_obj.setFirstName(first_name);		// Assign name to class to parse - setName

	// Display message if user name is already in system and female is accessing
	cout << endl << endl << greeting_starter[loc_gs] << female_obj.getFirstName() << greeting_ending[loc_ge] << endl << endl;

	// To allow for user visability
	system("pause");
	return 0;
}

void check_name()
{
	ifstream file;
	file.open("female_data.txt");

	if (file.is_open())
	{
		cout << "File has successfully opened!" << endl;
	}
	else
	{
		cout << "File has failed to open! Creating file now." << endl;
		ofstream new_user;
		new_user.open("female_data.txt");

		if (new_user.is_open())
		{
			cout << "Account being created!\nPlease answer all questions to the best of your knowledge." << endl << endl;
			new_user << "user";
 		}
		else
		{
			cout << "New account failed to be made. Please check for errors in your code!" << endl;
		}
	}
}