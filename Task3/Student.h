#pragma once
#include <string>
#include <iostream>

class student
{
public:
	student();
	student(
		std::string family_name,   // фамилия
		std::string name,          // имя
		int age,                   // код возраз
		int group_number           // номер группы
	);

	// вывод в консоль информации о книге
	void print() const;
	void input_data();

	bool operator ==(const student& other) const;

private:
	std::string family_name_;   // фамилия
	std::string name_;          // имя
	int age_;                   // код возраз
	int group_number_; // номер группы
};

inline student::student()
{
	this->name_ = "";
	this->family_name_ = "";
	this->age_ = 0;
	this->group_number_ = 0;
}

inline student::student(
	std::string family_name,
	std::string name,
	int age,
	int group_number)
	: family_name_(std::move(family_name)),
	name_(std::move(name)),
	age_(age),
	group_number_(group_number)
{
}



