#include <iostream>
using namespace std;

#include "Agency.h"

// Method implementations of Agency class

// Default constructor
Agency::Agency()
{
	name = new char[strlen("Not provided") + 1];
	strcpy(name, "Not provided");
	name[strlen("Not provided")] = '\0';

	building_number = 0;

	for (int i = 0; i < 50; i++)
	{
		this->buildings[i] = NULL;
	}
}

// Parametrized constructor
Agency::Agency(const char *name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';

	this->building_number = 0;

	for (int i = 0; i < 50; i++)
	{
		this->buildings[i] = NULL;
	}
}

// Copy constructor
Agency::Agency(const Agency &a)
{
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->name[strlen(a.name)] = '\0';

	this->building_number = a.building_number;

	for (int i = 0; i < building_number; i++)
	{
		this->buildings[i] = a.buildings[i];
	}
}

// Operator overloading
void Agency::operator=(const Agency &a)
{
	// Deleting the heap members
	delete[] this->name;

	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);
	this->name[strlen(a.name)] = '\0';

	this->building_number = a.building_number;

	for (int i = 0; i < building_number; i++)
	{
		this->buildings[i] = a.buildings[i];
	}
}

// Destructor
Agency::~Agency()
{
	delete[] name;
}

void Agency::set_name(const char *name)
{
	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';
}

char *Agency::get_name() const
{
	return Agency::name;
}

void Agency::set_building_number(int building_number)
{
	this->building_number = building_number;
}

int Agency::get_building_number() const
{
	return building_number;
}

// Adding a building to the agency
void Agency::add_building(Building &building)
{
	if (this->building_number == 50)
	{
		cout << "Building capacity is full!" << endl;
	}
	else
	{
		this->buildings[this->building_number++] = &building;
	}
}

// Adding an apartment to the building
void Agency::add_apartment(int apt_id, int room_no, int price, int size, int specific_feature, int type, int building_id)
{
	for (int i = 0; i < building_number; i++)
	{
		if (buildings[i]->get_building_id() == building_id)
		{
			buildings[i]->add_apartment(apt_id, room_no, price, size, specific_feature, type);
		}
	}
}

// Searching whether the set building id already exists or not
bool Agency::search_building_ids(int id)
{
	for (int i = 0; i < building_number; i++)
	{
		if (buildings[i]->search_building_id(id) == true)
		{
			return true;
		}
	}
	return false;
}

// Searching whether the set apartment id already exists or not
bool Agency::search_apt_ids(int building_id, int id)
{
	for (int i = 0; i < this->building_number; i++)
	{
		if (buildings[i]->get_building_id() == building_id)
		{
			return buildings[i]->search_apt_ids(id);
		}
	}
	return false;
}

// Printing the buildings with its addresses only
void Agency::buildings_wAddress()
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->building_wAddress();
	}
}

// Printing the buildings' details
void Agency::buildings_details()
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->building_details();
	}
}

// Printing the buildings' details with their apartments' details
void Agency::buildings_apartments()
{
	not_initialized();
	if (building_number != 0)
	{
		cout << "Available Buildings:" << endl;
	}
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->building_apartments();
	}
}

// Printing the apartment whose number of rooms is equal to the specified number
void Agency::apartment_wRoom(int room_no)
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->apartment_wRoom(room_no);
	}
}

// Printing the apartment whose size is bigger than the specified size
void Agency::apartment_wSize(int size)
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->apartment_wSize(size);
	}
}

// Calculating the rental price of the apartment with the given id for the specified days
int Agency::rental_price(int id, int days)
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->rental_price(id, days);
	}
	return 0;
}

// Printing the details of the apartment that can be rented with the specified price within the specified days
void Agency::apartment_cheaper(int price, int days)
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->apartment_cheaper(price, days);
	}
}

// Printing the details of the apartments based on the selection integer
void Agency::apts(int select)
{
	not_initialized();
	for (int i = 0; i < building_number; i++)
	{
		buildings[i]->apts(select);
	}
}

// Printing the not initialized case
void Agency::not_initialized()
{
	if (building_number == 0)
	{
		cout << "Not Found! First, you have to add a building." << endl;
	}
}