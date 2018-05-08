// shoppingCart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void removeItemFromCart();
bool weighItem = false;
bool itemsInCart();
double scanItem();
double itemWeight();
bool taxable = false;
double unitPrice = 0;
double subTotal = 0;
double runningTotal = 0;

int main()
{
	double subTotal = 0;

	do
	{
		removeItemFromCart();

		if (weighItem == true)
		{
			itemWeight();
		}
		else
		{
			scanItem();
		}
		if (taxable == true)
		{
			subTotal = unitPrice * 1.13;
		}
		else
		{
			subTotal = unitPrice;
		}

		runningTotal = runningTotal + subTotal;
		cout << runningTotal << endl;
	} while (itemsInCart() == true);
	cout << "Your total is: $" << runningTotal << endl;

	return 0;
}

bool itemsInCart()
{
	bool moreItems = true;
	char choice = 'y';

	cout << "More items in cart(y/n)?" << endl;
	cin >> choice;

	if (choice == 'y')
	{
		moreItems = true;
	}
	else
	{
		moreItems = false;
	}
	return moreItems;
}

void removeItemFromCart()
{
	char isWeighed;

	cout << "The item is removed from the cart" << endl;
	cout << "Does the item need to be weighed(y/n)?" << endl;
	cin >> isWeighed;

	if (isWeighed == 'y')
	{
		weighItem = true;
	}
	else
	{
		weighItem = false;
	}
}

double scanItem()
{
	char taxableItem;
	char drinkCont;

	cout << "Enter the price of item:" << endl;
	cin >> unitPrice;

	cout << "Is the item a drink container? (y/n)" << endl;

	cin >> drinkCont;

	if (drinkCont == 'y')
	{
		unitPrice += 0.05;
		cout << "There will be an additional charge of $0.05 added to this item for environmental reasons" << endl;
	}

	cout << "Is the item taxable? (y/n)" << endl;

	cin >> taxableItem;

	if (taxableItem == 'y')
	{
		taxable = true;
	}
	else
	{
		taxable = false;
	}
	return unitPrice;
}

double itemWeight()
{
	char taxableItem;
	double weight;
	double price;

	cout << "Enter the weight of item:" << endl;

	cin >> weight;

	cout << "Enter the price of the item:" << endl;

	cin >> price;

	unitPrice = weight * price;

	cout << "Is the item taxable? (y/n)" << endl;

	cin >> taxableItem;

	if (taxableItem == 'y')
	{
		taxable = true;
	}
	else
	{
		taxable = false;
	}
	return unitPrice;
}