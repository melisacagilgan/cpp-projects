#include <iostream>
using namespace std;

#include "Building.h"

// Method implementations of Building class

// Default constructor
Building::Building()
{
	building_id = -1;

	address = new char[strlen("Not provided") + 1];
	strcpy(address, "Not provided");
	address[strlen("Not provided")] = '\0';

	apt_number = 0;

	for (int i = 0; i < 50; i++)
	{
		this->apartments[i] = NULL;
	}
}

// Parametrized constructor
Building::Building(int building_id, char *address)
{
	this->building_id = building_id;

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
	this->address[strlen(address)] = '\0';

	this->apt_number = 0;

	for (int i = 0; i < 50; i++)
	{
		this->apartments[i] = NULL;
	}
}

// Copy constructor
Building::Building(const Building &b)
{
	this->building_id = b.building_id;

	this->address = new char[strlen(b.address) + 1];
	strcpy(this->address, b.address);
	this->address[strlen(b.address)] = '\0';

	this->apt_number = b.apt_number;

	for (int i = 0; i < 50; i++)
	{
		this->apartments[i] = b.apartments[i];
	}
}

// Operator overloading
void Building::operator=(const Building &b)
{
	// Deleting heap members
	delete[] this->address;
	for (int i = 0; i < 50; i++)
	{
		delete this->apartments[i];
	}

	this->building_id = b.building_id;

	this->address = new char[strlen(b.address) + 1];
	strcpy(this->address, b.address);
	this->address[strlen(b.address)] = '\0';

	this->apt_number = b.apt_number;

	for (int i = 0; i < apt_number; i++)
	{
		int apartment_id = b.apartments[i]->get_apartment_id();
		int no_of_rooms = b.apartments[i]->get_no_of_rooms();
		int price = b.apartments[i]->get_price();
		int size = b.apartments[i]->get_size();

		if (b.apartments[i]->type() == 0) // Daily Rental Apartment
		{
			int specific_feature = b.apartments[i]->specific_feature();
			DailyRentalApartment *daily_apt = new DailyRentalApartment(apartment_id, no_of_rooms, price, size, apartType(specific_feature));
			this->apartments[i] = daily_apt;
		}
		else // Monthly Rental Apartment
		{
			bool specific_feature = b.apartments[i]->specific_feature();
			MonthlyRentalApartment *daily_apt = new MonthlyRentalApartment(apartment_id, no_of_rooms, price, size, specific_feature);
		}
	}
}

// Destructor
Building::~Building()
{
	delete[] address;
	for (int i = 0; i < apt_number; i++)
	{
		delete this->apartments[i];
	}
}

void Building::set_building_id(int building_id)
{
	this->building_id = building_id;
}

int Building::get_building_id() const
{
	return building_id;
}

void Building::set_address(const char *address)
{
	delete[] this->address;

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
	this->address[strlen(address)] = '\0';
}

char *Building::get_address() const
{
	return address;
}

void Building::set_apt_number(int apt_number)
{
	this->apt_number = apt_number;
}

int Building::get_apt_number() const
{
	return apt_number;
}

// Adding an apartment to the building
void Building::add_apartment(int apt_id, int room_no, int price, int size, int specific_feature, int type)
{
	if (this->apt_number == 50)
	{
		cout << "Apartment capacity is full!" << endl;
	}
	else
	{
		if (type == 0) // Daily Rental Apartment
		{
			DailyRentalApartment *daily_apt = new DailyRentalApartment(apt_id, room_no, price, size, apartType(specific_feature));
			this->apartments[this->apt_number++] = daily_apt;
		}
		else // Monthly Rental Apartment
		{
			MonthlyRentalApartment *monthly_apt = new MonthlyRentalApartment(apt_id, room_no, price, size, (bool)specific_feature);
			this->apartments[this->apt_number++] = monthly_apt;
		}
	}
}

// Searching whether the set building id already exists or not
bool Building::search_building_id(int id)
{
	if (building_id == id)
	{
		return true;
	}
	return false;
}

// Searching whether the set apartment id already exists or not
bool Building::search_apt_ids(int id)
{
	for (int i = 0; i < this->apt_number; i++)
	{
		return apartments[i]->search_apt_id(id);
	}
	return false;
}

// Printing the building with its address only
void Building::building_wAddress()
{
	cout << "Address: " << address << endl;
}

// Printing the building details
void Building::building_details()
{
	cout << "ID: " << building_id << " ";
	building_wAddress();
}

// Printing the building details with its apartments' details
void Building::building_apartments()
{
	cout << "In Building: ID: " << this->building_id << ", Address: " << this->address << endl;
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		apartments[i]->apt_details();
	}
}

// Printing the apartment whose number of rooms is equal to the specified number
void Building::apartment_wRoom(int room_no)
{
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		apartments[i]->apartment_wRoom(room_no);
	}
}

// Printing the apartment whose size is bigger than the specified size
void Building::apartment_wSize(int size)
{
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		apartments[i]->apartment_wSize(size);
	}
}

// Calculating the rental price of the apartment with the given id for the specified days
int Building::rental_price(int id, int days)
{
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		if (apartments[i]->get_apartment_id() == id)
		{
			return apartments[i]->rental_price(days);
		}
	}
	return 0;
}

// Printing the details of the apartment that can be rented with the specified price within the specified days
void Building::apartment_cheaper(int price, int days)
{
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		apartments[i]->apartment_cheaper(price, days);
	}
}

// Printing the details of the apartments based on the selection integer
void Building::apts(int select)
{
	not_initialized();
	for (int i = 0; i < apt_number; i++)
	{
		if (select == 0)
		{
			apartments[i]->daily_apt();
		}
		else if (select == 1)
		{
			apartments[i]->monthly_apt();
		}
		else
		{
			apartments[i]->apt_details();
		}
	}
}

// Printing the not initialized case
void Building::not_initialized()
{
	if (apt_number == 0)
	{
		cout << "Not Found! First, you have to add a daily or monthly rental apartment." << endl;
	}
}