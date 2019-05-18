#include <iostream>
#include "LinkedList.h"
#include "Book.h"


//#include <windows.h>

// ����������� �������� ��� ������ � ���� ������ ������
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
	// ��������� "�������" ������
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
		std::cout << "�������� ������ ��� ������" << std::endl;
		std::cout << "1 - ������ ���������" << std::endl;
		std::cout << "2 - ������ ����" << std::endl;
		std::cout << "3 - �����" << std::endl;
		std::cout << "4 - �����" << std::endl;

		std::cout << "�����: ";
		std::cin >> choice;

		switch (choice)
		{
		case choice_students:
			// ������ ������ 
			std::cout << "������ ������ ���������: ";

			// ���������� ������
			break;

		case choice_books:
			// ������ ������ 
			std::cout << "������ ������ ����: " << std::endl;

			list_menu<book>();

			// ���������� ������

			break;

		case choice_shop_items:

			// ������ ������ 
			std::cout << "������ ������ �������: ";

			// ���������� ������


			break;

		case choice_exit:
			// ������ ������ 
			// exit
			std::cout << "�����....";
			break;

		default:
			std::cout << "������������ �����." << std::endl;
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
		std::cout << "������� ��� ������ �� �������" << std::endl;
		std::cout << "1 - ������� ������" << std::endl;
		std::cout << "    �������� �������:" << std::endl;
		std::cout << "2 -         � ������" << std::endl;
		std::cout << "3 -         � �����" << std::endl;
		std::cout << "4 -         ����� ��������� ��������" << std::endl;
		std::cout << "5 - ����� ������� ������ (������� ���������)" << std::endl;
		std::cout << "6 - ������� ������� ������" << std::endl;
		std::cout << "7 - ������� (��������) ������" << std::endl;
		std::cout << "0 - ���������" << std::endl;
		std::cout << "�����: ";
		std::cin >> choice;
		std::cout << std::endl;
		switch (choice)
		{
		case create_list:
			{
				// ������ ������ 
				std::cout << "������� �������� ������: ";

				if (work_list == nullptr)
				{
					work_list = new linked_list<book>();
					std::cout << "����� ������ ������: ";
				}
				else
				{
					std::cout << "������� ������ ��� ���������: ";
					// ���������� ������
					work_list->print();
				}

				break;
			}

		case add_to_begining:
		{
			if (work_list == nullptr)
			{
				std::cout << "������� �������� ������!!!" << std::endl;
			}
			else
			{
				std::cout << "���������� �������� � ������ ������: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_list->append(*new_item);
				// ���������� ������
				std::cout << "C�����: " << std::endl;
				work_list->print();
			}
			break;
		}

		case add_to_end:
		{
			if (work_list == nullptr)
			{
				std::cout << "������� �������� ������!!!" << std::endl;
			}
			else
			{
				std::cout << "���������� �������� � ����� ������: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_list->append(*new_item);

				// ���������� ������
				std::cout << "C�����: " << std::endl;
				work_list->print();
			}
			break;
		}

		case clear_all:
			if (work_list == nullptr)
			{
				std::cout << "������ ��� ��� ����" << std::endl;
			}
			else
			{
				std::cout << "�������� ������" << std::endl;
				work_list->clear();
			}
			break;

		case return_back:
			// ������ ������ 
			std::cout << "�����....";
			// exit
			break;

		default:
			std::cout << "������������ �����." << std::endl;
		}
	} while (choice != return_back);
}