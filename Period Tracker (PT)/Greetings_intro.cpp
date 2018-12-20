#include "Greetings_intro.h"
#include <iostream>
#include <fstream>
using namespace std;

Greetings_intro::Greetings_intro()
{
	cout << "Welcome user!!! It is an honor to be able to help you with something that is so close and personal to you.\n"
		"I just need you to answer a few basic questions in order to get started. Please answer as accurately as possible.\n" << endl;
}

void Greetings_intro::create_init_file()
{
	ofstream init;
	init.open("female_data.txt");

	if (init.is_open())
	{
		init << "user_first ";
		init << "user_last ";
		init << "weight ";
		init << "height_feet ";
		init << "height_inches ";
		init << "ethnicity ";
		init << "sexually_active ";
		init << "birth_control ";
		init << "typical_day_of_period ";
		init << "Birthday";
	}
	else
	{
		cout << "Initial data failed to be created!" << endl;
	}

	init.close();
	if (!init.is_open())
	{
		cout << "Initial data is closed!" << endl;
	}
	else
	{
		cout << "Initial data file has failed to close!" << endl;
	}
}

void Greetings_intro::setFirstName(string fn)
{
	 first = fn;
}

void Greetings_intro::setLastName(string ln)
{
	last = ln;
}

string Greetings_intro::getFirstName()
{
	return first;
}

string Greetings_intro::getLastName()
{
	return last;
}

Greetings_intro::~Greetings_intro()
{
	cout << "Your constructor has been destroyed!!!" << endl << endl;
}