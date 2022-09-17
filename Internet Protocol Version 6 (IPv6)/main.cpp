#include "Address.h"

int main()
{
	char *select = new char[10];
	int valid, i, j;
	char *tempAdd = new char[500];
	char *hex = new char[33];
	char *bin = new char[129];
	hex[32] = NULL;
	bin[128] = NULL;

	//	Test IP_1:	1080:0012:3456:789A:0008:0800:200C:417A
	//	Test IP_2:	2080:00FE:3456:789A:FEDC:BA98:7654:3210

	// Initial
	cout << "\n----------------------------------------\nCNG 242 Assignment 3" << endl
		 << "Melisa Cagilgan - 2328755\nWelcome to my solution for assignment 3\n----------------------------------------\n\n----------------------------------------\n";
	cout << "For A1:\nPlease enter Address in Hexadecimal seperated with ':' every 4 digits:\n";
	do
	{
		valid = 1;
		cin >> tempAdd;
		if (strlen(tempAdd) != 39)
		{
			cout << "\nInvalid input! Length of input must be 39 characters!\nPlease re-enter:\n";
			valid = 0;
		}
		else
		{
			for (i = 0; i < 39;)
			{
				if (('A' <= tempAdd[i] && tempAdd[i] <= 'F') || ('0' <= tempAdd[i] && tempAdd[i] <= '9') || tempAdd[i] == ':')
				{
					i++;
				}
				else
				{
					cout << "\nInvalid input! Please only use: 0-9, A-F characters!\nPlease re-enter:\n";
					valid = 0;
					break;
				}
			}
		}
	} while (valid == 0);

	for (i = 0, j = 0; tempAdd[i];)
	{
		if (tempAdd[i] != ':')
		{
			hex[j] = tempAdd[i];
			j++;
			i++;
		}
		else
		{
			i++;
		}
	}

	for (i = 0, j = 0; hex[i]; i++, j += 4) // Hexadecimal to binary conversion
	{
		if (hex[i] == '0')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '1')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == '2')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == '3')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == '4')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '5')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == '6')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == '7')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == '8')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '9')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'A')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'B')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'C')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'D')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'E')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'F')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
	}
	Address A1(hex, bin);
	cout << "\nSuccessfully created!\n----------------------------------------\n\n----------------------------------------\n";

	cout << "For A2:\nPlease enter Address in Hexadecimal seperated with ':' every 4 digits:\n";
	do
	{
		valid = 1;
		cin >> tempAdd;
		if (strlen(tempAdd) != 39)
		{
			cout << "\nInvalid input! Length of input must be 39 characters!\nPlease re-enter:\n";
			valid = 0;
		}
		else
		{
			for (i = 0; i < 39;)
			{
				if (('A' <= tempAdd[i] && tempAdd[i] <= 'F') || ('0' <= tempAdd[i] && tempAdd[i] <= '9') || tempAdd[i] == ':')
				{
					i++;
				}
				else
				{
					cout << "\nInvalid input! Please only use: 0-9, A-F characters!\nPlease re-enter:\n";
					valid = 0;
					break;
				}
			}
		}
	} while (valid == 0);

	for (i = 0, j = 0; tempAdd[i];)
	{
		if (tempAdd[i] != ':')
		{
			hex[j] = tempAdd[i];
			j++;
			i++;
		}
		else
		{
			i++;
		}
	}

	for (i = 0, j = 0; hex[i]; i++, j += 4) // Hexadecimal to binary conversion
	{
		if (hex[i] == '0')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '1')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == '2')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == '3')
		{
			bin[j] = '0';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == '4')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '5')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == '6')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == '7')
		{
			bin[j] = '0';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == '8')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == '9')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'A')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'B')
		{
			bin[j] = '1';
			bin[j + 1] = '0';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'C')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'D')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '0';
			bin[j + 3] = '1';
		}
		if (hex[i] == 'E')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '0';
		}
		if (hex[i] == 'F')
		{
			bin[j] = '1';
			bin[j + 1] = '1';
			bin[j + 2] = '1';
			bin[j + 3] = '1';
		}
	}
	Address A2(hex, bin);
	cout << "\nSuccessfully created!\n----------------------------------------\n\n----------------------------------------\n";

	do
	{
		cout << "a.Change Address of A1" << endl;
		cout << "b.Change Address of A2" << endl;
		cout << "1. Print result of classification" << endl;
		cout << "2. Print TLA ID" << endl;
		cout << "3. Print NLA ID" << endl;
		cout << "4. Print SLA ID" << endl;
		cout << "5. Bitwise disjunction" << endl;
		cout << "6. Bitwise conjuction" << endl;
		cout << "7. Bitwise NOR" << endl;
		cout << "8. Bitwise NAND" << endl;
		cout << "9. Bitwise XOR" << endl;
		cout << "10. Bitwsse XNOR" << endl;
		cout << "11.Copy contents of first address to another" << endl;
		cout << "12. Compare if A1 == A2" << endl;
		cout << "13. Compare if A1 != A2" << endl;
		cout << "14. Print Address" << endl;
		cout << "15.Enter an Address" << endl;
		cout << "0. Exit" << endl;

		do
		{
			cout << "\nPlease select: ";
			cin >> select;
			if (strlen(select) == 1)
			{
				if (select[0] == 'a' || select[0] == 'b' || select[0] == '0' || select[0] == '1' || select[0] == '2' || select[0] == '3' || select[0] == '4' || select[0] == '5' || select[0] == '6' || select[0] == '7' || select[0] == '8' || select[0] == '9')
				{
					valid = 1;
				}
				else
				{
					valid = 0;
				}
			}
			if (strlen(select) == 2)
			{
				if (select[0] == '1')
				{
					if (select[1] == '0' || select[1] == '1' || select[1] == '2' || select[1] == '3' || select[1] == '4' || select[1] == '5')
					{
						valid = 1;
					}
					else
					{
						valid = 0;
					}
				}
				else
				{
					valid = 0;
				}
			}
			if (valid == 0)
			{
				cout << "Please enter a valid selection!\n";
			}
		} while (valid == 0);

		if (select[0] == 'a')
		{

			cout << "\nFor A1:\nPlease enter Address in Hexadecimal seperated with ':' every 4 digits:\n";
			do
			{
				valid = 1;
				cin >> tempAdd;
				if (strlen(tempAdd) != 39)
				{
					cout << "\nInvalid input! Length of input must be 39 characters!\nPlease re-enter:\n";
					valid = 0;
				}
				else
				{
					for (i = 0; i < 39;)
					{
						if (('A' <= tempAdd[i] && tempAdd[i] <= 'F') || ('0' <= tempAdd[i] && tempAdd[i] <= '9') || tempAdd[i] == ':')
						{
							i++;
						}
						else
						{
							cout << "\nInvalid input! Please only use: 0-9, A-F characters!\nPlease re-enter:\n";
							valid = 0;
							break;
						}
					}
				}
			} while (valid == 0);

			for (i = 0, j = 0; tempAdd[i];)
			{
				if (tempAdd[i] != ':')
				{
					hex[j] = tempAdd[i];
					j++;
					i++;
				}
				else
				{
					i++;
				}
			}

			for (i = 0, j = 0; hex[i]; i++, j += 4) // Hexadecimal to binary conversion
			{
				if (hex[i] == '0')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '1')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == '2')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == '3')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == '4')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '5')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == '6')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == '7')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == '8')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '9')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'A')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'B')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'C')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'D')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'E')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'F')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
			}
			Address A3(hex, bin);
			A1 = A3;
			cout << "\nThe Address of A1 is successfully changed!\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == 'b')
		{
			cout << "\nFor A2:\nPlease enter Address in Hexadecimal seperated with ':' every 4 digits:\n";
			do
			{
				valid = 1;
				cin >> tempAdd;
				if (strlen(tempAdd) != 39)
				{
					cout << "\nInvalid input! Length of input must be 39 characters!\nPlease re-enter:\n";
					valid = 0;
				}
				else
				{
					for (i = 0; i < 39;)
					{
						if (('A' <= tempAdd[i] && tempAdd[i] <= 'F') || ('0' <= tempAdd[i] && tempAdd[i] <= '9') || tempAdd[i] == ':')
						{
							i++;
						}
						else
						{
							cout << "\nInvalid input! Please only use: 0-9, A-F characters!\nPlease re-enter:\n";
							valid = 0;
							break;
						}
					}
				}
			} while (valid == 0);

			for (i = 0, j = 0; tempAdd[i];)
			{
				if (tempAdd[i] != ':')
				{
					hex[j] = tempAdd[i];
					j++;
					i++;
				}
				else
				{
					i++;
				}
			}

			for (i = 0, j = 0; hex[i]; i++, j += 4) // Hexadecimal to binary conversion
			{
				if (hex[i] == '0')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '1')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == '2')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == '3')
				{
					bin[j] = '0';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == '4')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '5')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == '6')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == '7')
				{
					bin[j] = '0';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == '8')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == '9')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'A')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'B')
				{
					bin[j] = '1';
					bin[j + 1] = '0';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'C')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'D')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '0';
					bin[j + 3] = '1';
				}
				if (hex[i] == 'E')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '0';
				}
				if (hex[i] == 'F')
				{
					bin[j] = '1';
					bin[j + 1] = '1';
					bin[j + 2] = '1';
					bin[j + 3] = '1';
				}
			}
			Address A4(hex, bin);
			A2 = A4;
			cout << "\nThe Address of A2 is successfully changed!\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '1' && strlen(select) == 1)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					cout << "Classification for A1 is: " << ~A1;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i == 2)
				{
					cout << "Classification for A2 is: " << ~A2;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input! Please re-enter: ";
				}
			} while (i < 1 || i > 2);
		}

		if (select[0] == '2' && strlen(select) == 1)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					cout << "TLA ID of A1";
					!A1;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i == 2)
				{
					cout << "TLA ID of A2";
					!A2;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input!";
				}
			} while (i < 1 || i > 2);
		}

		if (select[0] == '3' && strlen(select) == 1)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					cout << "NLA ID of A1";
					++A1;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i == 2)
				{
					cout << "NLA ID of A2";
					++A2;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input!";
				}
			} while (i < 1 || i > 2);
		}

		if (select[0] == '4' && strlen(select) == 1)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					cout << "SLA ID of A1";
					&A1;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i == 2)
				{
					cout << "SLA ID of A2";
					&A2;
					cout << "\n----------------------------------------\n\n----------------------------------------\n";
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input!";
				}
			} while (i < 1 || i > 2);
		}

		if (select[0] == '5' && strlen(select) == 1)
		{
			Address A3 = (A1 + A2);
			cout << "Result of A1 + A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '6' && strlen(select) == 1)
		{
			Address A3 = (A1 * A2);

			cout << "Result of A1 * A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '7' && strlen(select) == 1)
		{
			Address A3 = (A1 - A2);

			cout << "Result of A1 - A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '8' && strlen(select) == 1)
		{
			Address A3 = (A1 / A2);

			cout << "Result of A1 / A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '9' && strlen(select) == 1)
		{
			Address A3 = (A1 % A2);

			cout << "Result of A1 % A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '1' && select[1] == '0' && strlen(select) == 2)
		{
			Address A3 = (A1 ^ A2);

			cout << "Result of A1 ^ A2;\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '1' && select[1] == '1' && strlen(select) == 2)
		{
			int i;
			char *hex = new char[33];
			char *bin = new char[129];

			for (i = 0; i < 32; i++)
			{
				hex[i] = '0';
			}
			hex[32] = NULL;

			for (i = 0; i < 128; i++)
			{
				bin[i] = '0';
			}
			hex[128] = NULL;

			Address A3(hex, bin);

			cout << "\nCreating a new object (A3)!\nA3 is created!\n\nContents of A3:\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128() << endl;
			cout << "\nContents of A1:\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A1.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A1.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A1.get_Bin64_128();

			A3 = A1;

			cout << "\n\nAfter A3 = A1;\n";
			cout << "Contents of A3 : \n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A3.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A3.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A3.get_Bin64_128() << endl;
			cout << "\nContents of A1:\n";
			cout << endl
				 << "Hexadecimal:" << endl;
			cout << A1.get_Hex() << endl;
			cout << endl
				 << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
			cout << A1.get_Bin64() << endl;
			cout << "Interface Identifier" << endl;
			cout << A1.get_Bin64_128();
			cout << "\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '1' && select[1] == '2' && strlen(select) == 2)
		{
			bool result = (A1 == A2);

			char *bin1_64 = new char[80];
			char *bin1_128 = new char[80];

			char *bin2_64 = new char[80];
			char *bin2_128 = new char[80];

			int i, valid = 0;

			cout << "\nResult of A1==A2: ";
			if (result == 1)
			{
				cout << "True\n\n";
			}
			else
			{
				cout << "False\nSame sections:\n";
				strcpy(bin1_64, A1.get_Bin64());
				strcpy(bin1_128, A1.get_Bin64_128());

				strcpy(bin2_64, A2.get_Bin64());
				strcpy(bin2_128, A2.get_Bin64_128());

				for (i = 0; i < 3; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nFP";
				}

				valid = 0;
				for (i = 3; i < 19; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nTLA";
				}

				valid = 0;
				for (i = 20; i < 29; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nRes";
				}

				valid = 0;
				for (i = 30; i < 64; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nNLA";
				}

				valid = 0;
				for (i = 65; i < 79; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nSLA";
				}

				valid = 0;
				for (i = 0; i < 79; i++)
				{
					if (bin1_128[i] != bin2_128[i])
					{
						valid = 0;
						break;
					}
					else
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					cout << "\nInterface Identifier";
				}
				cout << "\n----------------------------------------\n\n----------------------------------------\n";
			}
		}

		if (select[0] == '1' && select[1] == '3' && strlen(select) == 2)
		{
			bool result = (A1 != A2);

			char *bin1_64 = new char[80];
			char *bin1_128 = new char[80];

			char *bin2_64 = new char[80];
			char *bin2_128 = new char[80];

			int i, valid = 0;

			cout << "\nResult of A1!=A2: ";
			if (result == 1)
			{
				cout << "True\nDifferent sections:\n";
				strcpy(bin1_64, A1.get_Bin64());
				strcpy(bin1_128, A1.get_Bin64_128());

				strcpy(bin2_64, A2.get_Bin64());
				strcpy(bin2_128, A2.get_Bin64_128());

				for (i = 0; i < 3; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nFP";
				}

				valid = 0;
				for (i = 3; i < 19; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nTLA";
				}

				valid = 0;
				for (i = 20; i < 29; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nRes";
				}

				valid = 0;
				for (i = 30; i < 64; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nNLA";
				}

				valid = 0;
				for (i = 65; i < 79; i++)
				{
					if (bin1_64[i] != bin2_64[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nSLA";
				}

				valid = 0;
				for (i = 0; i < 79; i++)
				{
					if (bin1_128[i] != bin2_128[i])
					{
						valid = 1;
						break;
					}
					else
					{
						valid = 0;
					}
				}

				if (valid == 1)
				{
					cout << "\nInterface Identifier";
				}
				cout << "\n----------------------------------------\n\n----------------------------------------\n";
			}
			else
			{
				cout << "False\n\n";
			}
		}

		if (select[0] == '1' && select[1] == '4' && strlen(select) == 2)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					cout << A1;
				}
				if (i == 2)
				{
					cout << A2;
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input!";
				}
			} while (i < 1 || i > 2);
		}

		if (select[0] == '1' && select[1] == '5' && strlen(select) == 2)
		{
			cout << "\nPlease enter 1 for A1, 2 for A2: ";
			do
			{
				cin >> i;
				if (i == 1)
				{
					A1 >> cin;
				}
				if (i == 2)
				{
					A2 >> cin;
				}
				if (i < 1 || i > 2)
				{
					cout << "\nInvalid input!";
				}
			} while (i < 1 || i > 2);
			cout << "\nSuccessfully created!\n----------------------------------------\n\n----------------------------------------\n";
		}

		if (select[0] == '0')
		{
			cout << "\n\nGoodbye!";
		}

	} while (select[0] != '0');

	return 0;
}