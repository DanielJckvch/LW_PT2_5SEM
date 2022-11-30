#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Keeper.h"
#define FIELDSIZE 15
#define AUXSTRLEN 50
using namespace std;
void keeper::add(sign* toInsert)
{
	place* new_place;
	try
	{
		new_place = new place(toInsert);
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	new_place->next = head;
	head->prev = new_place;
	head = new_place;
	amount++;
}
void keeper::addToEnd(sign* toInsert)
{
	place* new_place;
	try
	{
		new_place = new place(toInsert);
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	new_place->prev = tail->prev;
	new_place->next = tail;
	tail->prev = new_place;
	if (new_place->prev)
	{
		new_place->prev->next = new_place;
	}
	else
	{
		head = new_place;
	}
	amount++;
}
void keeper::insert(int pos, sign* toInsert)
{
	place* new_place;
	place* p = head;
	if (pos <= 1)
	{
		this->add(toInsert);
		return;
	}
	if (pos > amount)
	{
		this->addToEnd(toInsert);
		return;
	}
	try
	{
		new_place = new place(toInsert);
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	pos-=2;
	while (pos--)
	{
		p = p->next;
	}
	new_place->next = p->next;
	new_place->prev = p;
	p->next->prev = new_place;
	p->next = new_place;
	amount++;
	
}
void keeper::copy(int sou, int dest)
{
	if (sou <= 0 || sou > amount)
	{
		int er = 1;
		throw er;
		return;
	}
	place* p = head;
	sou--;
	while (sou)
	{
		p = p->next;
		sou = sou - 1;
	}
	this->insert(dest, p->note->get());
}
void keeper::del(int num)
{
	place* p = head;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
		return;
	}
	if (num > amount || num <= 0)
	{
		double er1 = 1.0;
		throw er1;
		return;
	}
	num--;
	while (num > 0)
	{
		p = p->next;
		num--;
	}
	if (p->prev)
	{
		p->prev->next = p->next;
	}
	else
	{
		head = head->next;
	}
	p->next->prev = p->prev;
	delete p;
	amount--;
}
void keeper::changeEl(int num)
{
	place* p = head;
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
		return;
	}
	if (num > amount || num <= 0)
	{
		double er1 = 1.0;
		throw er1;
		return;
	}
	num--;
	while (num > 0)
	{
		p = p->next;
		num--;
	}
	p->note->change();
}
void keeper::show(void)
{
	place* p = head;
	while (p->next != nullptr)
	{
		p->note->show(cout);
		p = p->next;
	}
}

void keeper::search(char* s, int f)
{
	place* p = head;
	int found = 0;
	if (!amount)
	{
		int er = 1;
		throw er;
	}
	while (p->next)
	{
		switch (f)
		{
		case 0:
			if (!strcmp(p->note->get(0), s))
			{
				found = 1;
				p->note->show(cout);
				break;
			}
			break;
		case 1:
			if (!strcmp(p->note->get(1), s))
			{
				found = 1;
				p->note->show(cout);
				break;
			}
			break;
		case 2:
			if (!strcmp(p->note->get(2), s))
			{
				found = 1;
				p->note->show(cout);
				break;
			}
			break;
		}
		p = p->next;
	}
	if (!found)
	{
		cout << "Nothing found" << endl;
	}
}
void keeper::search(int perVal, int perNum)
{
	place* p = head;
	int found = 0;
	if (!amount)
	{
		int er = 1;
		throw er;
	}
	while (p->next)
	{

		if (p->note->getDate(perNum) == perVal)
		{
			found = 1;
			p->note->show(cout);
		}
		p = p->next;
	}
	if (!found)
	{
		cout << "Nothing found" << endl;
	}
}
void keeper::clear(void)
{
	place* p = head;
	while (amount)
	{
		p = head;
		head = head->next;
		delete p;
		amount = amount - 1;
	}
	head->prev = nullptr;
}
keeper::keeper()
{
	cout << "Calling the constructor without parameters in the \"Keeper\" class" << endl;
	try
	{
		head = tail = new place;
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	amount = 0;
}
keeper::keeper(sign* rec)
{
	cout << "Calling the constructor with parameters in the \"Keeper\" class" << endl;
	try
	{
		head = tail = new place;
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	amount = 0;
	this->add(rec);
}
keeper::keeper(const keeper &toCopy)
{
	cout << "Calling the copy constructor in the \"Keeper\" class" << endl;
	place* ob_p = toCopy.tail->prev;
	sign* p;
	try
	{
		head = tail = new place;
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	amount = 0;
	while (ob_p != nullptr)
	{

		this->add(ob_p->note->get());
		ob_p = ob_p->prev;
		amount++;
	}
}
keeper::~keeper()
{
	cout << "Calling the destructor in the \"Keeper\" class" << endl;
	place* p = head;
	while (p != nullptr)
	{
		p = p->next;
		delete head;
		head = p;
	}
}
ostream& operator<<(ostream& stream, const keeper& cont)
{
	place* p = cont.head;
	
	if (p->next == nullptr)
	{
		int er = 1;
		throw er;
		return stream;
	}
	int i = 1;
	while (p->next != nullptr)
	{
		stream << "Person " << i << ':' << endl;
		p->note->show(stream);
		p = p->next;
		i++;
	}
	return stream;
}
/*
void keeper::loadToFile(char* name)
{
	ofstream file(name, ios::out | ios::trunc);
	if (!file)
	{
		cout << "File opening error" << endl;
		return;
	}
	file << "The list of vehicles." << endl;
	file << "\n\n";
	place* p = tail->prev;
	char* s;
	int i = 1;
	if (p == nullptr)
	{
		int er = 1;
		throw er;
		file.close();
		return;
	}
	while (p != nullptr)
	{
		p->note->show(file);
		p = p->prev;
	}
	file.close();
}

void keeper::loadFromFile(char* name)
{
	ifstream file(name, ios::in);
	if (!file)
	{
		cout << "File opening error" << endl;
		return;
	}
	place* p = head;
	this->clear();
	sign* g_ptr = nullptr;
	char t = 0;
	char buffErr[] = "Error of the input buffer";
	char incData[] = "Another type of data";
	short motoF = 0;
	short autoF = 0;
	short busF = 0;
	char* pos = 0;
	char* s;
	char* lows;
	char** fields;
	try
	{
		s = new char[AUXSTRLEN];
		lows = new char[AUXSTRLEN];
		fields = new char* [5];
		for (int i = 0;i < 5;i++)
		{
			fields[i] = new char[FIELDSIZE];
			memset(fields[i], 0, FIELDSIZE);
		}
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	while (file)
	{
		file.getline(s, AUXSTRLEN);
		strcpy(lows, s);
		_strlwr(lows);
		try
		{
			if (strstr(lows, "motorcycle") != 0)
			{
				if (t)
				{
					throw 'm';
				}
				g_ptr = new motorcycle;
				t = 'm';

			}
			else if (strstr(lows, "automobile") != 0)
			{
				if (t)
				{
					throw 'a';
				}
				g_ptr = new sign;
				t = 'a';
			}
			else if (strstr(lows, "bus") != 0)
			{
				if (t)
				{
					throw 'b';
				}
				g_ptr = new bus;
				t = 'b';
				/*
				try
				{
					while (file)
					{
						file.getline(s, AUXSTRLEN);
						strcpy(lows, s);
						_strlwr(lows);
						if ((pos = strstr(lows, "name")) != NULL)
						{
							fieldMode = 0;
							pos = s + (lows - pos) + 5;
						}
						else if ((pos = strstr(lows, "surname")) != NULL)
						{
							fieldMode = 1;
							pos = s + (lows - pos) + 6;
						}

						else
						{
							throw fieldMode;
						}
						strcpy(fields[fieldMode], pos);
					}
				}
				catch (char* errField)
				{
					cout << "Data for the bus is partially missing\n" << endl;
					if (fields[0][0] == 0)
					{
						cout << "Enter a new name: " << endl;
						try
						{
							cin >> fields[0];
							if (cin.bad() || cin.fail())
							{
								throw buffErr;
							}
						}
						catch (char*)
						{
							exit(1);
						}
					}
					if (fields[1][0] == 0)
					{
						cout << "Enter a new surname: " << endl;
						try
						{
							cin >> fields[1];
							if (cin.bad() || cin.fail())
							{
								throw buffErr;
							}
						}
						catch (char*)
						{
							exit(1);
						}
					}
					if (fields[2][0] == 0)
					{
						cout << "Enter a new total number of passengers: " << endl;
						try
						{
							cin >> fields[2];
							if (cin.bad() || cin.fail())
							{
								throw buffErr;
							}
						}
						catch (char*)
						{
							exit(1);
						}
					}
					if (fields[3][0] == 0)
					{
						cout << "Enter a new number of seats: " << endl;
						try
						{
							cin >> fields[3];
							if (cin.bad() || cin.fail())
							{
								throw buffErr;
							}
						}
						catch (char*)
						{
							exit(1);
						}
					}
					if (fields[4][0] == 0)
					{
						cout << "Enter a new terminal point: " << endl;
						try
						{
							cin >> fields[4];
							if (cin.bad() || cin.fail())
							{
								throw buffErr;
							}
						}
						catch (char*)
						{
							exit(1);
						}
					}
				}

			}
			else if ((pos = strstr(lows, "name")) != NULL)
			{
				if (motoF == 0 && t == 'm')
				{
					motoF = 1;
				}
				else if (autoF == 0 && t == 'a')
				{
					autoF = 1;
				}
				else if (busF == 0 && t == 'b')
				{
					busF = 1;
				}
				else 
				{
					throw incData;
				}
				pos = s + (lows - pos) + 5;
				strcpy(fields[0], pos);
			}
			else if ((pos = strstr(lows, "surname")) != NULL)
			{
				if (motoF == 1 && t == 'm')
				{
					motoF = 2;
				}
				else  if (autoF == 1 && t == 'a')
				{
					autoF = 2;
				}
				else if (busF == 1 && t == 'b')
				{
					busF = 2;
				}
				else 
				{
					throw incData;
				}
				pos = s + (lows - pos) + 6;
				strcpy(fields[1], pos);
			}
			else if ((pos = strstr(lows, "engine size")) != NULL)
			{
				if (t == 'b'&&!t)
				{
					throw incData;
				}
				if (motoF == 2 && t == 'm')
				{
					motoF = 3;
				}
				else if (autoF == 2 && t == 'a')
				{
					autoF = 3;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 12;
				strcpy(fields[2], pos);
			}
			else if ((pos = strstr(lows, "engine capability")) != NULL)
			{
				if (t != 'm'&&t)
				{
					throw incData;
				}
				if (motoF == 3)
				{
					motoF = 4;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 18;
				strcpy(fields[3], pos);
			}
			else if ((pos = strstr(lows, "terrain")) != NULL)
			{
				if (t != 'm'&&t)
				{
					throw incData;
				}
				if (motoF == 4)
				{
					motoF = 0;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 8;
				t = 0;
				strcpy(fields[4], pos);
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->addToEnd(g_ptr);
				g_ptr = nullptr;
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
			}
			else if ((pos = strstr(lows, "colour")) != NULL)
			{
				if (t != 'a' && t)
				{
					throw incData;
				}
				if (autoF == 3 && t == 'a')
				{
					autoF = 4;
				}
				else if (t == 'a')
				{
					throw incData;
				}
				pos = s + (lows - pos) + 7;
				strcpy(fields[3], pos);
			}
			else if ((pos = strstr(lows, "transmission type")) != NULL)
			{
				if (t != 'a' && t)
				{
					throw incData;
				}
				if (autoF == 4 && t == 'a')
				{
					autoF = 0;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 18;
				t = 0;
				strcpy(fields[4], pos);
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->addToEnd(g_ptr);
				g_ptr = nullptr;
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
			}
			else if ((pos = strstr(lows, "total number of passengers")) != NULL)
			{
				if (t != 'b' && t)
				{
					throw incData;
				}
				if (busF == 2 && t == 'b')
				{
					busF = 3;
				}
				else if (t == 'b')
				{
					throw incData;
				}
				pos = s + (lows - pos) + 27;
				strcpy(fields[2], pos);
			}
			else if ((pos = strstr(lows, "number of seats")) != NULL)
			{
				if (t != 'b' && t)
				{
					throw incData;
				}
				if (busF == 3 && t == 'b')
				{
					busF = 4;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 16;
				strcpy(fields[3], pos);
			}
			else if ((pos = strstr(lows, "terminal point")) != NULL)
			{
				if (t != 'b' && t)
				{
					throw incData;
				}
				if (busF == 4 && t == 'b')
				{
					busF = 0;
				}
				else
				{
					throw incData;
				}
				pos = s + (lows - pos) + 15;
				t = 0;
				strcpy(fields[4], pos);
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->addToEnd(g_ptr);
				g_ptr = nullptr;
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
			}
		}
		catch(char* er)
		{
			cout << er << endl;
			motoF = 0;
			autoF = 0;
			busF = 0;
			t = 0;
			for (int i = 0;i < 5;i++)
			{
				memset(fields[i], 0, FIELDSIZE);
			}
			if (g_ptr)
			{
				delete g_ptr;
				g_ptr = nullptr;
			}
			
		}
		catch (char newCl)
		{

			cout << "This object is missing part of the data: " << endl;
			cout << endl;
			switch (*(g_ptr->get(0)))
			{
			case 'm':
				cout << "Motorcycle" << endl;
				if (fields[0][0]) { cout << "Mark:" << fields[0] << endl; }
				if (fields[1][0]) { cout << "Model:" << fields[1] << endl; }
				if (fields[2][0]) { cout << "Engine size:" << fields[2] << endl; }
				if (fields[3][0]) { cout << "Engine capability:" << fields[3] << endl; }
				if (fields[4][0]) { cout << "Terrain:" << fields[4] << endl; }
				break;
			case 'a':
				cout << "Automobile" << endl;
				if (fields[0][0]) { cout << "Mark:" << fields[0] << endl; }
				if (fields[1][0]) { cout << "Model:" << fields[1] << endl; }
				if (fields[2][0]) { cout << "Engine size:" << fields[2] << endl; }
				if (fields[3][0]) { cout << "Colour:" << fields[3] << endl; }
				if (fields[4][0]) { cout << "Transmission type:" << fields[4] << endl; }
				break;
			case 'b':
				cout << "Bus" << endl;
				if (fields[0][0]) { cout << "Mark:" << fields[0] << endl; }
				if (fields[1][0]) { cout << "Model:" << fields[1] << endl; }
				if (fields[2][0]) { cout << "Total number of passengers:" << fields[2] << endl; }
				if (fields[3][0]) { cout << "Number of seats:" << fields[3] << endl; }
				if (fields[4][0]) { cout << "Terminal point:" << fields[4] << endl; }
				break;
			}
			cout << endl;
			cout << "You can fill in the data: " << endl;
			cout << endl;
			switch (*(g_ptr->get(0)))
			{
			case 'm':
				switch (motoF)
				{
				case 0:
					cout << "Enter a new name: " << endl;
					try
					{
						cin >> fields[0];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 1:
					cout << "Enter a new surname: " << endl;
					try
					{
						cin >> fields[1];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 2:
					cout << "Enter a new engine size: " << endl;
					try
					{
						cin >> fields[2];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 3:
					cout << "Enter a new engine capability: " << endl;
					try
					{
						cin >> fields[3];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 4:
					cout << "Enter a new terrain for the motorcycle: " << endl;
					try
					{
						cin >> fields[4];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				}
				motoF = 0;
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->add(g_ptr);
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
				break;
			case 'a':
				switch (autoF)
				{
				case 0:
					cout << "Enter a new name: " << endl;
					try
					{
						cin >> fields[0];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 1:
					cout << "Enter a new surname: " << endl;
					try
					{
						cin >> fields[1];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 2:
					cout << "Enter a new engine size: " << endl;
					try
					{
						cin >> fields[2];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 3:
					cout << "Enter a new colour: " << endl;
					try
					{
						cin >> fields[3];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 4:
					cout << "Enter a new transmission type: " << endl;
					try
					{
						cin >> fields[4];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				}
				autoF = 0;
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->add(g_ptr);
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
				break;
			case 'b':
				switch (busF)
				{
				case 0:
					cout << "Enter a new name: " << endl;
					try
					{
						cin >> fields[0];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 1:
					cout << "Enter a new surname: " << endl;
					try
					{
						cin >> fields[1];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 2:
					cout << "Enter a new total number of passengers: " << endl;
					try
					{
						cin >> fields[2];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 3:
					cout << "Enter a new number of seats: " << endl;
					try
					{
						cin >> fields[3];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				case 4:
					cout << "Enter a new terminal point: " << endl;
					try
					{
						cin >> fields[4];
						if (cin.bad() || cin.fail())
						{
							throw buffErr;
						}
					}
					catch (char*)
					{
						exit(1);
					}
				}
				busF = 0;
				g_ptr->set(fields[0], fields[1], fields[2], fields[3], fields[4]);
				this->add(g_ptr);
				for (int i = 0;i < 5;i++)
				{
					memset(fields[i], 0, FIELDSIZE);
				}
				break;
			}
			switch (newCl)
			{
			case 'm':
				g_ptr = new motorcycle;
				t = 'm';
				break;
			case 'a':
				g_ptr = new sign;
				t = 'a';
				break;
			case 'b':
				g_ptr = new bus;
				t = 'b';
				break;
			}
		}
		
	}
	file.close();
	delete[] s;
	delete[] lows;
	for (int i = 0;i < 5;i++)
	{
		delete[] fields[i];
	}
	delete[] fields;
}*/