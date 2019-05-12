#pragma once
#include <string>

class Book
{
public:
	Book();
	//~Book();

	// вывод в консоль информации о книге
	void Print() const;

private:
	std::string author;    // автор
	std::string title;     // название
	int code;              // код книги
	int pageCount;         // количество страниц
};

