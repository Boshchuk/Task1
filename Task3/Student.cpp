#include "Student.h"
#include <iostream>


void student::print() const
{
	std::cout << "�������: " << this->family_name_
		<< ", ���: " << this->name_
		<< ", �������: " << this->age_
		<< ", ����� ������: " << this->group_number_ << std::endl;
}

void student::input_data()
{
	std::string choice;

	std::cout << "������� �������: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->family_name_ = choice;

	std::cout << "������� ���: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->name_ = choice;

	std::cout << "������� �������: ";
	std::cin >> this->age_;

	std::cout << "������� ����� ������: ";
	std::cin >> this->group_number_;
}

bool student::operator==(const student& other) const
{
	return (this->family_name_ == other.family_name_
		&& this->name_ == other.name_
		&& this->age_ == other.age_
		&& this->group_number_ == other.group_number_);
}