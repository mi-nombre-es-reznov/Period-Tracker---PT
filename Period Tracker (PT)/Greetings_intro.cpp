#include "Greetings_intro.h"
#include <iostream>
using namespace std;

Greetings_intro::Greetings_intro()
{
	cout << "Welcome user!!! It is an honor to be able to help you with something that is so close and personal to you.\n"
		"I just need you to answer a few basic questions in order to get started. Please answer as accurately as possible.\n" << endl;
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