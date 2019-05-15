#include "Book.h"
#include <iostream>

book::book()
{
	this->author_     = "";
	this->title_      = "";
	this->page_count_ = 0;
	this->code_       = 0;
	this->id_         = 0;
}

// Конструктор инициализирующий поля значениями параметров
book::book(std::string author,
	std::string title,
	int code,
	int page_count)
	: id_(0), author_(std::move(author)), title_(std::move(title)), code_(code), page_count_(page_count)
{
}

void book::print() const
{
	std::cout << "Автор: " << author_ << ", Название: " << std::endl;
}
