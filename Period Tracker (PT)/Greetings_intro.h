#pragma once
#ifndef GREETINGS_INTRO_H
#define GREETING_INTRO_H
#include <iostream>
#include <string>
using namespace std;

class Greetings_intro
{
private:
	string first;
	string last;
public:
	Greetings_intro();
	void create_init_file();
	void setFirstName(string);
	void setLastName(string);
	string getFirstName();
	string getLastName();
	~Greetings_intro();
};
#endif