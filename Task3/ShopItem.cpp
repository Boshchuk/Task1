#include "ShopItem.h"
#include <iostream>


shop_item::shop_item()
{
	this->title_       = "";
	this->description_ = "";
	this->item_code_   = 0;
	this->quantity_    = 0;
}

shop_item::shop_item(
	std::string title,
	std::string description,
	int item_code,
	int quantity)
: 
title_(std::move(title)),
description_(std::move(description)),
item_code_(item_code),
quantity_(quantity)
{
}

void shop_item::print() const
{
	std::cout << "Название: " << this->title_
		<< ", Описание: "     << this-> description_
		<< ", Код: "          << this->item_code_
		<< ", Количество: "   << this->quantity_ << std::endl;
}

void shop_item::input_data()
{
	std::string choice;

	std::cout << "Введите Название: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->title_ = choice;

	std::cout << "Введите Описание: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->description_ = choice;

	std::cout << "Введите Код: ";
	std::cin >> this->item_code_;

	std::cout << "Введите Количество: ";
	std::cin >> this->quantity_;
}

bool shop_item::operator==(const shop_item& other) const
{
	return (this->description_ == other.description_
		&& this->title_ == other.title_
		&& this->item_code_ == other.item_code_
		&& this->quantity_ == other.quantity_);
}
