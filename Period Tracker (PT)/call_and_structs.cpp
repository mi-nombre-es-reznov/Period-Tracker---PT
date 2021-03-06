#include "call_and_structs.h"
Boundries bounded;

call_and_structs::call_and_structs()
{

}

// -------------------------------
//       Get member Birthday
// -------------------------------
Birthday call_and_structs::get_Birthday()
{
	int day, year;
	string month;
	bool numFail;
	int choice;

	// Loop to rerun through if user gives invalid choice for year born in.
	do
	{
		cout << "What year were you born: ";
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
			//cout << "\n\nChoice accepted. You picked January." << endl;
			month = "January";
			return Birthday{ day, month, year };
			break;
		}
		case 2:
		{
			//cout << "\n\nChoice accepted. You picked February." << endl;
			month = "February";
			return Birthday{ day, month, year };
			break;
		}
		case 3:
		{
			//cout << "\n\nChoice accepted. You picked March." << endl;
			month = "March";
			return Birthday{ day, month, year };
			break;
		}
		case 4:
		{
			//cout << "\n\nChoice accepted. You picked April." << endl;
			month = "April";
			return Birthday{ day, month, year };
			break;
		}
		case 5:
		{
			//cout << "\n\nChoice accepted. You picked May." << endl;
			month = "May";
			return Birthday{ day, month, year };
			break;
		}
		case 6:
		{
			//cout << "\n\nChoice accepted. You picked June." << endl;
			month = "June";
			return Birthday{ day, month, year };
			break;
		}
		case 7:
		{
			//cout << "\n\nChoice accepted. You picked July." << endl;
			month = "July";
			return Birthday{ day, month, year };
			break;
		}
		case 8:
		{
			//cout << "\n\nChoice accepted. You picked August." << endl;
			month = "August";
			return Birthday{ day, month, year };
			break;
		}
		case 9:
		{
			//cout << "\n\nChoice accepted. You picked Septmeber." << endl;
			month = "September";
			return Birthday{ day, month, year };
			break;
		}
		case 10:
		{
			//cout << "\n\nChoice accepted. You picked October." << endl;
			month = "October";
			return Birthday{ day, month, year };
			break;
		}
		case 11:
		{
			//cout << "\n\nChoice accepted. You picked November." << endl;
			month = "November";
			return Birthday{ day, month, year };
			break;
		}
		case 12:
		{
			//cout << "\n\nChoice accepted. You picked December." << endl;
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

// -------------------------------
//       Display Month Menu
// -------------------------------
void call_and_structs::Months()
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

string call_and_structs::get_question(char choice)
{
	string name, rep_weight, rep_hf, rep_hi, rep_ethnicity, rep_sex, rep_bc, rep_avg_dop, rep_birthday;
	int int_weight;

	switch (choice)
	{
		case 'a':
		{
			cout << "Please enter your new first name: ";
			getline(cin, name);
			name = bounded.single_word(name);
			return name;
			break;
		}
		case 'b':
		{
			cout << "Please enter your new last name: ";
			getline(cin, name);
			name = bounded.single_word(name);
			return name;
			break;
		}
		case 'c':
		{
			cout << "Please enter your new weight: ";
			rep_weight = bounded.weight_checker();
			return rep_weight;
			break;
		}
		case 'd':
		{
			cout << "Please enter your new height (feet only): ";
			rep_hf = bounded.get_height_feet();
			return rep_hf;
			break;
		}
		case 'e':
		{
			cout << "Please enter your new height (inches only): ";
			rep_hi = bounded.get_height_inches();
			return rep_hi;
			break;
		}
		case 'f':
		{
			rep_ethnicity = bounded.get_ethnicity();
			return rep_ethnicity;
			break;
		}
		case 'g':
		{
			cout << "Are you sexually active? ";
			rep_sex = bounded.get_yes_no();
			return rep_sex;
			break;
		}
		case 'h':
		{
			cout << "Are you on birth control? ";
			rep_bc = bounded.get_yes_no();
			return rep_bc;
			break;
		}
		case 'i':
		{
			cout << "Please enter a new average day for your period: ";
			rep_avg_dop = bounded.day_checker();
			return rep_avg_dop;
			break;
		}
		case 'j':
		{
			return "birthday_loop";
			break;
		}
		case 'k':
		{
			return "Exit";
			break;
		}
		default:
		{
			return "Error!";
			break;
		}
	}
}

int call_and_structs::getPassword(string pass)
{
	string password;
	int match;

	cout << "Please enter your password to continue: ";
	getline(cin, password);

	if (password == pass)
	{
		match = 1;
	}
	else
	{
		system("CLS");
		cout << "Password is incorrect!" << endl;
		match = 0;
	}

	return match;
}