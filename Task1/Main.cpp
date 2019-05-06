#include <iostream>

using namespace std;

// ���� ���������� � ������ ������� ���� int
struct Stack
{

private:
	// ��������� �� ��������� ������
	int* items{};

	// �������� �����:
	int MAX_SIZE{}; // �������
	int length{};         // ���������� ���������

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
	// ������ ����� (���������)
	void push(int);
	void pop();
	int top() const;
	

	/* ����������� �� ��������� */
	Stack(int n = 20)
		//: MAX_SIZE{ n },
		//items{ new int[MAX_SIZE] }
	{
		MAX_SIZE = n;
		items = new int[MAX_SIZE];
		length = 0;
	}

	// ���������� (��� ������������ ������ ���������)
	~Stack()
	{
		items = nullptr;
		delete[] items;
	}
};

void PrintArray(int* arr, int size);

void InverArray(int* arr, int size);

// ������� main()
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
			// �������������� ��������� ������� � ����� ��� � ������

			// ����������� ������
			InverArray(array, size);

			cout << "Inverted Array:" << endl;
			// ������� ���������� ������� ����� ��������������
			PrintArray(array, size);
			break;

		case 2:
			// �������� ������ ������� � ����� ��� � �������
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

// ����������� ������ � ��������������� ��������� ������ ����
void InverArray(int* arr, int size)
{
	// ������� ���� �������� �������
	Stack st( size );

	// ���������� ��������� �������� ������� � ����
	for (int i = 0; i < size; i++)
	{
		st.push(arr[i]);
	}

	// ���������� ������� ����� � ������

	for (int i = 0; i < size; i++)
	{
		// ����������� "�������" - ��������� ������� �����
		arr[i] = st.top();
		// ������� ��������� ������� �����
		st.pop();
	}

	// �������� ����������, ��� �� ���������� ������.
	st.~Stack();
}

// ���������� ������� ���������
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
		// ��������� ����������
		cout << "Top in null";
		exit(EXIT_FAILURE);
	}
	else
	{
		return items[length - 1];
	}
}