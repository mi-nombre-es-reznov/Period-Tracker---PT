#include "Data_Entry.h"
Boundries borders;

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

	cout << "Are you on your period today? ";
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
	PeriodData period_info;
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
		meds = on_Meds();
		cin.ignore();
		notes = get_notes();

		data << date << " " << time << " " << "null " << "null " << "null " << "null " << meds << " null " << "null " << "null " << notes << endl;
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
	cout << "Do you have cramps?" << endl << endl;
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
		cramps_pain = "null";
	}

	cout << endl << "Do you have breast pain?" << endl << endl;
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
		breasts_pain = "None";
	}

	cout << "Are you using a pad or tampon today?" << endl;
	pt = borders.get_yes_no();

	cout << endl << "Is there a foul smell coming from your vagina?" << endl;
	smelly_vag = borders.get_yes_no();

	blood = get_blood_loss();

	return PeriodData{ cramps, cramps_pain, breasts, breasts_pain, pt, smelly_vag, blood };
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
			loss = "Abdormally large amount";
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