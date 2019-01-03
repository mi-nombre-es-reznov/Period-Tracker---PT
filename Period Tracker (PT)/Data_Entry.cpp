#include "Data_Entry.h"
Boundries borders;
PeriodData period_info;

data_entry::data_entry()
{

}

void data_entry::set_period(string per)
{
	period = per;
}

string data_entry::get_period()
{
	return period;
}

string data_entry::ask_period()
{
	string period;

	cout << endl << endl << endl << "Are you on your period today? ";
	period = borders.get_yes_no();
	return period;
}

string data_entry::save_time()
{
	string curr_time;
	int totalsec = time(0);
	int currsec = totalsec % 60;
	int totalMin = totalsec / 60;
	int currmin = totalMin % 60;
	int tothours = totalMin / 60;
	int currhour = tothours % 24;

	if (currhour <= 8)
	{
		if (currhour == 0)
		{
			currhour = 16;
		}
		else if (currhour == 1)
		{
			currhour = 17;
		}
		else if (currhour == 2)
		{
			currhour = 18;
		}
		else if (currhour == 3)
		{
			currhour = 19;
		}
		else if (currhour == 4)
		{
			currhour = 20;
		}
		else if (currhour == 5)
		{
			currhour = 21;
		}
		else if (currhour == 6)
		{
			currhour = 22;
		}
		else if (currhour == 7)
		{
			currhour == 23;
		}
		else if (currhour == 8)
		{
			currhour == 0;
		}
	}
	else
	{
		currhour -= 8;
	}

	if (currmin < 10)
	{
		if (currhour < 10)
		{
			curr_time = ("0" + to_string(currhour) + "0" + to_string(currmin));
		}
		else
		{
			curr_time = (to_string(currhour) + "0" + to_string(currmin));
		}
	}
	else
	{
		if (currhour < 10)
		{
			curr_time = ("0" + to_string(currhour) + to_string(currmin));
		}
		else
		{
			curr_time = (to_string(currhour) + to_string(currmin));
		}
	}

	return curr_time;
}

void data_entry::started_period(string name, string time, string date)
{
	string meds, notes;
	// Get info on period.
	//first - does your period hurt? - 0 if no pain and scale below if there is pain.
	//1) On a scale from 1 to 10 (10 being 'give me death', how much pain are they currently in? - null if not on period
	//	if yes, do your breasts hurt?
	//		if yes, 1-10?
	//2) Are you currently on medication?
	//3) Are you using a pad or tampon? - null if not on period
	//4) Does your vagina emit a foul smell? - null if not on period
	//5) How much blood have you lost today? - null if not on period
	//	none, very little, small amount, average (relative to normal loss), large amount, abdormally large amount
	//6) Notes (Put anything you want in this section. Don't use '_' marks.)
	ofstream data;
	data.open(name + "_DataEntry.txt", ios::app);

	if (data.is_open())
	{
		period_info = get_period_data();
		system("CLS");
		meds = on_Meds();
		cin.ignore();
		notes = get_notes();

		data << date << " " << time << " " << period_info.cramps << " " << period_info.cramps_pain << " " << period_info.breast << " "
			<< period_info.breast_pain << " " << meds << " " << period_info.Pad_Tampon << " " << period_info.smelly_vagina << " " <<
			period_info.blood_loss << " " << notes << endl;
	}

	data.close();
}

void data_entry::not_on_period(string name, string time, string date)
{
	string meds, notes;
	// Get info on period.
	//first - does your period hurt? - 0 if no pain and scale below if there is pain.
	//1) On a scale from 1 to 10 (10 being 'give me death', how much pain are they currently in? - null if not on period
	//	if yes, do your breasts hurt?
	//		if yes, 1-10?
	//2) Are you currently on medication?
	//3) Are you using a pad or tampon? - null if not on period
	//4) Does your vagina emit a foul smell? - null if not on period
	//5) How much blood have you lost today? - null if not on period
	//	none, very little, small amount, average (relative to normal loss), large amount, abdormally large amount
	//6) Notes (Put anything you want in this section. Don't use '_' marks.)

	ofstream data;
	data.open(name + "_DataEntry.txt", ios::app);

	if (data.is_open())
	{
		system("CLS");
		meds = on_Meds();
		cin.ignore();
		notes = get_notes();

		data << date << " " << time << " " << "n/a " << "n/a " << "n/a " << "n/a " << meds << " n/a " << "n/a " << "n/a " << notes << endl;
	}

	data.close();
}

