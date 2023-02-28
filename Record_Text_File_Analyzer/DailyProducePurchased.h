/*
* Header file for daily produce purchased class declaring all functions to be used
* See DailyProducePurchased.cpp for function definitions and explanations
* Author: Robert Harmon
* Date: 2/19/23
*/

#pragma once
#ifndef DailyProducePurchased_H_
#define DailyProducePurchased_H_
#include <map>
#include <string>

class DailyProducePurchased {
public:
	void ReadDataToMap();
	void WriteDataToFile();
	void OutputMenu();
	int GetInput(int& userInput);
	void PrintValueOfItem();
	void PrintValueList();
	void PrintValueHistogram();

private:
	std::map<std::string, int> produceItems; // map to hold produce items as keys and ammount purchased as values
};

#endif // DailyProducePurchased_H_
