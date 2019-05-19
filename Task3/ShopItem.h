#pragma once
#include <string>

class shop_item
{
public:
	shop_item();
	shop_item(
		std::string title,       // наименование
		std::string description, // описание 
		int item_code,			  // код товара
		int quantity			  // количество
	);

	// вывод в консоль информации о книге
	void print() const;
	void input_data();

	bool operator ==(const shop_item& other) const;

private:
	std::string title_;       // наименование
	std::string description_; // описание 
	int item_code_;			  // код товара
	int quantity_;			  // количество
};

