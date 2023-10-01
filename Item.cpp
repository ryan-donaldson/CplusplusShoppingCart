#include "Item.h"
#include <unordered_map>
// Define the constructor and put into it the list of items.
Item::Item()
{
}
// Define getters
std::string Item::getName() const
{
	return name;
}
double Item::getPrice() const
{
	return price;
}
// Define the method for creating the list of items.
std::unordered_map<std::string, double> Item::createItemList()
{
	std::unordered_map<std::string, double> itemList;

	// Add items and prices to the list.
	itemList["Popsicle"] = 2.99;
	itemList["Ice Cream Sandwich"] = 4.99;
	itemList["Block of Fudge"] = 6.99;
	itemList["Snowcone"] = 1.99;
	itemList["Brownie"] = 3.99;

	return itemList;
}

