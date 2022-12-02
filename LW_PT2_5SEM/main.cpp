#include <iostream>
#include <fstream>
#include "Keeper.h"
//#include "Keeper.cpp"
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

//ОПТИМИЗАЦИЯ В ПОИСКЕ, ПРОВЕРКА ЗНАКА ЗОДИАКА, ПРОПУСКИ МЕЖДУ СТРОКАМИ, ВЫБОР СОРТ ВОЗРАС УБЫВАНИЕ, 
//ПОСМОТРЕТЬ НА try-catch, проверка на пустой список в перегр операторе [] и sort(), номера функций в switch-case части 1,

void procSignList(void);
void procSenten(void);

int main(void)
{
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
	int num = 0;
	int copied = 0;
	int toCopy = 0;
	char buffErr[] = "Error of the input buffer";
	do
	{
		cout << endl;
		cout << "Enter the processing mode: 0 - exit, 1 - add person data, 2 - sort records, 3 - , 4 - copy person\'s data, 5 - change person\'s data, 6 - delete person\'s data, 7 - clear the container, 8 - show all list, 9 - search for person by zodiac sign, 10 - search for person by another characteristic,  11 - load data to a file, 12 - load data from a file." << endl;
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
		switch (mode)
		{
		case 1:
			cin >> cont1;
			break;
		case 2:
			cont1.sort();
			break;
		case 3:
			
			break;
		case 4:
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
		case 5:
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
		case 6:
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

			/*
			keeper g2 = cont1;
			g2.show();
			int a = 5;*/
			break;
		case 7:
			cont1.clear();
			cout << "The list is empty" << endl;
			break;
		case 8:
			try
			{
				cout << cont1;
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 9:
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
		case 10:
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
			try
			{
				//garage.txt
				cont1.loadToFile(filename);
			}
			catch (int)
			{
				cout << "The list is empty" << endl;
			}
			break;
		case 12:
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
	
	inFile.close();
	delete[] buf;
	delete[] filename;

}