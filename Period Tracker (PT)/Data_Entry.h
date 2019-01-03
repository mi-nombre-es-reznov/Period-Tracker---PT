#pragma once
#ifndef DATA_ENTRY_H
#define DATA_ENTRY_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Bounds.h"
using namespace std;

struct PeriodData
{
	string cramps;
	string cramps_pain;
	string breast;
	string breast_pain;
	string Pad_Tampon;
	string smelly_vagina;
	string blood_loss;
};

class data_entry
{
private:
	string period;
public:
	data_entry();
	void set_period(string);
	string get_period();
	string ask_period();
	string save_time();
	void started_period(string, string, string);
	void not_on_period(string, string, string);
	string save_date();
	string on_Meds();
	string on_PadsTampons();
	string vagina_odor();
	string get_notes();
	PeriodData get_period_data();
	string get_dec_scale();
	string get_blood_loss();
	void find_curr_day_entry(string, string, string);
	void update_cramp(string, string, string);
	void update_breast(string, string, string);
	void update_meds(string, string, string, string);
	void update_pads_tampons(string, string, string, string);
	void update_foul_smell(string, string, string, string);
	void update_blood_loss(string, string, string, string);
	void update_notes(string, string, string, string);
};
#endif