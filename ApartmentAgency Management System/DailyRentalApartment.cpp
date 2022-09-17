#include <iostream>
using namespace std;

#include "DailyRentalApartment.h"

// Method implementations of Daily Rental Apartment class

// Default constructor
DailyRentalApartment::DailyRentalApartment()
{
	decorationStyle = Minimalist;
}

// Parametrized constructor
DailyRentalApartment::DailyRentalApartment(int apartment_id, int no_of_rooms, int price, int size, apartType decorationStyle) : Apartment(apartment_id, no_of_rooms, price, size)
{
	this->decorationStyle = decorationStyle;
}

void DailyRentalApartment::set_decorationStyle(apartType decorationStyle)
{
	this->decorationStyle = decorationStyle;
}

apartType DailyRentalApartment::get_decorationStyle() const
{
	return decorationStyle;
}

// Getting enum variables as string
void DailyRentalApartment::get_decorationStyleName()
{
	switch (decorationStyle)
	{
	case 1:
		cout << "Minimalist" << endl;
		break;
	case 2:
		cout << "Modern" << endl;
		break;
	case 3:
		cout << "Classic" << endl;
		break;
	}
}

// Printing apartment details
void DailyRentalApartment::apt_details()
{
	cout << "Daily Rental Apartments:" << endl;
	Apartment::apt_details();
	cout << ", Decoration Style:";
	get_decorationStyleName();
}

void DailyRentalApartment::daily_apt()
{
	apt_details();
}

// Printing the apartment whose number of rooms is equal to the specified number
void DailyRentalApartment::apartment_wRoom(int room_no)
{
	if (no_of_rooms == room_no)
	{
		apt_details();
	}
	else
	{
		not_found();
	}
}

// Printing the apartment whose size is bigger than the specified size
void DailyRentalApartment::apartment_wSize(int size)
{
	if (this->size > size)
	{
		apt_details();
	}
	else
	{
		not_found();
	}
}

// Calculating the rental price for the specified days
int DailyRentalApartment::rental_price(int days)
{
	return (this->price * days);
}

// Printing the details of the apartment that can be rented with the specified price within the specified days
void DailyRentalApartment::apartment_cheaper(int price, int days)
{
	if (rental_price(days) < price)
	{
		apt_details();
	}
	else
	{
		not_found();
	}
}

// Printing the not found case
void DailyRentalApartment::not_found()
{
	cout << "Daily Rental Apartments:\nNot Found" << endl;
}

// Getting the type
int DailyRentalApartment::type()
{
	return 0;
}

// Getting the type specific attribute
int DailyRentalApartment::specific_feature()
{
	return decorationStyle;
}