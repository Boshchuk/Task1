#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

//реализация стека с абстрактной структурой данных
template <typename T>
struct Stack
{

private:
	// указатель на хранилище данных
	T* items{};

	// свойства стека:
	int MAX_SIZE{}; // ёмкость
	int length{};   // количество элементов

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
	// методы стэка (интерфейс)
	void push(T);
	void pop();
	T top() const;


	/* Конструктор по умолчанию */
	Stack(int n = 20)
	{
		MAX_SIZE = n;
		items = new T[MAX_SIZE];
		length = 0;
	}

	// деструктор (для освобождения памяти указателя)
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
	// поддержка "русской" локали
	setlocale(LC_ALL, "ru-Ru"); 

	// поддержка ввода и вывода русских символов при помощи <windows.h>
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string choice;
	auto isExit = false;
	do
	{
		cout << endl;
		cout << "Введите произвольную строку.";
		cout << "Чтобы выйти из приложения введите: e(xit)" << endl;

		// считываем ввод пользователя 
		getline(cin, choice);

		isExit = isExitString(choice);
		
		// делаем проверку строки если эта строка не команда для выхода
		if (isExit == false) {
			cout << (isBalanced(choice)
				? "Положительный баланс"
				: "Отрицательный баланс")
				<< endl;
		}

	} while (isExit == false);

	// успешное завершение программы
	return EXIT_SUCCESS;
}

// проверка строки на баланс открывающий и закрывающих скобой
// 
// строка без скобок - положительный баланс
// пустая строка     - положительный баланс
// строка a[a]a      - положительный баланс
// строка [{]}       - отрицательный баланс
// строка ))((       - отрицательный баланс
bool isBalanced(const string str)
{
	Stack<char> stk;
	auto length = str.length();
	for (int i=0; i<length; ++i)
	{
		// проверяем является ли символ открывающейся скобкой
		if (isOpeningBracket(str[i])) {
			// если является, помещяем в стек
			stk.push(str[i]);
		}
		// проверяем является ли последующая последовательность смайликом
		else  {
			auto indexOfNext = i + 1;
			if (str[i] == ':' && (indexOfNext < length) && str[indexOfNext] == ')') {
				// найден смайлик. уведичиваем итератор таким образом, что бы его пропустить
				i++;
				// переходим к следующим эелементам
				continue;
			}
			// проверяем является ли элемент закрывающейся скобкой
			else if (isClosingBracket(str[i]))
			{
				// если элемент закрывающая скобка,
				// а стек пуст или помещенной ранее открытой скобке нет соответствующей закрытой
				// считам количество скобой несбалансированным
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

// является ли символ одним из символов определяющих открывающуюся скобку
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

// является ли символ одним из сивмолов 
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

// соответсвие открытой скобки закрытой
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

// реализации методов структуры
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
		// аварийное завершение
		cout << "Top in null";
		exit(EXIT_FAILURE);
	}
	else
	{
		return items[length - 1];
	}
}

