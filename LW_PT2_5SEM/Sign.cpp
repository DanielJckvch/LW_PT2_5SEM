#define _CRT_SECURE_NO_WARNINGS
#include "Sign.h"
#include <iostream>
#include <string.h>
#define FIELDSIZE 15
using namespace std;

void sign::show(ostream& out)
{
	out << "Name:" << name << endl;
	out << "Surname:" << surname << endl;
	out << "Zodiac sign:" << zodiacSign << endl;
	out << "Date of birth:" << birthDate[0] << '.' << birthDate[1] << '.' << birthDate[2] << endl;
	out << endl;
}
sign::sign(void)
{
	//notuse
	cout << "Calling the constructor in the \"Sign\" class" << endl;
	name = surname = zodiacSign = nullptr;
	birthDate = nullptr;
}
sign::sign(char* s1, char* s2, char* s3, short day, short month, short year):name(s1),surname(s2),zodiacSign(s3)
{
	cout << "Calling the constructor in the \"Sign\" class" << endl;
	birthDate = new short[3];
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
}
sign::sign(const sign& toCopy)
{
	cout << "Calling the copy constructor in the \"Sign\" class" << endl;
	if (toCopy.name)
	{
		try
		{
			name = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
		strcpy(name, toCopy.name);
	}
	else
	{
		name = nullptr;
	}
	if (toCopy.surname)
	{
		try
		{
			surname = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
		strcpy(surname, toCopy.surname);
	}
	else
	{
		surname = nullptr;
	}
	if (toCopy.zodiacSign)
	{
		try
		{
			zodiacSign = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
		strcpy(zodiacSign, toCopy.zodiacSign);
	}
	else
	{
		zodiacSign = nullptr;
	}
	if (toCopy.birthDate)
	{
		try
		{
			birthDate = new short[3];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
		for (int i = 0;i < 3;i++)
		{
			birthDate[i] = toCopy.birthDate[i];
		}
	}
	else
	{
		birthDate = nullptr;
	}
	
}

sign* sign::get(void)
{
	sign* new_ob;
	try
	{
		new_ob = new sign(*this);
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	return new_ob;
}
char* sign::get(int propNum)
{
	switch (propNum)
	{
	case 0:
		return name;
	case 1:
		return surname;
	case 2:
		return zodiacSign;
	}
}
short sign::getDate(int perNum)
{
	return birthDate[perNum];
}
void sign::set(char* s1, char* s2, char* s3, short day, short month, short year)
{
	if (!name)
	{
		try
		{
			name = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
	}
	strcpy(name, s1);
	if (!surname)
	{
		try
		{
			surname = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}

	}
	strcpy(surname, s2);
	if (!zodiacSign)
	{
		try
		{
			zodiacSign = new char[FIELDSIZE];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}

	}
	strcpy(zodiacSign, s3);
	if (!birthDate)
	{
		try
		{
			birthDate = new short[3];
		}
		catch (bad_alloc)
		{
			cout << "Error of the operator \"new\"" << endl;
			exit(-1);
		}
		
	}
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
	
}
sign::~sign(void)
{
	cout << "Calling the destructor in the \"Sign\" class" << endl;
	delete[] name;
	delete[] surname;
	delete[] zodiacSign;
	delete[] birthDate;
}
void sign::change(void)
{
	int chanProp;
	char buffErr[] = "Error of the input buffer";
	cout << "Original data: " << endl;
	cout << endl;
	cout << "Name:" << name << endl;
	cout << "Surname:" << surname << endl;
	cout << "Zodiac sign:" << zodiacSign << endl;
	cout << "Date of birth:" << birthDate[0]<<'.'<< birthDate[1] <<'.'<< birthDate[2] << endl;
	cout << endl;
	cout << "Enter the number of note property to change: 1 - name, 2 - surname, 3 - zodiac sign, 4 - day of birth, 5 - month of birth, 6 - year of birth." << endl;
	try
	{
		cin >> chanProp;
		if (cin.bad() || cin.fail())
		{
			throw buffErr;
		}
	}
	catch (char*)
	{
		exit(1);
	}
	switch (chanProp)
	{
	case 1:
		cout << "Enter a new name: " << endl;
		try
		{
			cin >> name;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	case 2:
		cout << "Enter a new surname: " << endl;
		try
		{
			cin >> surname;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	case 3:
		cout << "Enter a new zodiac sign: " << endl;
		try
		{
			cin >> zodiacSign;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	case 4:
		cout << "Enter a new day of birth: " << endl;
		try
		{
			cin >> birthDate[0];
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	case 5:
		cout << "Enter a new month of birth: " << endl;
		try
		{
			cin >> birthDate[1];
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	case 6:
		cout << "Enter a new year of birth: " << endl;
		try
		{
			cin >> birthDate[2];
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		break;
	}
}