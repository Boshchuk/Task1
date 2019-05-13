#include <iostream>
#include <string>

#include "Node.h"
#include <forward_list>

#include <windows.h>

// определение констант для работы с меню выбора списка
#define CHOICE_STUDENTS   1
#define CHOICE_BOOKS      2
#define CHOICE_SHOP_ITEMS 3
#define CHOICE_EXIT       4


//
int main()
{
	// поддержка "русской" локали
	setlocale(LC_ALL, "ru-Ru");

	// поддержка ввода и вывода русских символов при помощи <windows.h>
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	do
	{
		std::cout << "Выберите список для работы" << std::endl;
		std::cout << "1 - Список студентов"       << std::endl;
		std::cout << "2 - Список книг"            << std::endl;
		std::cout << "3 - Товар"                  << std::endl;
		std::cout << "4 - Выход" << std::endl;

		std::cout << "Выбор: ";
		std::cin >> choice;

		switch (choice)
		{
		case CHOICE_STUDENTS:
			// Запуск работы 
			std::cout << "Выбран список студентов: ";

			// отображаем список
			break;

		case CHOICE_BOOKS:
			// Запуск работы 
			std::cout << "Выбран список книг: ";

			// отображаем список
			
			break;

		case CHOICE_SHOP_ITEMS:

			// Запуск работы 
			std::cout << "Выбран список товаров: ";

			// отображаем список

			// exit
			break;

		case CHOICE_EXIT:
			// Запуск работы 
			std::cout << "Выход....";
			break;

		default:
			std::cout << "Недопустимый выбор." << std::endl;
		}
	} while (choice != 4);


	/*std::forward_list<int> mylist = { 10, 20, 30 };
	mylist.clear();*/
}


