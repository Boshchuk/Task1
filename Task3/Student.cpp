#include "Student.h"
#include <iostream>


void student::print() const
{
	std::cout << "Фамилия: " << this->family_name_
		<< ", Имя: " << this->name_
		<< ", Возраст: " << this->age_
		<< ", Номер группы: " << this->group_number_ << std::endl;
}

void student::input_data()
{
	std::string choice;

	std::cout << "Введите Фамилию: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->family_name_ = choice;

	std::cout << "Введите Имя: ";
	std::cin >> choice;
	std::cout << std::endl;
	this->name_ = choice;

	std::cout << "Введите Возраст: ";
	std::cin >> this->age_;

	std::cout << "Введите Номер группы: ";
	std::cin >> this->group_number_;
}

bool student::operator==(const student& other) const
{
	return (this->family_name_ == other.family_name_
		&& this->name_ == other.name_
		&& this->age_ == other.age_
		&& this->group_number_ == other.group_number_);
}