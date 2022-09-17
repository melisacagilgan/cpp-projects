#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::strlen;

class Address
{
private:
	char *hexadecimal;
	char *binary;

public:
	Address()
	{
		hexadecimal = new char[33];
		binary = new char[129];
	}
	Address(char *hex, char *bin)
	{
		hexadecimal = new char[(strlen(hex) + 1)];
		binary = new char[(strlen(bin) + 1)];

		strcpy(hexadecimal, hex);
		strcpy(binary, bin);
	}
	/*		~Address()
			{
				delete[] hexadecimal;
				delete[] binary;
			}*/

	char *get_Hex()
	{
		int i, j;
		char *hex = new char[40];
		for (i = 0, j = 0; i < 39; i++)
		{
			if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24 || i == 29 || i == 34) // To separate every 4 digits with ":"
			{
				hex[i] = ':';
			}
			else
			{
				hex[i] = hexadecimal[j];
				j++;
			}
		}
		hex[39] = NULL;
		return hex;
	}

	char *get_Bin64()
	{
		int i, j;
		char *bin64 = new char[80];
		for (i = 0, j = 0; i < 80; i++)
		{
			if (i == 4 || i == 9 || i == 14 || i == 24 || i == 29 || i == 34 || i == 44 || i == 49 || i == 54 || i == 64 || i == 69 || i == 74) // To separate 4 digits with space
			{
				bin64[i] = ' ';
			}
			else if (i == 19 || i == 39 || i == 59) // To separate 4 digits with ":"
			{
				bin64[i] = ':';
			}
			else
			{
				bin64[i] = binary[j];
				j++;
			}
		}
		bin64[79] = NULL;
		return bin64;
	}

	char *get_Bin64_128()
	{
		int i, j;
		char *bin64_128 = new char[80];
		for (i = 0, j = 64; i < 80; i++)
		{
			if (i == 4 || i == 9 || i == 14 || i == 24 || i == 29 || i == 34 || i == 44 || i == 49 || i == 54 || i == 64 || i == 69 || i == 74) // To separate 4 digits with space
			{
				bin64_128[i] = ' ';
			}
			else if (i == 19 || i == 39 || i == 59) // To separate 4 digits with ":"
			{
				bin64_128[i] = ':';
			}
			else
			{
				bin64_128[i] = binary[j];
				j++;
			}
		}
		bin64_128[79] = NULL;
		return bin64_128;
	}

	Address &operator=(const Address &add) // a & b and Operator 11
	{
		int i;
		for (i = 0; i < 32; i++)
		{
			this->hexadecimal[i] = add.hexadecimal[i];
		}
		for (i = 0; i < 128; i++)
		{
			this->binary[i] = add.binary[i];
		}
		return *this;
	}

	const char *operator~() // Operator 1
	{
		if (binary[0] == '0' && binary[1] == '0' && binary[2] == '0')
		{
			return "Anycast";
		}
		if (binary[0] == '0' && binary[1] == '0' && binary[2] == '1')
		{
			return "Unicast";
		}
		if ((binary[0] == '0' && binary[1] == '1' && binary[2] == '0') || (binary[0] == '0' && binary[1] == '1' && binary[2] == '1') || (binary[0] == '1' && binary[1] == '0' && binary[2] == '0'))
		{
			return "Unicast";
		}
		else
		{
			return "Multicast";
		}
	}

	void operator!() // Operator 2
	{
		int i;

		cout << "\nHexadecimal: ";
		for (int i = 0; i < 4; i++)
		{
			cout << hexadecimal[i];
		}

		cout << "\nBinary: ";
		for (i = 3; i < 16; i++)
		{
			if (i == 4 || i == 8 || i == 12) // To separate 4 digits with space
			{
				cout << ' ';
			}
			cout << binary[i];
		}
	}

	void operator++() // Operator 3
	{
		int i;

		cout << "\nHexadecimal: ";
		for (i = 6; i < 12; i++)
		{
			cout << hexadecimal[i];
		}

		cout << "\nBinary: ";
		for (i = 24; i < 48; i++)
		{
			if (i == 28 || i == 33 || i == 38 || i == 43)
			{
				binary[i] = ' ';
			}
			cout << binary[i];
		}
	}

	void operator&() // Operator 4
	{
		int i;

		cout << "\nHexadecimal: ";
		for (i = 12; i < 16; i++)
		{
			cout << hexadecimal[i];
		}

		cout << "\nBinary: ";
		for (i = 48; i < 64; i++)
		{
			if (i == 52 || i == 56 || i == 60)
			{
				cout << ' ';
			}
			cout << binary[i];
		}
	}

	Address operator+(const Address &add) // Operator 5
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] == '1' || add.binary[i] == '1') // Bitwise OR operator
			{
				A3.binary[i] = '1';
			}
			else
			{
				A3.binary[i] = '0';
			}
		}
		A3.binary[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	Address operator*(const Address &add) // Operator 6
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] == '1' && add.binary[i] == '1') // Bitwise AND operator
			{
				A3.binary[i] = '1';
			}
			else
			{
				A3.binary[i] = '0';
			}
		}
		A3.binary[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	Address operator-(const Address &add) // Operator 7
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] == '0' && add.binary[i] == '0') // Bitwise NOR operator
			{
				A3.binary[i] = '1';
			}
			else
			{
				A3.binary[i] = '0';
			}
		}
		A3.binary[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	Address operator/(const Address &add) // Operator 8
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] == '1' && add.binary[i] == '1') // Bitwise NAND operator
			{
				A3.binary[i] = '0';
			}
			else
			{
				A3.binary[i] = '1';
			}
		}
		A3.binary[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	Address operator%(const Address &add) // Operator 9
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] != add.binary[i]) // Bitwise XOR operator
			{
				A3.binary[i] = '1';
			}
			else
			{
				A3.binary[i] = '0';
			}
		}
		A3.hexadecimal[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	Address operator^(const Address &add) // Operator 10
	{
		Address A3;
		int i, j, count = 0;

		for (i = 0; i < 64; i++) // First 64 digits(in binary) remain unchanged
		{
			A3.binary[i] = this->binary[i];
		}

		for (i = 64; i < 128; i++)
		{
			if (this->binary[i] == add.binary[i]) // Bitwise XNOR operator
			{
				A3.binary[i] = '1';
			}
			else
			{
				A3.binary[i] = '0';
			}
		}
		A3.hexadecimal[128] = NULL;

		for (i = 0; i < 16; i++) // First 16 digits(in hexadecimal) remain unchanged
		{
			A3.hexadecimal[i] = this->hexadecimal[i];
		}

		for (i = 16; i < 32; i++) // Binary to hexadecimal conversion
		{
			j = 4 * i;
			count = 0;
			if (A3.binary[j] == '1')
			{
				count += 8;
			}
			if (A3.binary[j + 1] == '1')
			{
				count += 4;
			}
			if (A3.binary[j + 2] == '1')
			{
				count += 2;
			}
			if (A3.binary[j + 3] == '1')
			{
				count += 1;
			}

			if (count > 9)
			{
				switch (count)
				{
				case 10:
					A3.hexadecimal[i] = 'A';
					break;
				case 11:
					A3.hexadecimal[i] = 'B';
					break;
				case 12:
					A3.hexadecimal[i] = 'C';
					break;
				case 13:
					A3.hexadecimal[i] = 'D';
					break;
				case 14:
					A3.hexadecimal[i] = 'E';
					break;
				case 15:
					A3.hexadecimal[i] = 'F';
					break;
				}
			}
			else
			{
				A3.hexadecimal[i] = '0' + count;
			}
		}
		A3.hexadecimal[32] = NULL;

		return A3;
	}

	bool operator==(const Address &add) // Operator 12
	{
		int i;
		for (i = 0; i < 128; i++)
		{
			if (this->binary[i] != add.binary[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const Address &add) // Operator 13
	{
		int i;
		for (i = 0; i < 128; i++)
		{
			if (this->binary[i] != add.binary[i])
			{
				return true;
			}
		}
		return false;
	}

	friend void operator<<(ostream &output, Address &add) // Operator 14
	{
		output << endl
			   << "Hexadecimal:" << endl;
		output << add.get_Hex() << endl;
		output << endl
			   << "Binary:\nFP, TLA, Res, NLA, SLA" << endl;
		output << add.get_Bin64() << endl;
		output << "Interface Identifier" << endl;
		output << add.get_Bin64_128();
		output << "\n----------------------------------------\n\n----------------------------------------\n";
	}

	friend void operator>>(Address &add, istream &input) // Operator 15
	{
		int i, j, valid;
		cout << "\nPlease enter Address in Hexadecimal seperated with ':' every 4 digits:\n";
		do
		{
			valid = 1;
			input >> add.hexadecimal;
			if (strlen(add.hexadecimal) != 39)
			{
				cout << "\nInvalid input! Length of input must be 39 characters!\nPlease re-enter:\n";
				valid = 0;
			}
			else
			{
				for (i = 0; i < 39;)
				{
					if (('A' <= add.hexadecimal[i] && add.hexadecimal[i] <= 'F') || ('0' <= add.hexadecimal[i] && add.hexadecimal[i] <= '9') || add.hexadecimal[i] == ':')
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

		for (i = 0, j = 0; add.hexadecimal[i]; i++, j += 4) // Hexadecimal to binary conversion
		{
			if (add.hexadecimal[i] == '0')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == '1')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == '2')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == '3')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == '4')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == '5')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == '6')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == '7')
			{
				add.binary[j] = '0';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == '8')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == '9')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == 'A')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == 'B')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '0';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == 'C')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == 'D')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '0';
				add.binary[j + 3] = '1';
			}
			if (add.hexadecimal[i] == 'E')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '0';
			}
			if (add.hexadecimal[i] == 'F')
			{
				add.binary[j] = '1';
				add.binary[j + 1] = '1';
				add.binary[j + 2] = '1';
				add.binary[j + 3] = '1';
			}
		}
	}
};