string data_entry::save_date()
{
	int month_i;
	string month, save;

	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	month_i = (now->tm_mon + 1);

	switch (month_i)
	{
		case 1:
		{
			month = "January";
			break;
		}
		case 2:
		{
			month = "February";
			break;
		}
		case 3:
		{
			month = "March";
			break;
		}
		case 4:
		{
			month = "April";
			break;
		}
		case 5:
		{
			month = "May";
			break;
		}
		case 6:
		{
			month = "June";
			break;
		}
		case 7:
		{
			month = "July";
			break;
		}
		case 8:
		{
			month = "August";
			break;
		}
		case 9:
		{
			month = "September";
			break;
		}
		case 10:
		{
			month = "October";
			break;
		}
		case 11:
		{
			month = "November";
			break;
		}
		case 12:
		{
			month = "December";
			break;
		}
		default:
		{
			month = "Error";
			cout << "An error has occured";
			break;
		}
	}

	save = month + '_' + to_string(now->tm_mday) + ",_" + to_string(now->tm_year + 1900);
	//cout << "Saved Date: " << save << endl;
	//system("pause");
	return save;
}

string data_entry::on_Meds()
{
	string meds;

	cout << "Are you taking medication currently?" << endl << endl;
	meds = borders.get_yes_no();

	return meds;
}

string data_entry::on_PadsTampons()
{
	string padsTampons;

	cout << "Are you using a pad or tampon today?" << endl << endl;
	padsTampons = borders.get_yes_no();

	return padsTampons;
}

string data_entry::vagina_odor()
{
	string vag;

	cout << "Is there a foul smell coming from your vagina?" << endl << endl;
	vag = borders.get_yes_no();

	return vag;
}

string data_entry::get_notes()
{
	string notes;

	system("CLS");
	cout << "\t\t\t\t\t\t\tNotes" << endl << endl << endl;
	cout << "Please treat this section as you would like a daily journal. Record any notes you would like and how your day was.\n(preferably relative to your period - for your own benefit)" << endl;
	cout << "Press enter/return to submit data! (Do not include '_' characters in your submission)" << endl << endl << endl << endl;
	cout << "Notes: ";
	getline(cin, notes);
	notes = borders.single_word(notes);
	
	return notes;
}

PeriodData data_entry::get_period_data()
{
	//PeriodData period_stuff;
	string cramps, cramps_pain, breasts, breasts_pain, c_pain, b_pain, pt, smelly_vag, blood;
	system("CLS");
	cout << "Have you had cramps recently?" << endl << endl;
	cramps = borders.get_yes_no();

	if (cramps == "Yes")
	{
		cout << "\n\nAre your cramps hurting you today?" << endl << endl;
		c_pain = borders.get_yes_no();
		if (c_pain == "Yes")
		{
			system("CLS");
			cout << "How much pain are you experiencing from cramps?" << endl;
			cramps_pain = get_dec_scale();
		}
		else
		{
			cramps_pain = "None";
		}
	}
	else
	{
		c_pain = "No";
		cramps_pain = "None";
	}

	system("CLS");
	cout << "Have you had breast pain recently?" << endl << endl;
	breasts = borders.get_yes_no();

	if (breasts == "Yes")
	{
		cout << "\n\nAre your breasts hurting today?" << endl << endl;
		b_pain = borders.get_yes_no();
		if (b_pain == "Yes")
		{
			system("CLS");
			cout << "How much pain are your breasts giving you?" << endl;
			breasts_pain = get_dec_scale();
		}
		else
		{
			breasts_pain = "None";
		}
	}
	else
	{
		b_pain = "No";
		breasts_pain = "None";
	}

	system("CLS");
	pt = on_PadsTampons();

	system("CLS");
	smelly_vag = vagina_odor();

	system("CLS");
	blood = get_blood_loss();

	//cout << "c_pain: " << c_pain << endl;
	//cout << "cramps pain: " << cramps_pain << endl;
	//cout << "B pain: " << b_pain << endl;
	//cout << "breasts pain: " << breasts_pain << endl;
	//cout << "pad: " << pt << endl;
	//cout << "smelly vag: " << smelly_vag << endl;
	//cout << "bloody: " << blood << endl;
	//system("pause");
	return PeriodData{ c_pain, cramps_pain, b_pain, breasts_pain, pt, smelly_vag, blood};
}

