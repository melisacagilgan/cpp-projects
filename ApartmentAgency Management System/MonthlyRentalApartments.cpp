#include <iostream>
using namespace std;

#include "MonthlyRentalApartment.h"

// Method implementations of Monthly Rental Apartment class

// Default constructor
MonthlyRentalApartment::MonthlyRentalApartment()
{
	hasFurniture = false;
}

// Parametrized constructor
MonthlyRentalApartment::MonthlyRentalApartment(int apartment_id, int no_of_rooms, int price, int size, bool hasFurniture) : Apartment(apartment_id, no_of_rooms, price, size)
{
	this->hasFurniture = hasFurniture;
}

void MonthlyRentalApartment::set_hasFurniture(bool hasFurniture)
{
	this->hasFurniture = hasFurniture;
}

bool MonthlyRentalApartment::get_hasFurniture() const
{
	return this->hasFurniture;
}

// Printing apartment details
void MonthlyRentalApartment::apt_details()
{
	cout << "Monthly Rental Apartments:" << endl;
	Apartment::apt_details();
	cout << ", Furnished:";
	if (this->hasFurniture == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

void MonthlyRentalApartment::monthly_apt()
{
	apt_details();
}

// Printing the apartment whose number of rooms is equal to the specified number
void MonthlyRentalApartment::apartment_wRoom(int room_no)
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
void MonthlyRentalApartment::apartment_wSize(int size)
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
int MonthlyRentalApartment::rental_price(int days)
{
	int month_count = 0;
	while (days > 0)
	{
		days /= 30;
		month_count++;
	}
	return (this->price * (month_count + 1));
}

// Printing the details of the apartment that can be rented with the specified price within the specified days
void MonthlyRentalApartment::apartment_cheaper(int price, int days)
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
void MonthlyRentalApartment::not_found()
{
	cout << "Monthly Rental Apartments:\nNot Found" << endl;
}

// Getting the type
int MonthlyRentalApartment::type()
{
	return 1;
}

// Getting the type specific attribute
int MonthlyRentalApartment::specific_feature()
{
	return hasFurniture;
}