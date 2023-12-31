// TheTemperatureManagerProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


int main() {

	string filename = "temp.txt";

		cout << "The Temperature Manager Program\n\n";

	cout << "COMMANDS\n"
		<< "v - View temperatures\n"
		<< "a - Add a temperatures\n"
		<< "r - Remove temperatures\n"
		<< "s - Save changes\n"
		<< "x - Exit\n";

	// read low and high temps from file and store in vectors
	double low, high;
	vector<double> low_temps, high_temps;
	ifstream input_file;
	input_file.open(filename);
	if (input_file) {
		while (input_file >> low >> high) {
			low_temps.push_back(low);
			high_temps.push_back(high);

		}
		input_file.close();
	}   
	else {
		cout << "Unable to open file. You may need to add Temperatures.\n";
	}
	char command = 'v';
	while (command != 'x') {
		// get command from user
		cout << endl;
		cout << "Command: ";
		cin >> command;
		cout << endl;

		// define variabled
		ofstream output_file;
		int day_num, index;

		// execute switch
		switch (command) {
		case 'v' :
			cout << "TEMPERATURES\n"
				 << left << setw(4) << "Day"
				 << right << setw(8) << "Low" << setw(8) << "high" << endl
				 <<"____ _______ _______" << endl;

			cout << fixed << setprecision(1);
			day_num = 1;
			for (int i = 0; i < low_temps.size(); ++i) {
				low = low_temps[i];
				high = high_temps[i];
				cout << left << setw(4) << day_num
					 << right << setw(8) << low << setw(8) << high << '\n';
				++day_num;

			}
			break;
		case 'a' :
			cout << "Enter low temp:  ";
			cin >> low;

			cout << "Enter high temp:  ";
			cin >> high;

			low_temps.push_back(low);
			high_temps.push_back(high);
			break;

		case 'r' :
			int day;
			cout << "Enter day to remove:  ";
			cin >> day;
			index = day - 1;
			if (index >= 0 && index < high_temps.size()) {
				high_temps.erase(high_temps.begin() + index);
				low_temps.erase(low_temps.begin() + index);

			}
			cout << "Temps for day " << day << " have been removed.\n";
			break;

		case 's' :
			output_file.open(filename);
			for (int i = 0; i < low_temps.size(); ++i) {
				low = low_temps[i];
				high = high_temps[i];
				output_file << low << '\t' << high << '\n';								
			}
			output_file.close();
			cout << "your changes have been saved.\n";
			break;

		case 'x' :
			cout << "Bye!\n\n";
			break;

		default:
			cout << "Invalid command. Try again.\n";

		}

		
	}
}