string data_entry::get_dec_scale()
{
	cout << "Please choose an option (10 being the worst): ";
	int scale;
	string s_scale;
	bool numFail;

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		cin >> scale;
		if (scale < 1 || scale > 10)
		{
			cout << "Invalid option! Please choose an option between 1 -> 10: ";
		}

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (scale < 1) || (scale > 10));

	s_scale = to_string(scale);

	return s_scale;
}

string data_entry::get_blood_loss()
{
	char choice;
	string loss;

	do
	{
		system("CLS");
		cout << "\t\t\t\t\t\t\tBlood Loss" << endl;
		cout << "\t\t\ta) None" << endl;
		cout << "\t\t\tb) Very Little" << endl;
		cout << "\t\t\tc) Average" << endl;
		cout << "\t\t\td) A lot" << endl;
		cout << "\t\t\te) Abdormally large amount" << endl << endl << endl;
		cout << endl << "How much blood have you lost today? (relative to your average): ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e');

	switch (choice)
	{
		case 'a':
		{
			loss = "None";
			break;
		}
		case 'b':
		{
			loss = "Very_Little";
			break;
		}
		case 'c':
		{
			loss = "Average";
			break;
		}
		case 'd':
		{
			loss = "A_lot";
			break;
		}
		case 'e':
		{
			loss = "Abdormally_large_amount";
			break;
		}
		default:
		{
			loss = "Error";
			break;
		}
	}

	return loss;
}

void data_entry::find_curr_day_entry(string day, string time, string name)
{
	string meds, notes, date, og_time, see_info, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	char update_info;
	int count = 0;

	ifstream file;
	file.open(name + "_DataEntry.txt");

	if (file.is_open())
	{
		while (file >> date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (date == day)
			{
				count += 1;
			}
		}

		if (count > 0)
		{
			cout << endl << endl << "Would you like to see the info we have on file?" << endl;
			see_info = borders.get_yes_no();
			

			if (see_info == "Yes")
			{
				system("CLS");
				cout << "\t\t\t\t\t\t\tToday's Data" << endl << endl << endl << endl;
				cout << "Today's Date? " << date << endl;
				cout << "Original time? " << og_time << endl;
				cout << "Have you had cramps today? " << cramps << endl;
				cout << "Pain level from cramps? " << cramps_pain << endl;
				cout << "Have you had breast pain today? " << breast << endl;
				cout << "Pain level from breasts? " << breast_pain << endl;
				cout << "Are you on medication? " << meds << endl;
				cout << "Are you using a pad/tampon? " << Pad_Tampon << endl;
				cout << "Is there a foul smell coming from your vagina? " << smelly_vagina << endl;
				cout << "Blood loss level (relative to normal average)? " << blood_loss << endl;
				cout << "Note: " << notes << endl << endl << endl;
				system("pause");

				system("CLS");
				do
				{
					cout << "\t\t\t\t\tUpdate Today's Entry" << endl << endl << endl;
					cout << "\t\t\ta) Pain from cramps" << endl;
					cout << "\t\t\tb) Pain from breasts" << endl;
					cout << "\t\t\tc) Medication" << endl;
					cout << "\t\t\td) Pad/Tampon usage" << endl;
					cout << "\t\t\te) Foul smell" << endl;
					cout << "\t\t\tf) Blood loss" << endl;
					cout << "\t\t\tg) Notes" << endl;
					cout << "\t\t\th) Cancel update" << endl << endl;
					cout << "\nWhat would you like to update? ";
					cin >> update_info;

					update_info = tolower(update_info);
				} while (update_info != 'a' && update_info != 'b' && update_info != 'c' && update_info != 'd' && update_info != 'e' && update_info != 'f' && update_info != 'g' && update_info != 'h');

				switch (update_info)
				{
					case 'a':
					{
						update_cramp(name, day, time);
						break;
					}
					case 'b':
					{
						update_breast(name, day, time);
						break;
					}
					case 'c':
					{
						string on_meds;
						on_meds = on_Meds();
						update_meds(name, day, time, on_meds);
						break;
					}
					case 'd':
					{
						string on_pads;
						on_pads = on_PadsTampons();
						update_pads_tampons(name, day, time, on_pads);
						break;
					}
					case 'e':
					{
						string is_foul;
						is_foul = vagina_odor();
						update_foul_smell(name, day, time, is_foul);
						break;
					}
					case 'f':
					{
						string update_bl;
						update_bl = get_blood_loss();
						update_blood_loss(name, day, time, update_bl);
						break;
					}
					case 'g':
					{
						string new_note;
						cin.ignore();
						new_note = get_notes();
						update_notes(name, day, time, new_note);
						break;
					}
					case 'h':
					{
						system(0);
						break;
					}
					default:
					{
						cout << "Error! Please check code!!!" << endl;
						break;
					}
				}
			}
			else
			{
				system("CLS");
				do
				{
					cout << "\t\t\t\t\tUpdate Today's Entry" << endl << endl << endl;
					cout << "\t\t\ta) Pain from cramps" << endl;
					cout << "\t\t\tb) Pain from breasts" << endl;
					cout << "\t\t\tc) Medication" << endl;
					cout << "\t\t\td) Pad/Tampon usage" << endl;
					cout << "\t\t\te) Foul smell" << endl;
					cout << "\t\t\tf) Blood loss" << endl;
					cout << "\t\t\tg) Notes" << endl;
					cout << "\t\t\th) Cancel update" << endl << endl;
					cout << "\nWhat would you like to update? ";
					cin >> update_info;

					update_info = tolower(update_info);
				} while (update_info != 'a' && update_info != 'b' && update_info != 'c' && update_info != 'd' && update_info != 'e' && update_info != 'f' && update_info != 'g' && update_info != 'h');

				switch (update_info)
				{
					case 'a':
					{
						update_cramp(name, day, time);
						break;
					}
					case 'b':
					{
						update_breast(name, day, time);
						break;
					}
					case 'c':
					{
						string on_meds;
						on_meds = on_Meds();
						update_meds(name, day, time, on_meds);
						break;
					}
					case 'd':
					{
						string on_pads;
						on_pads = on_PadsTampons();
						update_pads_tampons(name, day, time, on_pads);
						break;
					}
					case 'e':
					{
						string is_foul;
						is_foul = vagina_odor();
						update_foul_smell(name, day, time, is_foul);
						break;
					}
					case 'f':
					{
						string update_bl;
						update_bl = get_blood_loss();
						update_blood_loss(name, day, time, update_bl);
						break;
					}
					case 'g':
					{
						string new_note;
						cin.ignore();
						new_note = get_notes();
						update_notes(name, day, time, new_note);
						break;
					}
					case 'h':
					{
						system(0);
						break;
					}
					default:
					{
						cout << "Error! Please check code!!!" << endl;
						break;
					}
				}

			}
		}
		else
		{
			cout << endl << endl << "No data is on file for today's date. Would you like to create a new entry?";
			string new_entry = borders.get_yes_no();

			if (new_entry == "Yes")
			{
				period = ask_period();
				set_period(period);
				cout << endl << endl;
				if (period == "Yes")
				{
					started_period(name, time, day);
				}
				else if (period == "No")
				{
					not_on_period(name, time, day);
				}
				else
				{
					system("CLS");
					cout << "An error has occurred. Please restart the program and try again!" << endl;
					system("pause");
				}
			}
			else
			{
				cout << endl << endl << "Understood. No changes will be made!" << endl;
			}
		}
	}
}

void data_entry::update_cramp(string first, string date, string time)
{
	string cramps_update, cramps_pain_update, c_pain_update;
	//system("CLS");
	cout << "Have you had cramps recently?" << endl << endl;
	cramps_update = borders.get_yes_no();

	if (cramps_update == "Yes")
	{
		cout << "\n\nAre your cramps hurting you today?" << endl << endl;
		c_pain_update = borders.get_yes_no();
		if (c_pain_update == "Yes")
		{
			system("CLS");
			cout << "How much pain are you experiencing from cramps?" << endl;
			cramps_pain_update = get_dec_scale();
		}
		else
		{
			cramps_pain_update = "None";
		}
	}
	else
	{
		c_pain_update = "No";
		cramps_pain_update = "None";
	}

	//cout << "cramps hurting: " << c_pain_update << endl;
	//cout << "cramps pain level: " << cramps_pain_update << endl;
	//system("pause");

	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << c_pain_update << " " << cramps_pain_update << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}

}

