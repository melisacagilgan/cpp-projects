#include <iostream>
using namespace std;

#include "Apartment.h"

// Method implementations of Apartment class

// Default constructor
Apartment::Apartment()
{
	apartment_id = -1;
	no_of_rooms = -1;
	price = -1;
	size = -1;
}

// Parametrized constructor
Apartment::Apartment(int apartment_id, int no_of_rooms, int price, int size)
{
	this->apartment_id = apartment_id;
	this->no_of_rooms = no_of_rooms;
	this->price = price;
	this->size = size;
}

void Apartment::set_apartment_id(int apartment_id)
{
	this->apartment_id = apartment_id;
}

int Apartment::get_apartment_id() const
{
	return apartment_id;
}

void Apartment::set_no_of_rooms(int no_of_rooms)
{
	this->no_of_rooms = no_of_rooms;
}

int Apartment::get_no_of_rooms() const
{
	return no_of_rooms;
}

void Apartment::set_price(int price)
{
	this->price = price;
}

int Apartment::get_price() const
{
	return price;
}

void Apartment::set_size(int size)
{
	this->size = size;
}

int Apartment::get_size() const
{
	return size;
}

// Printing apartment details
void Apartment::apt_details()
{
	cout << "Apartment id:" << get_apartment_id() << ", Number of Rooms:" << get_no_of_rooms() << ", Rent:" << get_price() << " GBP, Size:" << get_size();
}

// Searching whether the set apartment id already exists or not
bool Apartment::search_apt_id(int id)
{
	if (apartment_id == id)
	{
		return true;
	}
	return false;
}

// Printing the apartment whose number of rooms is equal to the specified number
void Apartment::apartment_wRoom(int room_no)
{
	if (no_of_rooms == room_no)
	{
		apt_details();
	}
}

// Printing the apartment whose size is bigger than the specified size
void Apartment::apartment_wSize(int size)
{
	if (this->size > size)
	{
		apt_details();
	}
}

// Calculating the rental price for the specified days
int Apartment::rental_price(int days)
{
	return (this->price * days);
}

// Printing the details of the apartment that can be rented with the specified price within the specified days
void Apartment::apartment_cheaper(int price, int days)
{
	if (rental_price(days) < price)
	{
		apt_details();
	}
}

// Printing the details of an apartment based on its type
void Apartment::daily_apt()
{
}
void Apartment::monthly_apt()
{
}
int Apartment::type()
{
	return -1;
}
int Apartment::specific_feature()
{
	return -1;
}