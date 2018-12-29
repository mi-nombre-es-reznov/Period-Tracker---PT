#pragma once
#ifndef BOUNDS_H
#define BOUNDS_H
#include <iostream>
#include <string>
using namespace std;

class Boundries
{
private:
	int day;
public:
	Boundries();
	string day_checker();
	string get_yes_no();
	string get_height_feet();
	string get_height_inches();
	string weight_checker(int);
	string get_ethnicity();
	string single_word(string);
	string unbind_words(string);
};
#endif