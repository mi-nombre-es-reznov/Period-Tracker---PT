#include "Bounds.h"

Boundries::Boundries()
{

}

string Boundries::day_checker()
{
	int i_day;
	string s_day;
	bool numFail;

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		//cout << "\nPlease enter a day: ";
		cin >> i_day;

		if (i_day < 1 || i_day > 31)
		{
			cout << "Invalid option! Please enter a day between 0 and 32: ";
		}

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (i_day < 1) || (i_day > 31));

	s_day = to_string(i_day);

	return s_day;
}

string Boundries::get_yes_no()
{
	char choice;
	string yes_no;

	do
	{
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t\t\tYes/No" << endl << endl << endl;
		cout << "\t\t\ta) Yes" << endl;
		cout << "\t\t\tb) No" << endl;
		cout << endl << endl;

		cout << "\t\t\tPlease select your choice: ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'a' && choice != 'b');

	switch (choice)
	{
		case 'a':
		{
			yes_no = "Yes";
			break;
		}
		case 'b':
		{
			yes_no = "No";
			break;
		}
		default:
		{
			yes_no = "Error";
			break;
		}
	}

	return yes_no;
}

string Boundries::get_height_feet()
{
	int feet;
	string s_feet;
	bool numFail;

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		cin >> feet;
		if (feet < 1 || feet > 7)
		{
			cout << "Invalid option! Please choose an option between 0 -> 7: ";
		}

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (feet < 1) || (feet > 7));

	s_feet = to_string(feet);

	return s_feet;
}

string Boundries::get_height_inches()
{
	int inches;
	string s_inches;
	bool numFail;

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		cin >> inches;
		if (inches < 0 || inches > 11)
		{
			cout << "Invalid option! Please choose an option between 0 (inclusive) -> 12: ";
		}

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (inches < 0) || (inches > 11));

	s_inches = to_string(inches);

	return s_inches;
}

string Boundries::weight_checker()
{
	int weight;
	string s_weight;
	bool numFail;

	// Loop to run through if user were to give invalid choice for day born on.
	do
	{
		cin >> weight;
		if (weight < 40 || weight > 1000)
		{
			cout << "Invalid option! Please choose an option between 40 -> 1000: ";
		}

		numFail = cin.fail();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (numFail == true)
		{
			cout << "You entered an invalid option, please enter a valid number!" << endl;
		}
	} while ((numFail == true) || (weight < 40) || (weight > 1000));

	s_weight = to_string(weight);

	return s_weight;
}

string Boundries::get_ethnicity()
{
	char choice;
	string ethnicity;

	do
	{
		cout << "\n\n\t\t\t\t\t\t\tEthnic Backgrounds" << endl << endl << endl;
		cout << "a) White" << endl;
		cout << "b) Hispanic or latina" << endl;
		cout << "c) Black or African American" << endl;
		cout << "d) Native American or American Indian" << endl;
		cout << "e) Asian/Pacific Islander" << endl;
		cout << "f) Other" << endl << endl << endl;

		cout << "Your choice: ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f');

	switch (choice)
	{
		case 'a':
		{
			ethnicity = "White";
			break;
		}
		case 'b':
		{
			ethnicity = "Latina";
			break;
		}
		case 'c':
		{
			ethnicity = "Black";
			break;
		}
		case 'd':
		{
			ethnicity = "American Indian";
			break;
		}
		case 'e':
		{
			ethnicity = "Asian";
			break;
		}
		case 'f':
		{
			ethnicity = "Other";
			break;
		}
		default:
		{
			ethnicity = "error";
			break;
		}
	}

	return ethnicity;
}

string Boundries::single_word(string word)
{
	// To replace major '_' with spaces
	string altered_word = word;
	int position = altered_word.find(" ");

	if (position != string::npos)
	{
		while (position != string::npos)
		{
			altered_word.replace(position, 1, "_");
			position = altered_word.find(" ", position + 1);
		}
	}

	return altered_word;
}

string Boundries::unbind_words(string words)
{
	// To replace major '_' with spaces
	string altered_word = words;
	int position = altered_word.find("_");

	if (position != string::npos)
	{
		while (position != string::npos)
		{
			altered_word.replace(position, 1, " ");
			position = altered_word.find("_", position + 1);
		}
	}

	return altered_word;
}