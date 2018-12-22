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
	string weight;
	string feet;
	string inches;
	string ethnicity;
	string sex;
	string bc;
	string period;
	string birthday;
	int val;
public:
	Greetings_intro();	// Constructor
	void create_init_file();
	void intro_message();
	void setFirstName(string);
	void setLastName(string);
	void setWeight(string);
	void setHeightFeet(string);
	void setHeightInches(string);
	void setEthnicity(string);
	void setSex(string);
	void setBirthControl(string);
	void setPeriodDay(string);
	void setBirthday(string);
	void show_months();
	string getFirstName();
	string getLastName();
	string getWeight();
	string getHeightFeet();
	string getHeightInches();
	string getEthnicity();
	string getSex();
	string getBirthControl();
	string getPeriodDay();
	string getBirthday();
	int random_number(int);
	
	// Destructor
	~Greetings_intro();
};

// Structs
struct Birthday
{
	int Day;
	string Month;
	int Year;
};

// Call functions
Birthday get_Birthday();
void Months();
#endif