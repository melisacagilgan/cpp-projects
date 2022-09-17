#include <iostream>
using namespace std;

#include "Agency.h"
#include "DailyRentalApartment.h"
#include "MonthlyRentalApartment.h"

/*  All the building objects belongs to the agency object is kept both in the main function and inside
	the agency object to make the relationship betwen those objects aggregation while the relationship
	between each building and its apartments is composition, so if a building is deleted, its apartments
	will also be deleted. However, even though a building of the agency is deleted, since all buildings
	are kept in the main function as an array, its data will still exist. */

int main()
{
	int option;
	Agency agency("Manchester Comfort Apartments");
	Building *building_array[50];
	int building_number = 0;

	cout << "!!!Welcome to Agency Management System!!!\n"
			"---------------------------------------------\n"
			"Please select an operation\n"
			"1. Add a new building to the agency\n"
			"2. Add a new apartment(monthly or daily rental) to a building\n"
			"3. List all buildings with their addresses\n"
			"4. List all apartments available for the agency\n"
			"5. List all apartments that have the specified number of rooms\n"
			"6. List all apartments which are bigger than the specified apartment size\n"
			"7. List all apartments which are cheaper than the specified price in a specified number of days\n"
			"8. List all apartments that are either daily or monthly rental\n"
			"9. Calculate the price of a specific apartment in a specified number of days\n"
			"0. Exit"
		 << endl;
	do
	{
		cout << "---------------------------------------------" << endl;
		cout << "Your selection: ";
		cin >> option;
		if (option == 1)
		{
			int i = 0;
			char c;
			char *address = new char[100];
			cout << "What is the address of your building: ";

			c = cin.get();
			do
			{
				c = cin.get();
				if (c != '\n')
				{
					address[i++] = c;
				}
			} while (c != '\n');
			address[i] = '\0';

			building_array[building_number] = new Building(building_number, address);
			agency.add_building(*building_array[building_number]);
			cout << "The building is created with the id number " << building_array[building_number]->get_building_id() << "." << endl;
			building_number++;

			delete[] address;
		}
		else if (option == 2)
		{
			int building_id, type, apt_id, room_no, price, size, specific_feature, valid = 0;
			cout << "Which building you want to add apartment into?\nAvailable Buildings:" << endl;
			agency.buildings_details();

			do
			{
				cout << "Building id: ";
				cin >> building_id;
				for (int i = 0; i < agency.get_building_number(); i++)
				{
					if (!(agency.search_building_ids(building_id)))
					{
						cout << "Invalid building id! Please re-enter." << endl;
						valid = 0;
						break;
					}
					valid = 1;
				}
			} while (valid == 0);

			cout << "What is the type of the apartment?\n1. Daily Rental Apartment\n2. Monthly Rental Apartment\nType: ";
			cin >> type;

			if (type == 1) // Daily Rental Apartment
			{
				do
				{
					valid = 1;
					cout << "Enter apartment id: ";
					cin >> apt_id;
					if (agency.search_apt_ids(building_id, apt_id))
					{
						cout << "Apartment id already exists! Please re-enter." << endl;
						valid = 0;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter number of rooms: ";
					cin >> room_no;
					if (room_no <= 0)
					{
						cout << "Invalid room number! Please re-enter." << endl;
						valid = 0;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter rent(GBP): ";
					cin >> price;
					if (price <= 0)
					{
						cout << "Invalid price! Please re-enter." << endl;
						valid = 0;
						continue;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter size(m2): ";
					cin >> size;
					if (size <= 0)
					{
						cout << "Invalid size! Please re-enter." << endl;
						valid = 0;
						continue;
					}
				} while (valid == 0);

				do
				{
					cout << "Decoration Style:\n1. Minimalist\n2. Modern\n3. Classic" << endl;
					cout << "Your selection: ";
					cin >> specific_feature;
					if (specific_feature > 3 || specific_feature < 1)
					{
						cout << "Invalid selection! Please re-enter." << endl;
					}
				} while (specific_feature > 3 || specific_feature < 1);

				agency.add_apartment(apt_id, room_no, price, size, specific_feature, 0, building_id);
			}

			if (type == 2) // Monthly Rental Apartment
			{
				do
				{
					valid = 1;
					cout << "Enter apartment id: ";
					cin >> apt_id;
					if (agency.search_apt_ids(building_id, apt_id))
					{
						cout << "Apartment id already exists! Please re-enter." << endl;
						valid = 0;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter number of rooms: ";
					cin >> room_no;
					if (room_no <= 0)
					{
						cout << "Invalid room number! Please re-enter." << endl;
						valid = 0;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter rent(GBP): ";
					cin >> price;
					if (price <= 0)
					{
						cout << "Invalid price! Please re-enter." << endl;
						valid = 0;
						continue;
					}
				} while (valid == 0);

				do
				{
					valid = 1;
					cout << "Enter size(m2): ";
					cin >> size;
					if (size <= 0)
					{
						cout << "Invalid size! Please re-enter." << endl;
						valid = 0;
						continue;
					}
				} while (valid == 0);

				do
				{
					cout << "Furnished (Yes(1) / No (0)): ";
					cin >> specific_feature;
					if (specific_feature != 1 && specific_feature != 0)
					{
						cout << "Invalid selection! Please re-enter." << endl;
					}
				} while (specific_feature != 1 && specific_feature != 0);

				agency.add_apartment(apt_id, room_no, price, size, specific_feature, 1, building_id);
			}
			cout << "Apartment successfully added!" << endl;
		}
		else if (option == 3)
		{
			cout << "Buildings:" << endl;
			agency.buildings_details();
		}
		else if (option == 4)
		{
			agency.buildings_apartments();
		}
		else if (option == 5)
		{
			int room_no;
			cout << "Enter the specified room number: ";
			cin >> room_no;
			agency.apartment_wRoom(room_no);
		}
		else if (option == 6)
		{
			int size;
			cout << "Enter minimum size: ";
			cin >> size;
			agency.apartment_wSize(size);
		}
		else if (option == 7)
		{
			int price, days;
			cout << "Enter the price(GBP): ";
			cin >> price;
			cout << "Enter the days: ";
			cin >> days;
			agency.apartment_cheaper(price, days);
		}
		else if (option == 8)
		{
			int select;
			do
			{
				cout << "Enter Daily/Monthly Rental (0/1): ";
				cin >> select;
				agency.apts(select);

				if (select != 0 && select != 1)
				{
					cout << "Invalid selection! Please re-enter." << endl;
				}
			} while (select != 0 && select != 1);
		}
		else if (option == 9)
		{
			int building_id, apt_id, days, price;
			cout << "Available Buildings:" << endl;
			agency.buildings_details();
			if (agency.get_building_number() == 0)
			{
				continue;
			}
			do
			{
				cout << "Select Building: ";
				cin >> building_id;
				if (!(agency.search_building_ids(building_id)))
				{
					cout << "Invalid selection! Please re-enter." << endl;
				}
				else
				{
					cout << "Available apartments: " << endl;
					// Getting the building which has the specified building id
					building_array[building_id]->apts(-1);
					if (building_array[building_id]->get_apt_number() == 0)
					{
						break;
					}
					do
					{
						cout << "Enter Apartment id: ";
						cin >> apt_id;
						if (!(agency.search_apt_ids(building_id, apt_id)))
						{
							cout << "Invalid apartment id! Please re-enter." << endl;
						}
					} while (!(agency.search_apt_ids(building_id, apt_id)));
					cout << "Enter Number of Days: ";
					cin >> days;
					price = building_array[building_id]->rental_price(apt_id, days);
					cout << "The rent for your stay is " << price << " GBP!" << endl;
				}
			} while (!(agency.search_building_ids(building_id)));
		}
		else if (option == 0)
		{
			cout << "Thanks for choosing Agency Management System!" << endl;
		}
		else
		{
			cout << "Invalid option! Please re-enter." << endl;
		}
	} while (option != 0);

	return 0;
}