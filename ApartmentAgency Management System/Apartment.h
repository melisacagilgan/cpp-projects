#pragma once

class Apartment
{
protected:
	int apartment_id;
	int no_of_rooms;
	int price;
	int size;

public:
	// Constructors
	Apartment();
	Apartment(int, int, int, int);

	// Getters and setters
	void set_apartment_id(int);
	int get_apartment_id() const;
	void set_no_of_rooms(int);
	int get_no_of_rooms() const;
	void set_price(int);
	int get_price() const;
	void set_size(int);
	int get_size() const;

	// Method declarations
	bool search_apt_id(int);
	virtual void apt_details();
	virtual void daily_apt();
	virtual void monthly_apt();
	virtual void apartment_wRoom(int);
	virtual void apartment_wSize(int);
	virtual int rental_price(int);
	virtual void apartment_cheaper(int, int);
	virtual int type();
	virtual int specific_feature();
};
