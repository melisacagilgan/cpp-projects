#pragma once

#include "Apartment.h"

enum apartType
{
	Minimalist = 1,
	Modern = 2,
	Classic = 3
};

class DailyRentalApartment : public Apartment
{
private:
	apartType decorationStyle;

public:
	// Constructors
	DailyRentalApartment();
	DailyRentalApartment(int, int, int, int, apartType);

	// Getter and setter
	void set_decorationStyle(apartType);
	apartType get_decorationStyle() const;

	// Method declarations
	void get_decorationStyleName();
	void apt_details() override;
	void daily_apt() override;
	void apartment_wRoom(int) override;
	void apartment_wSize(int) override;
	void apartment_cheaper(int, int) override;
	int rental_price(int);
	void not_found();
	int type() override;
	int specific_feature();
};