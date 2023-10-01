#pragma once
#include <string>
#include <unordered_map>
class Item
{
private:
	std::string name;
	double price;

public:
	// Constructor
	Item();

	// Getters for name and price
	std::string getName() const;
	double getPrice() const;

	// Method to create and return a list of items and their prices.
	static std::unordered_map<std::string, double> createItemList();

};

