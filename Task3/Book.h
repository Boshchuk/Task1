#pragma once
#include <string>

class book
{
public:
	book();
	book(
		std::string author,
		std::string title,
		int code,
		int page_count);

	// ����� � ������� ���������� � �����
	void print() const;
	void input_data();

	bool operator ==(const book& other) const;

	

private:
	std::string author_;     // �����
	std::string title_;      // ��������
	int code_;               // ��� �����
	int page_count_;         // ���������� �������
};

