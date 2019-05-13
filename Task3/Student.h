#pragma once
#include <string>

class Student
{
public:
	Student();
	~Student();

private:
	int id;                    // идентификатор
	std::string FamilyName;    // автор
	std::string Name;          // название
	int age;                   // код книги
	int GroupName;             // количество страниц
};

