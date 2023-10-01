// program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "cart.h"
#include "Item.h"
#include <unordered_map>

// Create function to save cart data to a file.
void saveCartToFile(const Cart& cart, const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        std::vector<std::string> cartContents = cart.getCartContents();
        for (const std::string& itemString : cartContents)
        {
            file << itemString << std::endl;
        }
        file.close();
        std::cout << "Cart contents saved to: " << filename << std::endl;       
    }
    else
    {
        std::cerr << "Error: Unable to write to file." << std::endl;
    }


}

// Create function to load cart from file.
void loadCartFromFile(Cart& cart, const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string item, quantityStr, priceStr;

        while (std::getline(file, item, ',') && std::getline(file, quantityStr, ',') && std::getline(file, priceStr))
        {
            int quantity = std::stoi(quantityStr);
            double price = std::stod(priceStr);
            cart.addItem(item, quantity, price);
            cart.addCost(quantity, price);
        }

        file.close();
        std::cout << "Cart contents loaded from: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

int main()
{
    // Instantiate the needed classes.
    Cart myCart;
    Item item;

    // Welcome the user to the program and direct them how to begin.
    std::cout << "Welcome to the Shopping Cart program!" << std::endl;
    std::cout << "Choose an option below to get started." << std::endl;

    // Begin a loop which will keep the programming running until the user chooses to quit.
    int option = -1;
    while (option != 0)
    {   
        // Begin by displaying the menu options.
        std::cout << std::endl;
        std::cout << "Shopping Cart Menu Items: " << std::endl;
        std::cout << "0. Quit the program" << std::endl;
        std::cout << "1. See items for sale" << std::endl;
        std::cout << "2. Display cart contents" << std::endl;
        std::cout << "3. Add item to cart" << std::endl;
        std::cout << "4. Remove item from cart" << std::endl;
        std::cout << "5. Save cart contents to a file" << std::endl;
        std::cout << "6. Load cart contents from a file" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> option;
        
        // Determine what happens based on the user's input.
        if (option == 1)
        {
            std::cout << std::endl;

            // Access and display the item list.
            std::unordered_map<std::string, double> itemList = item.createItemList();
            for (const auto& itemPair : itemList)
            {
                std::cout << "Name: " << itemPair.first << " - Price: $" << itemPair.second << std::endl;
            }
        }
        else if (option == 2)
        {
            // Display the contents of the cart.
            myCart.displayCart();
        }
        else if (option == 3)
        {
            // Get the list of items to reference the prices of the items.
            std::unordered_map<std::string, double> itemList = item.createItemList();

            // Set variables for the user to fill, which will then be added to the cart.
            std::string itemName;
            double price;
            int quantity;

            // Ask the user what they want to add.
            std::cout << "What is the name of the item you would like to add? ";
            std::cin.ignore();
            std::getline(std::cin, itemName);

            // Determine if the desired item is a valid item.
            auto itemExist = itemList.find(itemName);
            if (itemExist != itemList.end())
            {
                // Set price value based on the itemName provided by the user; the name is they key, price is the value
                price = itemExist->second;

                // Ask the user how many of the desired item they want.
                std::cout << "How many would you like to add? ";
                std::cin >> quantity;
                std::cout << std::endl;

                // Add the desired item and quantity to the cart and the cost to the total.
                myCart.addItem(itemName, quantity, price);
                myCart.addCost(quantity, price);

                std::cout << "Item(s) added." << std::endl;
            }
            else
            {
                // Tell the user that item is not available.
                std::cout << "Item not found in items available for purchase." << std::endl;
            }
        }
        else if (option == 4)
        {
            if (myCart.isEmpty())
            {
                // Tell the user that the cart is empty.
                std::cout << "There are no items to remove, the cart is empty." << std::endl;
            }
            else
            {
                // Get the list of items to reference the prices of the items.
                std::unordered_map<std::string, double> itemList = item.createItemList();

                // Set variables for the user to fill, which will then be removed from the cart.
                std::string itemName;
                double price;
                int quantity;

                // Ask the user what they want to remove.
                std::cout << "What is the name of the item you would like to remove? ";
                std::cin.ignore();
                std::getline(std::cin, itemName);
                
                // If the desired item is in the cart:
                if (myCart.containsItem(itemName))
                {
                    auto itemExist = itemList.find(itemName);
                    price = itemExist->second;

                    // Ask the user how many of that item they want to remove.
                    std::cout << "How many would you like to remove? ";
                    std::cin >> quantity;
                    std::cout << std::endl;

                    // Remove the desired item and quantity from the cart, and the cost from the total.
                    myCart.removeItem(itemName, quantity);
                    myCart.subtractCost(quantity, price);

                    std::cout << "Item(s) removed." << std::endl;
                }
                else
                {
                    // Tell the user the item they tried to remove is not in the cart.
                    std::cout << "Item not found in the cart." << std::endl;
                }
            } 
        }
        else if (option == 5)
        {
            // Create a variable to hold the filename we will save the cart to.
            std::string fileName;

            // Prompt the user for the filename.
            std::cout << "What is the name of the file you want to save to? ";
            std::cin >> fileName;

            // Save to cart to the file.
            saveCartToFile(myCart, fileName);
        }
        else if (option == 6)
        {
            // Create a variable to hold the filename we will read from.
            std::string fileName;

            // Prompt the user for the filename.
            std::cout << "What is the name of the file you want to load from? ";
            std::cin >> fileName;

            // Read from the file with that name.
            loadCartFromFile(myCart, fileName);
        }
        else
        {
            // Tell the user they must enter a valid menu option.
            std::cout << "Please enter a valid option." << std::endl;

        }
    }
}

