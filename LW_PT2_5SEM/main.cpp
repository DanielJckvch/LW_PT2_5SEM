#include <iostream>
#include <fstream>
#include "Keeper.h"
#define FIELDSIZE 20
#define BUFLEN 5000
using namespace std;
/*
Задание:
Вариант 16
1. Стандартные потоки
Определить класс с именем SIGN, содержащий следующие поля:
● фамилия, имя;
● знак зодиака;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа SIGN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по датам дней рождения;
● вывод на экран информации о людях, родившихся под знаком, наименование которого введено с клавиатуры;
● если таких нет, выдать на дисплей соответствующее сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу, которая считывает текст из файла и выводит на экран сначала вопросительные, а затем восклицательные предложения.
*/
 

void procSignList(void);
void procSenten(void);
bool passCheck(void);

int main(void)
{
	if (!passCheck())
	{
		return 0;
	}
	int taskMode = 0;
	char buffErr[] = "Error of the input buffer";
	do
	{
		cout << endl;
		cout << "Enter number of the task: 0 - exit, 1 - container of objects of the SIGN class, 2 - separation of sentences." << endl;
		try
		{
			cin >> taskMode;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		cout << endl;
		if (taskMode < 0 || taskMode>2)
		{
			cout << "Entered uncorrect mode. Try entering the mode number again." << endl;
			continue;
		}
		switch (taskMode)
		{
		case 1:
			procSignList();
			break;
		case 2:
			procSenten();
			break;
		}

	} while (taskMode);
	return 0;
}

void procSignList(void)
{
	char* searchS;
	int searchDate = 0;
	char* filename;
	try
	{
		searchS = new char[FIELDSIZE];
		filename = new char[50];
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	sign* g_ptr = nullptr;
	keeper cont1;
	int mode = 0;
	int charMode = 0;
	int sortMode = 0;
	int num = 0;
	int copied = 0;
	int toCopy = 0;
	char buffErr[] = "Error of the input buffer";
	do
	{
		cout << endl;
		cout << "Enter the processing mode: 0 - exit, 1 - add person data, 2 - sort records, 3 - copy person\'s data, 4 - change person\'s data, 5 - delete person\'s data, 6 - clear the container, 7 - show all list, 8 - search for person by zodiac sign, 9 - search for person by another characteristic,  10 - load data to a file, 11 - load data from a file." << endl;
		try
		{
			cin >> mode;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		cout << endl;
		if (mode < 0 || mode>11)
		{
			cout << "Entered uncorrect mode. Try entering the mode number again." << endl;
			continue;
		}
		switch (mode)
		{
		case 1:
			cin >> cont1;
			break;
		case 2:
			cout << "Enter a sort mode: 0 - in ascending order, 1 - in descending order." << endl;
			try
			{
				cin >> sortMode;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			try 
			{
				cont1.sort(sortMode);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 3:
			cout << "Enter a position of the copied element: " << endl;
			try
			{
				cin >> copied;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			cout << "Enter a position to insert element: " << endl;
			try
			{
				cin >> toCopy;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			try
			{
				cont1.copy(copied, toCopy);
			}
			catch (int)
			{
				cout << "Copied element not found" << endl;
			}
			break;
		case 4:
			cout << "Enter the number of the processed element." << endl;//Надо вставлять в keeper::changeEl по логике?
			try
			{
				cin >> num;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			cout << endl;
			try
			{
				cont1.changeEl(num);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			catch (double)
			{
				cout << "Element not found" << endl;
			}
			break;
		case 5:
			cout << "Enter number of deleting position." << endl;
			try
			{
				cin >> num;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			cout << endl;
			try
			{
				cont1.del(num);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			catch (double)
			{
				cout << "Element not found" << endl;
			}
			break;
		case 6:
			cont1.clear();
			cout << "The list is empty" << endl;
			break;
		case 7:
			try
			{
				cout << cont1;
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 8:
			cout << "Enter zodiac sign for search: " << endl;
			try
			{
				cin >> searchS;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			try
			{
				cont1.search(searchS, 2);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 9:
			cout << "Enter person\'s characteristic for search: 1 - name, 2 - surname, 3 - birth day, 4 - birth month, 5 - birth year." << endl;
			try
			{
				cin >> charMode;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			if (charMode < 0 || charMode>11)
			{
				cout << "Entered uncorrect mode. Try entering the mode number again." << endl;
				continue;
			}
			cout << "Enter key value: " << endl;
			if (charMode < 3)
			{
				try
				{
					cin >> searchS;
					if (cin.bad() || cin.fail())
					{
						throw buffErr;
					}
				}
				catch (char*)
				{
					exit(1);
				}
				try 
				{
					cont1.search(searchS, charMode - 1);
				}
				catch (int)
				{
					cout << "The list is empty" << endl;
				}
			}
			else
			{
				try
				{
					cin >> searchDate;
					if (cin.bad() || cin.fail())
					{
						throw buffErr;
					}
				}
				catch (char*)
				{
					exit(1);
				}
				try
				{
					cont1.search(searchDate, charMode - 3);
				}
				catch (int)
				{
					cout << "The list is empty" << endl;
				}

			}
			break;
		case 10:
			cout << "Enter a file name or path with name:" << endl;
			try
			{
				cin >> filename;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			try
			{
				cont1.loadToFile(filename);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 11:
			cout << "Enter a file name or path with name:" << endl;
			try
			{
				cin >> filename;
				if (cin.bad() || cin.fail())
				{
					throw buffErr;
				}
			}
			catch (char*)
			{
				exit(1);
			}
			cont1.loadFromFile(filename);
			break;
		}
	} while (mode != 0);
	
	delete[] searchS;
	delete[] filename;
}

void procSenten(void)
{
	char* buf;
	char* filename;
	char* s;
	char* e;
	char temp;
	int senStart = 0;
	int toLoad = 0;
	ifstream inFile;
	ofstream outFile;
	if (!inFile)
	{
		cout << "File opening error" << endl;
		return;
	}
	char buffErr[] = "Error of the input buffer";
	try
	{
		buf = new char[BUFLEN];
		filename = new char[FIELDSIZE];
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		exit(-1);
	}
	cout << endl;
	cout << "Enter a file name or path with name:" << endl;
	try
	{
		cin >> filename;
		if (cin.bad() || cin.fail())
		{
			throw buffErr;
		}
	}
	catch (char*)
	{
		exit(1);
	}
	inFile.open(filename, ios::in);
	inFile.get(buf, BUFLEN, EOF);
	cout << "Sentences with \'?\' on end:" << endl;
	cout << endl;
	s = buf;
	e = buf;
	while (*e)
	{
		if (isupper(*e) && senStart)
		{
			s = e;
			senStart = 0;
		}
		if (*e == '?')
		{
			temp = *(e + 1);
			*(e + 1) = '\0';
			cout << s;
			cout << endl;
			*(e + 1) = temp;
			s = e + 1;
			senStart = 1;
		}
		if (*e == '.' || *e == '!')
		{
			senStart = 1;
		}
		e++;
	}
	cout << endl;
	cout << "Sentences with \'!\' on end:" << endl;
	cout << endl;
	s = buf;
	e = buf;
	while (*e)
	{
		if (isupper(*e) && senStart)
		{
			s = e;
			senStart = 0;
		}
		if (*e == '!')
		{
			temp = *(e + 1);
			*(e + 1) = '\0';
			cout << s;
			cout << endl;
			*(e + 1) = temp;
			s = e + 1;
			senStart = 1;
		}
		if (*e == '.' || *e == '?')
		{
			senStart = 1;
		}
		e++;
	}
	cout << endl;
	cout << "Load result in file? 0 - yes, 1 - no." << endl;
	try
	{
		cin >> toLoad;
		if (cin.bad() || cin.fail())
		{
			throw buffErr;
		}
	}
	catch (char*)
	{
		exit(1);
	}
	if (!toLoad)
	{
		cout << endl;
		cout << "Enter a file name or path with name:" << endl;
		try
		{
			cin >> filename;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		outFile.open(filename, ios::out | ios::trunc);
		outFile << "Sentences with \'?\' on end:" << endl;
		outFile << endl;
		s = buf;
		e = buf;
		while (*e)
		{
			if (isupper(*e) && senStart)
			{
				s = e;
				senStart = 0;
			}
			if (*e == '?')
			{
				temp = *(e + 1);
				*(e + 1) = '\0';
				outFile << s;
				outFile << endl;
				*(e + 1) = temp;
				s = e + 1;
				senStart = 1;
			}
			if (*e == '.' || *e == '!')
			{
				senStart = 1;
			}
			e++;
		}
		outFile << endl;
		outFile << "Sentences with \'!\' on end:" << endl;
		outFile << endl;
		s = buf;
		e = buf;
		while (*e)
		{
			if (isupper(*e) && senStart)
			{
				s = e;
				senStart = 0;
			}
			if (*e == '!')
			{
				temp = *(e + 1);
				*(e + 1) = '\0';
				outFile << s;
				outFile << endl;
				*(e + 1) = temp;
				s = e + 1;
				senStart = 1;
			}
			if (*e == '.' || *e == '?')
			{
				senStart = 1;
			}
			e++;
		}
		outFile.close();
	}
	inFile.close();
	delete[] buf;
	delete[] filename;

}

bool passCheck(void)
{
	int attempts = 0;
	int strLen = 20;
	char* attStr = nullptr;
	char* password = nullptr;
	char* str = nullptr;
	ifstream passFile("password.txt", ios::in);
	char buffErr[] = "Error of the input buffer";
	try
	{
		password = new char[strLen];
		attStr = new char[strLen];
		str = new char[strLen];
	}
	catch (bad_alloc)
	{
		cout << "Error of the operator \"new\"" << endl;
		delete[] attStr;
		delete[] password;
		delete[] str;
		return false;
	}
	if (!passFile)
	{
		cout << "File opening error" << endl;
		delete[] attStr;
		delete[] password;
		delete[] str;
		return false;
	}
	passFile.getline(password, 20);
	passFile.getline(attStr, 20);
	attempts = atoi(attStr);
	while (attempts--)
	{
		cout << "Enter password: " << endl;
		try
		{
			cin >> str;
			if (cin.bad() || cin.fail())
			{
				throw buffErr;
			}
		}
		catch (char*)
		{
			exit(1);
		}
		if (!strcmp(str, password))
		{
			cout << "The password is correct!" << endl;
			passFile.close();
			delete[] str;
			delete[] password;
			return true;
		}
		else if(attempts)
		{
			cout << "The password is not correct. You have " << attempts << " input attempts left." << endl;
		}
	}
	cout << "Number of attempts completed." << endl;
	delete[] attStr;
	delete[] str;
	delete[] password;
	passFile.close();
	return false;
}