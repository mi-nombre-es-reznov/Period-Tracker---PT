#include "update_core_data.h"

core_updates::core_updates()
{
	
}

void core_updates::name_and_date(string first, string last)
{
	cout << setw(10);
	get_current_date(first, last);
}

void core_updates::get_current_date(string f, string l)
{
	int month_i;
	string month;

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

	cout << setw(15) << f << " " << l << setw(66) << month << ' ' << now->tm_mday << ", " << (now->tm_year + 1900) <<  endl;
	cout << endl << endl << endl;
	get_time();
}

string core_updates::get_first(string first)
{
	first_name = first;
	return first_name;
}

string core_updates::get_last(string last)
{
	last_name = last;
	return last_name;
}

char core_updates::update_core_info_menu()
{
	char option;

	do
	{
		cout << "\n\n\n\t\t\t\t\tPlease select what you want to update" << endl << endl << endl;
		cout << "\t\ta) First name" << endl;
		cout << "\t\tb) Last name" << endl;
		cout << "\t\tc) Weight" << endl;
		cout << "\t\td) Height (feet)" << endl;
		cout << "\t\te) Height (inches)" << endl;
		cout << "\t\tf) ethnicity" << endl;
		cout << "\t\tg) sexually active" << endl;
		cout << "\t\th) birth control status" << endl;
		cout << "\t\ti) Average day of period" << endl;
		cout << "\t\tj) Birthday" << endl;
		cout << "\t\tk) Exit" << endl << endl << endl;
		cout << "Please select an option: ";

		cin >> option;

		option = tolower(option);
	} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e' && option != 'f' && option != 'g' && option != 'h' && option != 'i' && option != 'j' && option != 'k');

	return option;
}

void core_updates::update_core_info(char choice, string update)
{
	Boundries bounds;
	string y_or_n;

	switch (choice)
	{
		case 'a':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current first name as: " << first_name << endl;
					cout << "You have requested to change your name to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << update << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'b':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current last name as: " << last_name << endl;
					cout << "You have requested to change your name to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << update << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'c':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open()) 
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current weight as: " << weight << endl;
					cout << "You have requested to change your weight to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << update << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'd':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current height (feet only) as: " << hfeet << endl;
					cout << "You have requested to change your height (feet only) to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << update << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'e':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current height (inches only) as: " << hinches << endl;
					cout << "You have requested to change your height (inches only) to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << update << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'f':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current ethnicity as: " << ethnicity << endl;
					cout << "You have requested to change your ethnicity to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << update << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'g':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current sexually active status as: " << sex << endl;
					cout << "You have requested to change your sexually active status to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << update << " " << bc_pills << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'h':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current birth control status as: " << bc_pills << endl;
					cout << "You have requested to change your birth control status to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << update << " " << day_of_period << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'i':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current average period day as: " << day_of_period << endl;
					cout << "You have requested to change your average period day to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << update << " " << birthday;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'j':
		{
			ifstream first;
			ofstream copy;
			first.open("female_data.txt");
			copy.open("copy_data.txt");

			string first_name, last_name, weight, hfeet, hinches, ethnicity, sex, bc_pills, day_of_period, birthday;

			if (first.is_open())
			{
				while (first >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
				{
					cout << "We have entered the update successfully!!!" << endl;
					cout << "We have, on file, your current birthday as: " << birthday << endl;
					cout << "You have requested to change your birthday to: " << update << endl;
					cout << "Is this correct? (y or n): ";
					y_or_n = bounds.get_yes_no();
				}

				if (y_or_n == "Yes")
				{
					if (copy.is_open())
					{
						copy << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << update;
					}

					cout << "Your information has been updated." << endl;
				}
				else
				{
					cout << "Understood. We have not make any changes." << endl;
				}
			}

			first.close();
			copy.close();

			if (y_or_n == "Yes")
			{
				ofstream first2;
				ifstream copy2;
				first2.open("female_data.txt");
				copy2.open("copy_data.txt");

				if (copy2.is_open())
				{
					while (copy2 >> first_name >> last_name >> weight >> hfeet >> hinches >> ethnicity >> sex >> bc_pills >> day_of_period >> birthday)
					{
						first2 << first_name << " " << last_name << " " << weight << " " << hfeet << " " << hinches << " " << ethnicity << " " << sex << " " << bc_pills << " " << day_of_period << " " << birthday;
					}
				}

				first2.close();
				copy2.close();
			}

			break;
		}
		case 'k':
		{
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nThank you for using NCompEng Technologies. Please visit again soon!" << endl;
			system("pause");
			exit(0);
			break;
		}
		default:
		{
			cout << "Error!!!" << endl;
		}
	}

	system("pause");
}

void core_updates::get_time()
{
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
			cout << "Time initiated: " << "0" << currhour << "0" << currmin << " Pacific Time" << endl;
		}
		else
		{
			cout << "Time initiated: " << currhour << "0" << currmin << " Pacific Time" << endl;
		}
	}
	else
	{
		if (currhour < 10)
		{
			cout << "Time initiated: " << "0" << currhour << currmin << " Pacific Time" << endl;
		}
		else
		{
			cout << "Time initiated: " << currhour << currmin << " Pacific Time" << endl;
		}
	}
}