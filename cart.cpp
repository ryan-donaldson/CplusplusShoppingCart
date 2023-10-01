#include "cart.h"
#include <iostream>

// Intialize the class's variables to empty values
Cart::Cart() : total(0.0)
{

}

// addItem functionality.
void Cart::addItem(const std::string& item, int quantity, double price)
{
	cart[item] = {quantity, price};
	prices[item] = price;
}

// removeItem functionality.
void Cart::removeItem(const std::string& item, int quantity)
{
	cart[item].quantity -= quantity;

	if (cart[item].quantity <= 0)
	{
		cart.erase(item);
	}
	
}

// displayCart functionality.
void Cart::displayCart()
{
	std::cout << "Cart Contents: " << std::endl;
	for (const auto& cartItem : cart)
	{
		// Setup variables for displaying them later.
		const std::string& item = cartItem.first;
		int quantity = cartItem.second.quantity;
		double price = prices[item];
		double itemCost = quantity * price;

		std::cout << item << " - Quantity: " << quantity << " - Price per unit: $" << price << std::endl;
	}

	std::cout << "Total Cost: $" << total << std::endl;
}

// addCost functionality.
void Cart::addCost(int quantity, double cost)
{
	total += quantity * cost;
}

// subtractCost functionality.
void Cart::subtractCost(int quantity, double cost)
{
	total -= quantity * cost;
}

// Determine if the cart is empty or not.
bool Cart::isEmpty() const
{
	return cart.empty();
}

// Determine if an item is in the cart.
bool Cart::containsItem(const std::string& item) const
{
	return cart.find(item) != cart.end();
}

// Get the contents of the cart.
std::vector<std::string> Cart::getCartContents() const
{
	std::vector<std::string> contents;

	// Loop through the items in the cart, convert them to a string and add them to the list.
	for (const auto& cartItem : cart)
	{
		const std::string& item = cartItem.first;
		int quantity = cartItem.second.quantity;
		double price = cartItem.second.price;
		std::string itemString = item + "," + std::to_string(quantity) + "," + std::to_string(price);
		contents.push_back(itemString);
	}
	
	// Return contents.
	return contents;
}
