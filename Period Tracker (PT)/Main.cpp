#include <iostream>	// For input/output
#include <fstream>	// For reading/writing from/to external text files
#include <string>	 // For string variables
#include "Greetings_intro.h"	// For Greetings_intro class
using namespace std;	// Used to declare namespace as standard

// Call functions
string check_name();
void get_base_data();
void getfirstName();

// Global variables
Greetings_intro female_obj;	// Object of class Greetings_intro

int main()
{
	string first_name;	// Get female first name
	int loc_gs, loc_ge;	// Variables to hold randomized numbers for array search
	string greeting_starter[7] = {"Greetings ", "Good day ", "Salutations ", "Hello ", "Welcome ", "Hi ", "Howdy "};	// Array for beginning of greetings message
	string greeting_ending[7] = {", I hope all is well today.", ", I hope you are well today.", ", it is always a great day when you are around.", ", it is always a great day when you are around.", ", nice to have you back.", ", I'm glad you are here."}; // Array for ending of greetings message

	// Used to get random numbers from generator and assign to variables
	loc_gs = female_obj.random_number(6);
	loc_ge = female_obj.random_number(6);
	//cout << "test num: " << test_num << endl << endl;

	// Used to pull data from file and place in class's object variable (w/o, the system overrides the core data every call)
	getfirstName();
	cout << female_obj.getFirstName() << endl << endl;

	// If the value of the first name is "user_first" or and empty string
	if (female_obj.getFirstName() == "user_first" || female_obj.getFirstName() == "")
	{
		female_obj.intro_message();					// Intro message if parameter from above is met
		female_obj.create_init_file();				// Call to a class function to create a file and ask for user core data
		first_name = check_name();					// Call to check for name and assign it to the first name variable.
		female_obj.setFirstName(first_name);		// Assign name to class to parse - setName
	}

	system("CLS");

	// Display message if user name is already in system and female is accessing
	cout << greeting_starter[loc_gs] << female_obj.getFirstName() << greeting_ending[loc_ge] << endl << endl;

	// To allow for user visability
	system("pause");
	return 0;
}

string check_name()
{
	string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;
	ifstream file;
	ofstream copy;
	file.open("female_data.txt");
	copy.open("copy_data.txt");

	if (file.is_open())
	{
		while (file >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
		{
			if (first_name == "user_first" && last_name == "user_last" && weight == "weight" && hfeet == "height_feet" && hinches == "height_inches"
				&& ethnicity == "ethnicity" && sex == "sexually_active" && bc_pills == "birth_control" && day_of_period == "typical_day_of_period"
				&& birthday == "Birthday")
			{
				get_base_data();
			}
			else
			{
				break;
			}
		}

		copy << female_obj.getFirstName() << " " << female_obj.getLastName() << " " << female_obj.getWeight() << " " << female_obj.getHeightFeet() << " " << female_obj.getHeightInches() << " " << female_obj.getEthnicity() << " " << female_obj.getSex() <<
			" " << female_obj.getBirthControl() << " " << female_obj.getPeriodDay() << " " << female_obj.getBirthday();

		file.close();
		copy.close();

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
				else
				{
					break;
				}
			}

			copy2.close();
			file2.close();
		}
	}
	else
	{
		cout << "File has failed to open! Creating file now." << endl;
		system("pause");
		system("CLS");
	}

	return female_obj.getFirstName();
}

void get_base_data()
{
	string in_fn, in_ln, in_weight, in_hf, in_hi, in_eth, in_sex, in_bc, in_dop, in_birth;

	cout << "What is your first name: ";
	cin >> in_fn;
	female_obj.setFirstName(in_fn);
	cout << "\nWhat is your last name: ";
	cin >> in_ln;
	female_obj.setLastName(in_ln);
	cout << "\nHow much do you weigh in pounds (lbs): ";
	cin >> in_weight;
	female_obj.setWeight(in_weight);
	cout << "\nWhat is your height (feet): ";
	cin >> in_hf;
	female_obj.setHeightFeet(in_hf);
	cout << "\nWhat is your height (inches): ";
	cin >> in_hi;
	female_obj.setHeightInches(in_hi);
	cout << "\nWhat is your ethnicity: ";
	cin >> in_eth;
	female_obj.setEthnicity(in_eth);
	cout << "\nAre you sexually active: ";
	cin >> in_sex;
	female_obj.setSex(in_sex);
	cout << "\nAre you on birth control: ";
	cin >> in_bc;
	female_obj.setBirthControl(in_bc);
	cout << "\nWhat day does your period typically land on: ";
	cin >> in_dop;
	female_obj.setPeriodDay(in_dop);
	cout << "\nWhat is your DOB: ";
	cin >> in_birth;
	female_obj.setBirthday(in_birth);
}

void getfirstName()
{
	string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;
	ifstream file;
	file.open("female_data.txt");

	if (file.is_open())
	{
		while (file >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
		{
			female_obj.setFirstName(first_name);
			female_obj.setLastName(last_name);
			female_obj.setWeight(weight);
			female_obj.setHeightFeet(hfeet);
			female_obj.setHeightInches(hinches);
			female_obj.setEthnicity(ethnicity);
			female_obj.setSex(sex);
			female_obj.setBirthControl(bc_pills);
			female_obj.setPeriodDay(day_of_period);
			female_obj.setBirthday(birthday);
		}
	}
	else
	{
		cout << "File failed to open!" << endl;
	}

	file.close();
}