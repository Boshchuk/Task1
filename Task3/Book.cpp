#include "Book.h"
#include <iostream>

book::book()
{
	this->author_     = "";
	this->title_      = "";
	this->page_count_ = 0;
	this->code_       = 0;
}

// Конструктор инициализирующий поля значениями параметров
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
	std::cout   << "Автор: "                << author_
				<< ", Название: "           << title_
				<< ", Код: "                << code_
				<< ", Количество страниц: " << page_count_<< std::endl;
}

void book::input_data()
{
	std::string choice;

	std::cout << "Введите автора: ";
	std::cin >> choice;
	std::cout << std::endl;
	author_ = choice;

	std::cout << "Введите название: ";
	std::cin >> choice;
	std::cout << std::endl;
	title_ = choice;

	std::cout << "Введите Код: ";
	std::cin >> code_;

	std::cout << "Введите Кол-во старниц: ";
	std::cin >> page_count_;
}

bool book::operator==(const book& other) const
{
	return (this->author_     == other.author_
		 && this->title_      == other.title_
		 && this->page_count_ == other.page_count_
		 && this->code_       == other.code_);
}
