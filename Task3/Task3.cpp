#include <iostream>
#include "LinkedList.h"
#include "Book.h"
#include "ShopItem.h"
#include "Student.h"

class student;
// определение констант для работы с меню, которое позволяет выбрать списки для работы
const int choice_students = 1;
const int choice_books = 2;
const int choice_shop_items = 3;
const int choice_exit = 4;

// константы для работы с функциями списка
const int create_list = 1;
const int add_to_begining = 2;
const int add_to_end = 3;
const int add_after_cpecified = 4;
const int find_element = 5;
const int remove_element = 6;
const int clear_all = 7;
const int return_back = 0;


// вызывает меню работы со списком класса T
template <class T>
void list_menu(linked_list<T>* work_list);

//
int main()
{
	// поддержка "русской" локали
	setlocale(LC_ALL, "ru-Ru");

	// списки для работы с различными типами
	auto list_of_books      = new linked_list<book>();
	auto list_of_students   = new linked_list<student>();
	auto list_of_shop_items = new linked_list<shop_item>();

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
			list_of_students->print();

			// запускаем работу
			list_menu<student>(list_of_students);
			
			break;

		case choice_books:
			// Запуск работы 
			std::cout << "Выбран список книг: " << std::endl;

			// отображаем список
			list_of_books->print();

			// запускаем работу
			list_menu<book>(list_of_books);

			break;

		case choice_shop_items:

			// Запуск работы 
			std::cout << "Выбран список товаров: ";

			// отображаем список
			list_of_shop_items->print();

			// запускаем работу
			list_menu<shop_item>(list_of_shop_items);

			break;

		case choice_exit:
			// Запуск работы 
			// exit
			std::cout << "Выход...." << std::endl;
			break;

		default:
			std::cout << "Недопустимый выбор." << std::endl;
		}
	} while (choice != choice_exit);

	delete list_of_students;
	delete list_of_books;
	delete list_of_shop_items;

	return EXIT_SUCCESS;
}

template <class T>
void list_menu(linked_list<T>* work_list)
{
	node<T>* work_pointer = nullptr;
	std::cout << std::endl;
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
		std::cout << std::endl;
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
				work_list = new linked_list<T>();
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

		case add_after_cpecified:
		{
			if (work_list == nullptr)
			{
				std::cout << "Сначала создайте список!!!" << std::endl;
			}
			else
			{
				if (work_pointer == nullptr)
				{
					std::cout << "Нет рабочего указателя! Сначала используйте функцию: ""найти элемент списка (вернуть указатель)""" << std::endl;
				}
				else
				{
					std::cout << "Вставки будет произведена после элемента: " << std::endl;
					work_pointer->data.print();
					std::cout << "По адрессу: " << work_pointer << std::endl;

					std::cout << "Введите информацию об объекте который будет вставлен: " << std::endl;
					std::cout << std::endl;

					auto new_item = new T();

					new_item->input_data();

					work_list->insert(*new_item, work_pointer);
					// отображаем список
					std::cout << "Cписок: " << std::endl;
					work_list->print();
				}

			}
		}
		break;

		case remove_element:
		{
			if (work_list == nullptr)
			{
				std::cout << "Сначала создайте список!!!" << std::endl;
			}
			else
			{
				if (work_pointer == nullptr)
				{
					std::cout << "Нет рабочего указателя! Сначала используйте функцию: ""найти элемент списка (вернуть указатель)""" << std::endl;
				}
				else
				{
					std::cout << "Удаление будет произведено после элемента: " << std::endl;
					work_pointer->data.print();
					std::cout << "По адрессу: " << work_pointer << std::endl;

					work_list->delete_item(work_pointer->data);
					// отображаем список
					std::cout << "Cписок после удаления: " << std::endl;
					work_list->print();
				}
			}
		}
		break;

		case find_element:

			if (work_list == nullptr)
			{
				std::cout << "Сначала создайте список!!!" << std::endl;
			}
			else
			{
				std::cout << "Введите информацию что бы найти элемент: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_pointer = work_list->find(*new_item);

				if (work_pointer == nullptr)
				{
					std::cout << "Елемент не найден" << std::endl;
				}
				else
				{
					std::cout << "Указатель: " << work_pointer << std::endl;
					std::cout << "Указатель сохранен для работы (добавление после заданного элемента): " << work_pointer << std::endl;
				}
			}
			break;

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