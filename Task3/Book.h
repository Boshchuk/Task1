#pragma once
#include <string>

class book
{
public:
	book();
	book(std::string author,
		std::string title,
		int code,
		int page_count);

	// ����� � ������� ���������� � �����
	void print() const;

private:
	int id_;                 // �������������
	std::string author_;     // �����
	std::string title_;      // ��������
	int code_;               // ��� �����
	int page_count_;         // ���������� �������
};

