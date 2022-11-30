#pragma once
#include<iostream>

using namespace std;
class sign
{
private:
	char* name;
	char* surname;
	char* zodiacSign;
	short int* birthDate;
public:
	void show(std::ostream& out);
	void change(void);
	sign* get(void);
	char* get(int propNum);
	short getDate(int perNum);
	void set(char* s1, char* s2, char* s3, short day, short month, short year);
	sign(void);
	sign(char* s1, char* s2, char* s3, short day, short month, short year);
	sign(const sign& toCopy);
	~sign(void);
};
