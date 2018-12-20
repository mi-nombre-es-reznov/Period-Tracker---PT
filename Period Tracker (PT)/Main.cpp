#include <iostream>	// For input/output
#include <fstream>	// For reading/writing from/to external text files
#include <string>	 // For string variables
#include "Greetings_intro.h"	// For Greetings_intro class
#include <time.h>	// For random number generator
using namespace std;	// Used to declare namespace as standard

// Call functions
string check_name();

// Global variables
Greetings_intro female_obj;	// Object of class Greetings_intro

int main()
{
	string first_name;	// Get female first name
	int loc_gs, loc_ge;	// Variables to hold randomized numbers for array search
	string greeting_starter[7] = {"Greetings ", "Good day ", "Salutations ", "Hello ", "Welcome ", "Hi ", "Howdy "};	// Array for beginning of greetings message
	string greeting_ending[7] = {", I hope all is well today.", ", I hope you are well today.", ", it is always a great day when you are around.", ", it is always a great day when you are around.", ", nice to have you back.", ", I'm glad you are here."}; // Array for ending of greetings message

	// Setup to initialize rand() function
	srand(time(NULL));

	// Used to get random numbers from generator and assign to variables
	loc_gs = rand() % 6;
	loc_ge = rand() % 6;
	//cout << "test num: " << test_num << endl << endl;

	first_name = check_name();

	female_obj.setFirstName(first_name);		// Assign name to class to parse - setName

	// Display message if user name is already in system and female is accessing
	cout << endl << endl << greeting_starter[loc_gs] << female_obj.getFirstName() << greeting_ending[loc_ge] << endl << endl;

	// To allow for user visability
	system("pause");
	return 0;
}

string check_name()
{
	string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;
	string in_fn, in_ln, in_weight, in_hf, in_hi, in_eth, in_sex, in_bc, in_dop, in_birth;
	ifstream file;
	ofstream copy;
	file.open("female_data.txt");
	copy.open("copy_data.txt");

	if (file.is_open())
	{
		cout << "File has successfully opened!" << endl;
		while (file >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
		{
			if (first_name == "user_first" && last_name == "user_last" && weight == "weight" && hfeet == "height_feet" && hinches == "height_inches"
				&& ethnicity == "ethnicity" && sex == "sexually_active" && bc_pills == "birth_control" && day_of_period == "typical_day_of_period"
				&& birthday == "Birthday")
			{
				cout << "What is your first name: ";
				cin >> in_fn;
				cout << "\nWhat is your last name: ";
				cin >> in_ln;
				cout << "\nHow much do you weigh in pounds (lbs): ";
				cin >> in_weight;
				cout << "\nWhat is your height (feet): ";
				cin >> in_hf;
				cout << "\nWhat is your height (inches): ";
				cin >> in_hi;
				cout << "\nWhat is your ethnicity: ";
				cin >> in_eth;
				cout << "\nAre you sexually active: ";
				cin >> in_sex;
				cout << "\nAre you on birth control: ";
				cin >> in_bc;
				cout << "\nWhat day does your period typically land on: ";
				cin >> in_dop;
				cout << "\nWhat is your DOB: ";
				cin >> in_birth;

				copy << in_fn << " " << in_ln << " " << in_weight << " " << in_hf << " " << in_hi << " " << in_eth << " " << in_sex <<
					" " << in_bc << " " << in_dop << " " << in_birth;
			}
			else
			{
				return "False";
			}
		}
		file.close();
		copy.close();
		if (!file.is_open() && !copy.is_open())
		{
			cout << "File has successfully closed!" << endl << endl;
		}

		ifstream copy2;
		ofstream file2;
		file2.open("female_data.txt");
		copy2.open("copy_data.txt");

		if (file2.is_open() && copy2.is_open())
		{
			while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
			{
				if (first_name != "user_first" && last_name != "user_last" && weight != "weight" && hfeet != "height_feet" && hinches != "height_inches"
					&& ethnicity != "ethnicity" && sex != "sexually_active" && bc_pills != "birth_control" && day_of_period != "typical_day_of_period"
					&& birthday != "Birthday")
				{
					file2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity <<
						" " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
				}
			}

			copy2.close();
			file2.close();
			if (!file2.is_open() && !copy2.is_open())
			{
				cout << "File has successfully closed!" << endl << endl;
			}
		}
	}
	else
	{
		cout << "File has failed to open! Creating file now." << endl;
		female_obj.create_init_file();
	}

	return first_name;
}