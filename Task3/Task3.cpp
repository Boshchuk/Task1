#include <iostream>
#include <string>

#include "Node.h"
#include <forward_list>

#include <windows.h>

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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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


	/*std::forward_list<int> mylist = { 10, 20, 30 };
	mylist.clear();*/
}


