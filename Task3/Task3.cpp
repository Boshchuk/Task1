#include <iostream>
#include "LinkedList.h"
#include "Book.h"
#include "ShopItem.h"
#include "Student.h"

class student;
// ����������� �������� ��� ������ � ����, ������� ��������� ������� ������ ��� ������
const int choice_students = 1;
const int choice_books = 2;
const int choice_shop_items = 3;
const int choice_exit = 4;

// ��������� ��� ������ � ��������� ������
const int create_list = 1;
const int add_to_begining = 2;
const int add_to_end = 3;
const int add_after_cpecified = 4;
const int find_element = 5;
const int remove_element = 6;
const int clear_all = 7;
const int return_back = 0;


// �������� ���� ������ �� ������� ������ T
template <class T>
void list_menu(linked_list<T>* work_list);

//
int main()
{
	// ��������� "�������" ������
	setlocale(LC_ALL, "ru-Ru");

	// ������ ��� ������ � ���������� ������
	auto list_of_books      = new linked_list<book>();
	auto list_of_students   = new linked_list<student>();
	auto list_of_shop_items = new linked_list<shop_item>();

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
			list_of_students->print();

			// ��������� ������
			list_menu<student>(list_of_students);
			
			break;

		case choice_books:
			// ������ ������ 
			std::cout << "������ ������ ����: " << std::endl;

			// ���������� ������
			list_of_books->print();

			// ��������� ������
			list_menu<book>(list_of_books);

			break;

		case choice_shop_items:

			// ������ ������ 
			std::cout << "������ ������ �������: ";

			// ���������� ������
			list_of_shop_items->print();

			// ��������� ������
			list_menu<shop_item>(list_of_shop_items);

			break;

		case choice_exit:
			// ������ ������ 
			// exit
			std::cout << "�����...." << std::endl;
			break;

		default:
			std::cout << "������������ �����." << std::endl;
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
		std::cout << std::endl;
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
				work_list = new linked_list<T>();
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

		case add_after_cpecified:
		{
			if (work_list == nullptr)
			{
				std::cout << "������� �������� ������!!!" << std::endl;
			}
			else
			{
				if (work_pointer == nullptr)
				{
					std::cout << "��� �������� ���������! ������� ����������� �������: ""����� ������� ������ (������� ���������)""" << std::endl;
				}
				else
				{
					std::cout << "������� ����� ����������� ����� ��������: " << std::endl;
					work_pointer->data.print();
					std::cout << "�� �������: " << work_pointer << std::endl;

					std::cout << "������� ���������� �� ������� ������� ����� ��������: " << std::endl;
					std::cout << std::endl;

					auto new_item = new T();

					new_item->input_data();

					work_list->insert(*new_item, work_pointer);
					// ���������� ������
					std::cout << "C�����: " << std::endl;
					work_list->print();
				}

			}
		}
		break;

		case remove_element:
		{
			if (work_list == nullptr)
			{
				std::cout << "������� �������� ������!!!" << std::endl;
			}
			else
			{
				if (work_pointer == nullptr)
				{
					std::cout << "��� �������� ���������! ������� ����������� �������: ""����� ������� ������ (������� ���������)""" << std::endl;
				}
				else
				{
					std::cout << "�������� ����� ����������� ����� ��������: " << std::endl;
					work_pointer->data.print();
					std::cout << "�� �������: " << work_pointer << std::endl;

					work_list->delete_item(work_pointer->data);
					// ���������� ������
					std::cout << "C����� ����� ��������: " << std::endl;
					work_list->print();
				}
			}
		}
		break;

		case find_element:

			if (work_list == nullptr)
			{
				std::cout << "������� �������� ������!!!" << std::endl;
			}
			else
			{
				std::cout << "������� ���������� ��� �� ����� �������: " << std::endl;
				std::cout << std::endl;

				auto new_item = new T();

				new_item->input_data();

				work_pointer = work_list->find(*new_item);

				if (work_pointer == nullptr)
				{
					std::cout << "������� �� ������" << std::endl;
				}
				else
				{
					std::cout << "���������: " << work_pointer << std::endl;
					std::cout << "��������� �������� ��� ������ (���������� ����� ��������� ��������): " << work_pointer << std::endl;
				}
			}
			break;

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