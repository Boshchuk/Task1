#pragma once
#include <string>

class shop_item
{
public:
	shop_item();
	shop_item(
		std::string title,       // ������������
		std::string description, // �������� 
		int item_code,			  // ��� ������
		int quantity			  // ����������
	);

	// ����� � ������� ���������� � �����
	void print() const;
	void input_data();

	bool operator ==(const shop_item& other) const;

private:
	std::string title_;       // ������������
	std::string description_; // �������� 
	int item_code_;			  // ��� ������
	int quantity_;			  // ����������
};

