#include <iostream>
#include "LinkedList.h"
#include "Book.h"


//#include <windows.h>

// ����������� �������� ��� ������ � ���� ������ ������
#define CHOICE_STUDENTS   1
#define CHOICE_BOOKS      2
#define CHOICE_SHOP_ITEMS 3
#define CHOICE_EXIT       4

//
int main()
{
	// ��������� "�������" ������
	setlocale(LC_ALL, "ru-Ru");

	// ��������� ����� � ������ ������� �������� ��� ������ <windows.h>
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	auto list = new linked_list<book>();


	const auto book1 = new book("a1", "a11", 1, 1);
	const auto book2 = new book("a2", "a22", 2, 2);


	list->append(*book1);
	list->append(*book2);

	list->print();


	int choice;
	do
	{
		std::cout << "�������� ������ ��� ������" << std::endl;
		std::cout << "1 - ������ ���������"       << std::endl;
		std::cout << "2 - ������ ����"            << std::endl;
		std::cout << "3 - �����"                  << std::endl;
		std::cout << "4 - �����" << std::endl;

		std::cout << "�����: ";
		std::cin >> choice;

		switch (choice)
		{
		case CHOICE_STUDENTS:
			// ������ ������ 
			std::cout << "������ ������ ���������: ";

			// ���������� ������
			break;

		case CHOICE_BOOKS:
			// ������ ������ 
			std::cout << "������ ������ ����: ";

			// ���������� ������
			
			break;

		case CHOICE_SHOP_ITEMS:

			// ������ ������ 
			std::cout << "������ ������ �������: ";

			// ���������� ������

			// exit
			break;

		case CHOICE_EXIT:
			// ������ ������ 
			std::cout << "�����....";
			break;

		default:
			std::cout << "������������ �����." << std::endl;
		}
	} while (choice != 4);

	return EXIT_SUCCESS;
}


