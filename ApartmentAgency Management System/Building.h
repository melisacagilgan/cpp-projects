#pragma once

#include "DailyRentalApartment.h"
#include "MonthlyRentalApartment.h"

class Building
{
private:
	int building_id;
	char *address;
	int apt_number;
	Apartment *apartments[50];

public:
	// Constructors
	Building();
	Building(int, char *);
	Building(const Building &);
	void operator=(const Building &);
	~Building();

	// Getters and setters
	void set_building_id(int);
	int get_building_id() const;
	void set_address(const char *);
	char *get_address() const;
	void set_apt_number(int);
	int get_apt_number() const;

	// Method declarations
	void add_apartment(int, int, int, int, int, int);
	bool search_building_id(int);
	bool search_apt_ids(int);
	void building_wAddress();
	void building_details();
	void building_apartments();
	void apartment_wRoom(int);
	void apartment_wSize(int);
	int rental_price(int, int);
	void apartment_cheaper(int, int);
	void apts(int);
	void not_initialized();
};