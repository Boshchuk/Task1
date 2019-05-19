#include "Book.h"
#include <iostream>

book::book()
{
	this->author_     = "";
	this->title_      = "";
	this->page_count_ = 0;
	this->code_       = 0;
}

// ����������� ���������������� ���� ���������� ����������
book::book(std::string author,
	std::string title,
	int code,
	int page_count)
	: author_(std::move(author)),
		title_(std::move(title)),
		code_(code),
		page_count_(page_count)
{
}

void book::print() const
{
	std::cout   << "�����: "                << author_
				<< ", ��������: "           << title_
				<< ", ���: "                << code_
				<< ", ���������� �������: " << page_count_<< std::endl;
}

void book::input_data()
{
	std::string choice;

	std::cout << "������� ������: ";
	std::cin >> choice;
	std::cout << std::endl;
	author_ = choice;

	std::cout << "������� ��������: ";
	std::cin >> choice;
	std::cout << std::endl;
	title_ = choice;

	std::cout << "������� ���: ";
	std::cin >> code_;

	std::cout << "������� ���-�� �������: ";
	std::cin >> page_count_;
}

bool book::operator==(const book& other) const
{
	return (this->author_     == other.author_
		 && this->title_      == other.title_
		 && this->page_count_ == other.page_count_
		 && this->code_       == other.code_);
}
