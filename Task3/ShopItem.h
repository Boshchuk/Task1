#pragma once
#include <string>

class ShopItem
{
public:
	ShopItem();
	~ShopItem();


private:
	int id;                // �������������
	std::string title;
	std::string description;
	int itemCode;
	int quantity;
};

