#pragma once
#ifndef CALL_AND_STRUCTS_H
#define CALL_AND_STRUCTS_H
#include <iostream>
#include <string>
using namespace std;

// Structs
struct Birthday
{
	int Day;
	string Month;
	int Year;
};

class call_and_structs
{
public:
	call_and_structs();
	// Call functions
	Birthday get_Birthday();
	void Months();
};
#endif