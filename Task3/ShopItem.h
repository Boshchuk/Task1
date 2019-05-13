#pragma once
#include <string>

class ShopItem
{
public:
	ShopItem();
	~ShopItem();


private:
	int id;                // идентификатор
	std::string title;
	std::string description;
	int itemCode;
	int quantity;
};

