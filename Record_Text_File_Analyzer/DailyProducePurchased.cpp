/*
* CPP file containing public member functions for DailyProducePurchased.h file
* Author: Robert Harmon
* Date: 2/19/23
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "DailyProducePurchased.h"
#include <iomanip>
using namespace std;

// Read data from generated file of produce purchased, then add them to produce map and increment number of items for each duplicate item read
void DailyProducePurchased::ReadDataToMap() {
	ifstream inFS; // variable for input stream
	string item;   // variable to hold produce item name in loop
	
	inFS.open("Project3_input.txt"); // open produce file to read

	if (!inFS.is_open()) { // if file failed to open, output message
		cout << "Could not open file" << endl;
	}
	else {
		// loop till end of read file
		while (!inFS.eof()) {
			inFS >> item; // read 1 input from file
			// if input is already a key in the produce items map, increment key value by 1
			if (produceItems.count(item) == 1) {
				produceItems.at(item) = produceItems.at(item) + 1;
			}
			// else add item to map as key with a value of 1
			else {
				produceItems.emplace(item, 1);
			}
		}
	}
}

// write data from produce item map to frequency.dat file created in ReadDataToMap function
void DailyProducePurchased::WriteDataToFile() {
	ofstream outFS; // variable for output stream

	outFS.open("frequency.dat"); // create .dat data file to write data to

	// for each key and value in the produce items map, write them to the data file
	for (const auto& item : produceItems) {
		outFS << item.first << " " << item.second << endl;
	}
}

// output menu for user to show input options and functionality for program
void DailyProducePurchased::OutputMenu() {
	cout << string(34, '*') << endl;
	cout << "Check Items Purchased For The Day" << endl;
	cout << string(34, '*') << endl;
	cout << "1  Enter a produce item to see how many were sold today" << endl;
	cout << "2  Print a list with the number sold for each produce item" << endl;
	cout << "3  Print a graphical representation of the number sold for each produce item" << endl;
	cout << "4  Exit this program" << endl;
	cout << endl << "Please input a selection of one of these numbers" << endl;
}

// get user input for menu
int DailyProducePurchased::GetInput(int& userInput) {
	cin >> userInput; // get user input for menu option

	// validate user input for menu choice
	while ((cin.fail()) || (userInput < 1) || (userInput > 4)) {
		cin.clear();            // clear error flag on cin to check again
		cin.ignore(20, '\n');   // remove newline char from input buffer, allow for new input from user
		cout << "Please choose a number from the list (1-4) to perform that function" << endl;
		cin >> userInput;       // get new input from user
	}

	return userInput;
}

// get user input for a produce item and output item and number purchased
void DailyProducePurchased::PrintValueOfItem() {
	string item;
	cout << "Enter name of produce item to get quantity sold for the day" << endl;
	cin >> item;

	while ((produceItems.count(item) == 0) || (cin.fail())) {
		cin.clear();            // clear error flag on cin to check again
		cin.ignore(20, '\n');   // remove newline char from input buffer, allow for new input from user
		cout << "Couldn't find that item in the list of purchased items." << endl;
		cout << "Please try another item name, starting with a capital letter." << endl;
		cin >> item;
	}

	cout << produceItems.at(item) << " " << item << " were purchased." << endl;
	cin.ignore(20, '\n');   // remove newline char from input buffer, allow for new input from user
}

// Print all produce items with number of each item
void DailyProducePurchased::PrintValueList() {
	for (const auto& item : produceItems) {
		cout << item.first << " " << item.second << endl;
	}
}

// Print all produce items with number of each item shown graphically
void DailyProducePurchased::PrintValueHistogram() {
	
	for (const auto& item : produceItems) {
		cout << setw(11) << item.first << " " << string(item.second, '*') << endl;
	}

}