#pragma once
#include <string>
#include <unordered_map>
#include <vector>
class Cart
{
private:
	// Create variables to keep track of cart data.
	struct CartItem
	{
		int quantity;
		double price;
	};
	double total;
	std::unordered_map<std::string, CartItem> cart;
	std::unordered_map<std::string, double> prices;


public:
	// Constructor
	Cart();

	// Add an item to the shopping cart.
	void addItem(const std::string& item, int quantity, double price);

	// Remove an item from the cart.
	void removeItem(const std::string& item, int quantity);

	// Display the contents of the cart.
	void displayCart();

	// Add the item(s) cost to the total.
	void addCost(int quantity, double cost);

	// Remove the item(s) cost from the total.
	void subtractCost(int quantity, double cost);

	// Check if the cart is empty.
	bool isEmpty() const;

	// Check for an item within the cart.
	bool containsItem(const std::string& item) const;

	// Get cart contents for the purpose of saving them.
	std::vector<std::string> getCartContents() const;

};