#include <iostream>
#include "LinkedList.h"
#include "Book.h"


//#include <windows.h>

// определение констант для работы с меню выбора списка
const int choice_students      = 1;
const int choice_books         = 2;
const int choice_shop_items    = 3;
const int choice_exit          = 4;

const int create_list          = 1;
const int add_to_begining      = 2;
const int add_to_end           = 3;
const int add_after_cpecified  = 4;
const int find_element         = 5;
const int remove_element       = 6;
const int clear_all            = 7;
const int return_back          = 0;


template <class T>
void list_menu();

//
int main()
{
	// поддержка "русской" локали
	setlocale(LC_ALL, "ru-Ru");

	auto list = new linked_list<book>();


	const auto book1 = new book("a1", "a11", 1, 1);
	const auto book2 = new book("a2", "a22", 2, 2);
	const auto book3 = new book("a3", "a23", 3, 3);


	list->append(*book1);
	list->append(*book2);

	auto result = list->find(*book1);

	auto result2 = list->insert(*book3, result);

	list->print();
	list->clear();
	list->print();

	int choice;
	do
	{
		std::cout << "Выберите список для работы" << std::endl;
		std::cout << "1 - Список студентов" << std::endl;
		std::cout << "2 - Список книг" << std::endl;
		std::cout << "3 - Товар" << std::endl;
		std::cout << "4 - Выход" << std::endl;

		std::cout << "Выбор: ";
		std::cin >> choice;

		switch (choice)
		{
		case choice_students:
			// Запуск работы 
			std::cout << "Выбран список студентов: ";

			// отображаем список
			break;

		case choice_books:
			// Запуск работы 
			std::cout << "Выбран список книг: " << std::endl;

			list_menu<book>();

			// отображаем список

			break;

		case choice_shop_items:

			// Запуск работы 
			std::cout << "Выбран список товаров: ";

			// отображаем список


			break;

		case choice_exit:
			// Запуск работы 
			// exit
			std::cout << "Выход....";
			break;

		default:
			std::cout << "Недопустимый выбор." << std::endl;
		}
	} while (choice != choice_exit);

	return EXIT_SUCCESS;
}

template <class T>
void list_menu()
{
	linked_list<book>* work_list = nullptr;

	int choice;
	do
	{
		std::cout << "Команды для работы со списком" << std::endl;
		std::cout << "1 - Создать список" << std::endl;
		std::cout << "    добавить элемент:" << std::endl;
		std::cout << "2 -         в начало" << std::endl;
		std::cout << "3 -         в конец" << std::endl;
		std::cout << "4 -         после заданного элемента" << std::endl;
		std::cout << "5 - найти элемент списка (вернуть указатель)" << std::endl;
		std::cout << "6 - удалить элемент списка" << std::endl;
		std::cout << "7 - удалить (очистить) список" << std::endl;
		std::cout << "0 - Вернуться" << std::endl;
		std::cout << "Выбор: ";
		std::cin >> choice;
		std::cout << std::endl;
		switch (choice)
		{
		case create_list:
			{
				// Запуск работы 
				std::cout << "Выбрано создание списка: ";

				if (work_list == nullptr)
				{
					work_list = new linked_list<book>();
					std::cout << "Новый список создан: ";
				}
				else
				{
					std::cout << "Рабочий список уже ужествует: ";
					// отображаем список
					work_list->print();
				}

				break;
			}

		case add_to_begining:
		{
			if (work_list == nullptr)
			{
				std::cout << "Сначала создайте список!!!" << std::endl;
			}
			else
			{
				std::cout << "Добавление элемента в начало списка: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_list->append(*new_item);
				// отображаем список
				std::cout << "Cписок: " << std::endl;
				work_list->print();
			}
			break;
		}

		case add_to_end:
		{
			if (work_list == nullptr)
			{
				std::cout << "Сначала создайте список!!!" << std::endl;
			}
			else
			{
				std::cout << "Добавление элемента в конец списка: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_list->append(*new_item);

				// отображаем список
				std::cout << "Cписок: " << std::endl;
				work_list->print();
			}
			break;
		}

		case clear_all:
			if (work_list == nullptr)
			{
				std::cout << "Список уже был пуст" << std::endl;
			}
			else
			{
				std::cout << "Удаление списка" << std::endl;
				work_list->clear();
			}
			break;

		case return_back:
			// Запуск работы 
			std::cout << "Выход....";
			// exit
			break;

		default:
			std::cout << "Недопустимый выбор." << std::endl;
		}
	} while (choice != return_back);
}