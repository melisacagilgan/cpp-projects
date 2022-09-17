#pragma once

#include "Building.h"

class Agency
{
private:
	char *name;
	int building_number;
	Building *buildings[50];

public:
	// Constructors
	Agency();
	Agency(const char *);
	Agency(const Agency &);
	void operator=(const Agency &);
	~Agency();

	// Getters and setters
	void set_name(const char *);
	char *get_name() const;
	void set_building_number(int);
	int get_building_number() const;

	// Method declarations
	void add_building(Building &);
	void add_apartment(int, int, int, int, int, int, int);
	bool search_building_ids(int);
	bool search_apt_ids(int, int);
	void buildings_wAddress();
	void buildings_details();
	void buildings_apartments();
	void apartment_wRoom(int);
	void apartment_wSize(int);
	int rental_price(int, int);
	void apartment_cheaper(int, int);
	void apts(int);
	void not_initialized();
};
