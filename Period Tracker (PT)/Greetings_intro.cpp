#include "Greetings_intro.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

Greetings_intro::Greetings_intro()
{

}

void Greetings_intro::intro_message()
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
}

void Greetings_intro::setFirstName(string fn)
{
	 first = fn;
}

void Greetings_intro::setLastName(string ln)
{
	last = ln;
}

void Greetings_intro::setWeight(string we)
{
	weight = we;
}

void Greetings_intro::setHeightFeet(string hf)
{
	feet = hf;
}

void Greetings_intro::setHeightInches(string hi)
{
	inches = hi;
}

void Greetings_intro::setEthnicity(string eth)
{
	ethnicity = eth;
}

void Greetings_intro::setSex(string s)
{
	sex = s;
}

void Greetings_intro::setBirthControl(string birth)
{
	bc = birth;
}

void Greetings_intro::setPeriodDay(string per)
{
	period = per;
}

void Greetings_intro::setBirthday(string birth)
{
	birthday = birth;
}

string Greetings_intro::getFirstName()
{
	return first;
}

string Greetings_intro::getLastName()
{
	return last;
}

string Greetings_intro::getWeight()
{
	return weight;
}

string Greetings_intro::getHeightFeet()
{
	return feet;
}

string Greetings_intro::getHeightInches()
{
	return inches;
}

string Greetings_intro::getEthnicity()
{
	return ethnicity;
}

string Greetings_intro::getSex()
{
	return sex;
}

string Greetings_intro::getBirthControl()
{
	return bc;
}

string Greetings_intro::getPeriodDay()
{
	return period;
}

string Greetings_intro::getBirthday()
{
	return birthday;
}

int Greetings_intro::random_number(int mod)
{
	// Setup to initialize rand() function
	srand(time(NULL));
	val = rand() % mod;
	return val;
}

Greetings_intro::~Greetings_intro()
{
	cout << "Your constructor has been destroyed!!!" << endl << endl;
}