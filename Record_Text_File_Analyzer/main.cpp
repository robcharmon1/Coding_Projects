/*
* Program to determine number of each produce item purchased from store and allow user to see quantity of items purchased in different formats
* Author: Robert Harmon
* Date: 2/19/23
*/

#include <iostream>
#include "DailyProducePurchased.h"
using namespace std;

int main() {

	int userInput; // declare variable for user input menu choices

	DailyProducePurchased produceToday; // declare new object of DailyProducePurchased class

	produceToday.ReadDataToMap();     // call object function to read input file and add to a map
	produceToday.WriteDataToFile();   // call object function to write data from map to a .dat file
	produceToday.OutputMenu();        // call object function to output menuoptions for user
	produceToday.GetInput(userInput); // call object function to get user input
	
	while (userInput != 4) {
		// call object function for choice 1
		if (userInput == 1) {
			produceToday.PrintValueOfItem();
			cout << endl;
		}
		// call object function for choice 2
		else if (userInput == 2) {
			produceToday.PrintValueList();
			cout << endl;
		}
		// call object function for choice 3
		else if (userInput == 3) {
			produceToday.PrintValueHistogram();
			cout << endl;
		}

		produceToday.OutputMenu();        // print menu again
		produceToday.GetInput(userInput); // call object function to get user input

	}

	cout << "Exiting program";

	return 0;
}