void data_entry::update_breast(string first, string date, string time)
{
	string breasts, b_pain, breasts_pain, b_pain_update, breasts_pain_update;

	system("CLS");
	cout << "Have you had breast pain recently?" << endl << endl;
	breasts = borders.get_yes_no();

	if (breasts == "Yes")
	{
		cout << "\n\nAre your breasts hurting today?" << endl << endl;
		b_pain_update = borders.get_yes_no();
		if (b_pain_update == "Yes")
		{
			system("CLS");
			cout << "How much pain are your breasts giving you?" << endl;
			breasts_pain_update = get_dec_scale();
		}
		else
		{
			breasts_pain_update = "None";
		}
	}
	else
	{
		b_pain_update = "No";
		breasts_pain_update = "None";
	}

	//cout << "breasts hurting: " << b_pain_update << endl;
	//cout << "breasts pain level: " << breasts_pain_update << endl;
	//system("pause");

	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << b_pain_update << " " << breasts_pain_update << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}

}

void data_entry::update_meds(string first, string date, string time, string on_meds)
{
	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << on_meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}
}

void data_entry::update_pads_tampons(string first, string date, string time, string pad)
{
	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << pad << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}
}

void data_entry::update_foul_smell(string first, string date, string time, string smell)
{
	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smell << " " << blood_loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}
}

