#pragma once

#include "Apartment.h"

class MonthlyRentalApartment : public Apartment
{
private:
	bool hasFurniture;

public:
	// Constructors
	MonthlyRentalApartment();
	MonthlyRentalApartment(int, int, int, int, bool);

	// Getter and setter
	void set_hasFurniture(bool);
	bool get_hasFurniture() const;

	// Method declarations
	void apt_details() override;
	void monthly_apt() override;
	void apartment_wRoom(int) override;
	void apartment_wSize(int) override;
	void apartment_cheaper(int, int) override;
	int rental_price(int);
	void not_found();
	int type() override;
	int specific_feature();
};