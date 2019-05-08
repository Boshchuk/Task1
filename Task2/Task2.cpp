// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

//���������� ����� � ����������� ���������� ������
template <typename T>
struct Stack
{

private:
	// ��������� �� ��������� ������
	T* items{};

	// �������� �����:
	int MAX_SIZE{}; // �������
	int length{};   // ���������� ���������

public:
	bool isFull() const
	{
		return (length == MAX_SIZE);
	};
	bool isEmpty() const
	{
		return (length == 0);
	};

public:
	// ������ ����� (���������)
	void push(T);
	void pop();
	T top() const;


	/* ����������� �� ��������� */
	Stack(int n = 20)
	{
		MAX_SIZE = n;
		items = new T[MAX_SIZE];
		length = 0;
	}

	// ���������� (��� ������������ ������ ���������)
	~Stack()
	{
		items = nullptr;
		delete[] items;
	}
};


bool isBalanced(const string str);
bool isOpeningBracket(char);
bool isClosingBracket(char);
char openingBracket(char);

bool isExitString(std::string input);

int main()
{
	// ��������� "�������" ������
	setlocale(LC_ALL, "ru-Ru"); 

	// ��������� ����� � ������ ������� �������� ��� ������ <windows.h>
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string choice;
	auto isExit = false;
	do
	{
		cout << endl;
		cout << "������� ������������ ������.";
		cout << "����� ����� �� ���������� �������: e(xit)" << endl;

		// ��������� ���� ������������ 
		getline(cin, choice);

		isExit = isExitString(choice);
		
		// ������ �������� ������ ���� ��� ������ �� ������� ��� ������
		if (isExit == false) {
			cout << (isBalanced(choice)
				? "������������� ������"
				: "������������� ������")
				<< endl;
		}

	} while (isExit == false);

	// �������� ���������� ���������
	return EXIT_SUCCESS;
}

// �������� ������ �� ������ ����������� � ����������� ������
// 
// ������ ��� ������ - ������������� ������
// ������ ������     - ������������� ������
// ������ a[a]a      - ������������� ������
// ������ [{]}       - ������������� ������
// ������ ))((       - ������������� ������
bool isBalanced(const string str)
{
	Stack<char> stk;
	auto length = str.length();
	for (int i=0; i<length; ++i)
	{
		// ��������� �������� �� ������ ������������� �������
		if (isOpeningBracket(str[i])) {
			// ���� ��������, �������� � ����
			stk.push(str[i]);
		}
		// ��������� �������� �� ����������� ������������������ ���������
		else  {
			auto indexOfNext = i + 1;
			if (str[i] == ':' && (indexOfNext < length) && str[indexOfNext] == ')') {
				// ������ �������. ����������� �������� ����� �������, ��� �� ��� ����������
				i++;
				// ��������� � ��������� ����������
				continue;
			}
			// ��������� �������� �� ������� ������������� �������
			else if (isClosingBracket(str[i]))
			{
				// ���� ������� ����������� ������,
				// � ���� ���� ��� ���������� ����� �������� ������ ��� ��������������� ��������
				// ������ ���������� ������ ������������������
				if (stk.isEmpty() || stk.top() != openingBracket(str[i])) {
					return false;
				}
				else {
					stk.pop();
				}
			}
		}
	}

	return stk.isEmpty();
}

// �������� �� ������ ����� �� �������� ������������ ������������� ������
bool isOpeningBracket(char ch)
{
	switch (ch)
	{
	case '(':
	case '{':
	case '[':
	case '<':
		return true;

	default:
		return false;
	}
}

// �������� �� ������ ����� �� �������� 
bool isClosingBracket(char ch)
{
	switch (ch)
	{
	case ')':
	case '}':
	case ']':
	case '>':
		return true;

	default:
		return false;
	}
}

// ����������� �������� ������ ��������
char openingBracket(char ch)
{
	switch (ch)
	{
	case ')':
		return '(';

	case '}':
		return '{';

	case ']':
		return '[';

	case '>':
		return '<';

	default:
		return 0;
	}
}

bool isExitString(std::string input) {

	std::for_each(input.begin(), input.end(), [](char& c) {
		c = ::tolower(c);
	});

	if (input.compare("exit") == 0)
	{
		return true;
	}
	if (input.compare("e") == 0)
	{
		return true;
	}

	return false;
}

// ���������� ������� ���������
template <typename T>
void Stack<T>:: push(T item)
{
	if (isFull())
	{
		cout << "Stack is full";
	}
	else
	{
		items[length] = item;
		length++;
	}
}

template <typename T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty";
		return;
	}
	else
	{
		items[length] = NULL;
		length--;
		return;
	}
}

template <typename T>
T Stack<T>::top() const
{
	if (isEmpty())
	{
		// ��������� ����������
		cout << "Top in null";
		exit(EXIT_FAILURE);
	}
	else
	{
		return items[length - 1];
	}
}

