#pragma once
#ifndef UPDATE_CORE_DATA_H
#define UPDATE_CORE_DATA_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Greetings_intro.h"
#include "Bounds.h"
#include <chrono>
#include <ctime> 
#include <fstream>
using namespace std;

class core_updates
{
private:
	string first_name;
	string last_name;
public:
	core_updates();
	void name_and_date(string, string);
	void get_current_date(string, string);
	string get_first(string);
	string get_last(string);
	char update_core_info_menu();
	void update_core_info(char, string);
	void get_time();
};
#endif