void data_entry::update_blood_loss(string first, string date, string time, string loss)
{
	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << loss << " " << notes << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}
}

void data_entry::update_notes(string first, string date, string time, string note)
{
	string og_date, og_time, meds, notes, cramps, cramps_pain, breast, breast_pain, Pad_Tampon, smelly_vagina, blood_loss;
	ifstream file;
	ofstream update;
	file.open(first + "_DataEntry.txt");
	update.open(first + "_transfer.txt");

	if (file.is_open())
	{
		while (file >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			if (og_date == date)
			{
				update << og_date << " " << time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << note << endl;
			}
			else
			{
				update << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
			}
		}

		file.close();
		update.close();
	}

	ofstream file2;
	ifstream update2;
	file2.open(first + "_DataEntry.txt");
	update2.open(first + "_transfer.txt");

	if (update2.is_open())
	{
		while (update2 >> og_date >> og_time >> cramps >> cramps_pain >> breast >> breast_pain >> meds >> Pad_Tampon >> smelly_vagina >> blood_loss >> notes)
		{
			file2 << og_date << " " << og_time << " " << cramps << " " << cramps_pain << " " << breast << " " << breast_pain << " " << meds << " " << Pad_Tampon << " " << smelly_vagina << " " << blood_loss << " " << notes << endl;
		}

		file2.close();
		update2.close();
	}
}