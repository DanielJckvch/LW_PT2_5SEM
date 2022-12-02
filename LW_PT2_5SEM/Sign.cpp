#define _CRT_SECURE_NO_WARNINGS
#include "Sign.h"
#include <iostream>
#include <string.h>
#define FIELDSIZE 15
using namespace std;

sign::sign(void)
{
	//notuse
	cout << "Calling the constructor in the \"Sign\" class" << endl;
	name = surname = zodiacSign = nullptr;
	birthDate = nullptr;
	days = 0;
}
sign::sign(char* s1, char* s2, char* s3, short day, short month, short year)
{
	cout << "Calling the constructor in the \"Sign\" class" << endl;
	try
	{
		if (!name)
		{

			name = new char[FIELDSIZE];

		}
		strcpy(name, s1);
		if (!surname)
		{

			surname = new char[FIELDSIZE];

		}
		strcpy(surname, s2);
		if (!zodiacSign)
		{
			zodiacSign = new char[FIELDSIZE];

		}
		strcpy(zodiacSign, s3);
		if (!birthDate)
		{
			birthDate = new short[3];

		}
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
	days = 0;
}
sign::sign(const sign& toCopy)
{
	cout << "Calling the copy constructor in the \"Sign\" class" << endl;
	try
	{
		if (toCopy.name)
		{

			name = new char[FIELDSIZE];
			strcpy(name, toCopy.name);
		}
		else
		{
			name = nullptr;
		}
		if (toCopy.surname)
		{

			surname = new char[FIELDSIZE];
			strcpy(surname, toCopy.surname);
		}
		else
		{
			surname = nullptr;
		}
		if (toCopy.zodiacSign)
		{

			zodiacSign = new char[FIELDSIZE];
			strcpy(zodiacSign, toCopy.zodiacSign);
		}
		else
		{
			zodiacSign = nullptr;
		}
		if (toCopy.birthDate)
		{

			birthDate = new short[3];
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
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	days = toCopy.days;
}
sign::~sign(void)
{
	cout << "Calling the destructor in the \"Sign\" class" << endl;
	delete[] name;
	delete[] surname;
	delete[] zodiacSign;
	delete[] birthDate;
}
void sign::countDays(void)
{
	days = birthDate[0];
	for (int i = 0;i < birthDate[1];i++)
	{
		days += months[i];
	}
	days = days + birthDate[2] * 365;
	
}
void sign::change(void)
{
	int chanProp;
	char buffErr[] = "Error of the input buffer";
	cout << "Original data: " << endl;
	cout << endl;
	cout << *(this);
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
	if (chanProp < 0 || chanProp>6)
	{
		cout << "Entered uncorrect mode." << endl;
		return;
	}
	chanProp--;
	try
	{
		chanProp >> *(this);
	}
	catch (int)
	{
		cout << "Entered uncorrect date." << endl;
		return;
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
	try
	{
		if (!name)
		{

			name = new char[FIELDSIZE];

		}
		strcpy(name, s1);
		if (!surname)
		{

			surname = new char[FIELDSIZE];

		}
		strcpy(surname, s2);
		if (!zodiacSign)
		{
			zodiacSign = new char[FIELDSIZE];

		}
		strcpy(zodiacSign, s3);
		if (!birthDate)
		{
			birthDate = new short[3];
			
		}
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	birthDate[0] = day;
	birthDate[1] = month;
	birthDate[2] = year;
}
ostream& operator<<(ostream& out, sign& per)
{
	out << "Name:" << per.name << endl;
	out << "Surname:" << per.surname << endl;
	out << "Zodiac sign:" << per.zodiacSign << endl;
	out << "Date of birth:" << per.birthDate[0] << '.' << per.birthDate[1] << '.' << per.birthDate[2] << endl;
	out << endl;
	return out;
}
void operator>>(int perNum, sign& per)
{
	int errDate = 0;
	short b = 0;
	char buffErr[] = "Error of the input buffer";
	try {
		if (!per.name)
		{

			per.name = new char[FIELDSIZE];

		}
		if (!per.surname)
		{

			per.surname = new char[FIELDSIZE];

		}
		if (!per.zodiacSign)
		{

			per.zodiacSign = new char[FIELDSIZE];

		}
		if (!per.birthDate)
		{

			per.birthDate = new short[3];

		}
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	try
	{
		switch (perNum)
		{
		case 0:
			cout << "Enter a name:" << endl;
			cin >> per.name;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			cout << endl;
			break;
		case 1:
			cout << "Enter a surname:" << endl;
			cin >> per.surname;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			cout << endl;
			break;
		case 2:
			cout << "Enter a zodiac sign:" << endl;
			cin >> per.zodiacSign;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			cout << endl;
			break;
		case 3:
			cout << "Enter a day of birth:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			if (b < 1 || b > 31)
			{
				throw errDate;
			}
			per.birthDate[0] = b;
			cout << endl;
			break;
		case 4:
			cout << "Enter a month of birth:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			if (b < 1 || b > 12)
			{
				throw errDate;
			}
			per.birthDate[1] = b;
			cout << endl;
			break;
		case 5:
			cout << "Enter a year of birth:" << endl;
			cin >> b;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
			if (b < 0)
			{
				throw errDate;
			}
			per.birthDate[2] = b;
			break;
		}	
	}
	catch (char*)
	{
		exit(1);
	}
	
}





