#include <iostream>

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
			
			break;
		case 2:
			
			break;
		}

	} while (taskMode);
	return 0;
}