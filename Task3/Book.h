#pragma once
#include <string>

class Book
{
public:
	Book();
	//~Book();

	// ����� � ������� ���������� � �����
	void Print() const;

private:
	int id;                // �������������
	std::string author;    // �����
	std::string title;     // ��������
	int code;              // ��� �����
	int pageCount;         // ���������� �������
};

