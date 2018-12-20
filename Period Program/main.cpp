// Nicholas Perez-Aguilar
// 16 Dec 2018
// Title: Period Tracker (PT)
// Description: This program is going to be used to assist females in keeping track
// of their monthly cycles and to help assist in determining different information
// regarding this area of their lives.

#include <iostream>
#include <ctime>
#include <fstream>
#include "Greetings_intro.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

void get_current_date();

int main()
{
	cout << "Hello, World!" << endl;

	
	get_current_date();
	cout << endl << endl;

	Intro intro_obj;
	intro_obj.opening_text();

	system("pause");
	return 0;
}

void get_current_date()
{
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< "\n";
}