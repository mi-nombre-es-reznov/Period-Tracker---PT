#include "Greetings_intro.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

Greetings_intro::Greetings_intro()
{

}

void Greetings_intro::intro_message()
{
	cout << "Welcome user!!! It is an honor to be able to help you with something that is so close and personal to you.\n"
		"I just need you to answer a few basic questions in order to get started. Please answer as accurately as possible.\n" << endl;
}

void Greetings_intro::create_init_file()
{
	ofstream init;
	init.open("female_data.txt");

	if (init.is_open())
	{
		init << "user_first ";
		init << "user_last ";
		init << "weight ";
		init << "height_feet ";
		init << "height_inches ";
		init << "ethnicity ";
		init << "sexually_active ";
		init << "birth_control ";
		init << "typical_day_of_period ";
		init << "Birthday";
	}
	else
	{
		cout << "Initial data failed to be created!" << endl;
	}

	init.close();
	if (!init.is_open())
	{
		//cout << "Initial data is closed!" << endl;
	}
	else
	{
		cout << "Initial data file has failed to close!" << endl;
	}
}

void Greetings_intro::setFirstName(string fn)
{
	 first = fn;
}

void Greetings_intro::setLastName(string ln)
{
	last = ln;
}

void Greetings_intro::setWeight(string we)
{
	weight = we;
}

void Greetings_intro::setHeightFeet(string hf)
{
	feet = hf;
}

void Greetings_intro::setHeightInches(string hi)
{
	inches = hi;
}

void Greetings_intro::setEthnicity(string eth)
{
	ethnicity = eth;
}

void Greetings_intro::setSex(string s)
{
	sex = s;
}

void Greetings_intro::setBirthControl(string birth)
{
	bc = birth;
}

void Greetings_intro::setPeriodDay(string per)
{
	period = per;
}

void Greetings_intro::setBirthday(string birth)
{
	birthday = birth;
}

void Greetings_intro::show_months()
{
	cout << "\t\t\t\t\tMonths" << endl << endl;
	cout << "\t\t\t1) January" << endl;
	cout << "\t\t\t2) February" << endl;
	cout << "\t\t\t3) March" << endl;
	cout << "\t\t\t4) April" << endl;
	cout << "\t\t\t5) May" << endl;
	cout << "\t\t\t6) June" << endl;
	cout << "\t\t\t7) July" << endl;
	cout << "\t\t\t8) August" << endl;
	cout << "\t\t\t9) September" << endl;
	cout << "\t\t\t10) October" << endl;
	cout << "\t\t\t11) November" << endl;
	cout << "\t\t\t12) December" << endl << endl << endl;
}

string Greetings_intro::getFirstName()
{
	return first;
}

string Greetings_intro::getLastName()
{
	return last;
}

string Greetings_intro::getWeight()
{
	return weight;
}

string Greetings_intro::getHeightFeet()
{
	return feet;
}

string Greetings_intro::getHeightInches()
{
	return inches;
}

string Greetings_intro::getEthnicity()
{
	return ethnicity;
}

string Greetings_intro::getSex()
{
	return sex;
}

string Greetings_intro::getBirthControl()
{
	return bc;
}

string Greetings_intro::getPeriodDay()
{
	return period;
}

string Greetings_intro::getBirthday()
{
	return birthday;
}

int Greetings_intro::random_number(int mod)
{
	// Setup to initialize rand() function
	srand(time(NULL));
	val = rand() % mod;
	return val;
}

Greetings_intro::~Greetings_intro()
{
	cout << "Your constructor has been destroyed!!!" << endl << endl;
}

// -------------------------------
//       Display Month Menu
// -------------------------------
void Months()
{
	cout << endl << endl << endl << endl;	// Give space in beginning
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t       Month Selection Menu" << endl;
	cout << "\t\t\t*********************************" << endl << endl << endl;

	cout << "\t\t\t1) January" << endl;
	cout << "\t\t\t2) February" << endl;
	cout << "\t\t\t3) March" << endl;
	cout << "\t\t\t4) April" << endl;
	cout << "\t\t\t5) May" << endl;
	cout << "\t\t\t6) June" << endl;
	cout << "\t\t\t7) July" << endl;
	cout << "\t\t\t8) August" << endl;
	cout << "\t\t\t9) Septemeber" << endl;
	cout << "\t\t\t10) October" << endl;
	cout << "\t\t\t11) November" << endl;
	cout << "\t\t\t12) December" << endl;

	// Give space at the end
	cout << endl << endl << endl << endl;
}

// -------------------------------
//       Get member Birthday
// -------------------------------
Birthday get_Birthday()
{
	int day, year;
	string month;
	bool numFail;
	int choice;

	// Loop to rerun through if user gives invalid choice for year born in.
	do
	{
		cout << "\nWhat year were you born: ";
		cin >> year;

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (year < 1950) || (year > 2018));

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		cout << "\nPlease enter the day in which you were born: ";
		cin >> day;

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (day < 1) || (day > 31));

	// Loop to have user select from options of months and to rerun if choice is invalid.
	do
	{
		Months();
		cout << "\nPlease enter the month in which you were born: ";
		cin >> choice;

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (choice < 1) || (choice > 12));

	// Switch statement to run through if user choices are all valid and also returns selections in a struct to be processed.
	switch (choice)
	{
	case 1:
	{
		cout << "\n\nChoice accepted. You picked January." << endl;
		month = "January";
		return Birthday{ day, month, year };
		break;
	}
	case 2:
	{
		cout << "\n\nChoice accepted. You picked February." << endl;
		month = "February";
		return Birthday{ day, month, year };
		break;
	}
	case 3:
	{
		cout << "\n\nChoice accepted. You picked March." << endl;
		month = "March";
		return Birthday{ day, month, year };
		break;
	}
	case 4:
	{
		cout << "\n\nChoice accepted. You picked April." << endl;
		month = "April";
		return Birthday{ day, month, year };
		break;
	}
	case 5:
	{
		cout << "\n\nChoice accepted. You picked May." << endl;
		month = "May";
		return Birthday{ day, month, year };
		break;
	}
	case 6:
	{
		cout << "\n\nChoice accepted. You picked June." << endl;
		month = "June";
		return Birthday{ day, month, year };
		break;
	}
	case 7:
	{
		cout << "\n\nChoice accepted. You picked July." << endl;
		month = "July";
		return Birthday{ day, month, year };
		break;
	}
	case 8:
	{
		cout << "\n\nChoice accepted. You picked August." << endl;
		month = "August";
		return Birthday{ day, month, year };
		break;
	}
	case 9:
	{
		cout << "\n\nChoice accepted. You picked Septmeber." << endl;
		month = "September";
		return Birthday{ day, month, year };
		break;
	}
	case 10:
	{
		cout << "\n\nChoice accepted. You picked October." << endl;
		month = "October";
		return Birthday{ day, month, year };
		break;
	}
	case 11:
	{
		cout << "\n\nChoice accepted. You picked November." << endl;
		month = "November";
		return Birthday{ day, month, year };
		break;
	}
	case 12:
	{
		cout << "\n\nChoice accepted. You picked December." << endl;
		month = "December";
		return Birthday{ day, month, year };
		break;
	}
	default:
	{
		cout << "An error has occured. Try again.";
		break;
	}
	}
}