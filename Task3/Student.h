#pragma once
#include <string>

class Student
{
public:
	Student();
	~Student();

private:
	int id;                    // �������������
	std::string FamilyName;    // �����
	std::string Name;          // ��������
	int age;                   // ��� �����
	int GroupName;             // ���������� �������
};

