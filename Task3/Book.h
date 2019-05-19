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

	// вывод в консоль информации о книге
	void print() const;
	void input_data();

	bool operator ==(const book& other) const;

private:
	std::string author_;     // автор
	std::string title_;      // название
	int code_;               // код книги
	int page_count_;         // количество страниц
};

