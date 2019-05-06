#include <iostream>

using namespace std;

// стек работающий с телыми числами типа int
struct Stack
{

private:
	// указатель на хранилище данных
	int* items{};

	// свойства стека:
	int MAX_SIZE{}; // ёмкость
	int length{};         // количество элементов

private:

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
	void push(int);
	void pop();
	int top() const;
	

	/* Конструктор по умолчанию */
	Stack(int n = 20)
		//: MAX_SIZE{ n },
		//items{ new int[MAX_SIZE] }
	{
		MAX_SIZE = n;
		items = new int[MAX_SIZE];
		length = 0;
	}

	// деструктор (для освобождения памяти указателя)
	~Stack()
	{
		items = nullptr;
		delete[] items;
	}
};

void PrintArray(int* arr, int size);

void InverArray(int* arr, int size);

// функция main()
int main()
{
	int size;
	cout << "Input Array Size: ";
	cin >> size;
	cout << endl;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Input element[" << i << "]: ";
		cin >> array[i];
	}
	cout << endl;

	cout << "Array:" << endl;
	PrintArray(array, size);

	int choice;
	do
	{
		cout << endl;
		cout << "1 - Invert array." << endl;
		cout << "2 - Create new array." << endl;
		cout << "3 - Exit." << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			// инвентирование исходного массива и вывод его в косоль

			// инвентируем массив
			InverArray(array, size);

			cout << "Inverted Array:" << endl;
			// Выводим содержимое массива после инвертирования
			PrintArray(array, size);
			break;

		case 2:
			// создание ногово массива и вывод его в консоль
			cout << "Input Array Size: ";
			cin >> size;
			cout << endl;

			array = new int[size];

			for (int i = 0; i < size; i++)
			{
				cout << "Input element[" << i << "]: ";
				cin >> array[i];
			}
			cout << endl;

			cout << "Array:" << endl;
			PrintArray(array, size);
			break;

		case 3:
			// exit
			break;

		default:
			cout << "An Invalid choice." << endl;
		}
	} while (choice != 3);

	array = nullptr;
	delete[] array;

	return 0;
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}

// Инвентирует массив с исмпользованием структуры данных СТЭК
void InverArray(int* arr, int size)
{
	// создаем стэк размером массива
	Stack st( size );

	// поочередно добавляем элементы массива в стэк
	for (int i = 0; i < size; i++)
	{
		st.push(arr[i]);
	}

	// записываем элеметы стека в массив

	for (int i = 0; i < size; i++)
	{
		// присваиваем "верхний" - последний элемент СТЭКА
		arr[i] = st.top();
		// удаляем последний элемент стека
		st.pop();
	}

	// вызываем деструктор, что бы освободить память.
	st.~Stack();
}

// реализации методов структуры
void Stack::push(int item)
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

void Stack::pop()
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

int Stack::top() const
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