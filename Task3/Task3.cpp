#include <iostream>

template <class T>
struct Node {

};

template <class T>
class LinkedList {
public:
	// ���������� �� ���������. ������� ������ ������.
	LinkedList();

	// ����������
	~LinkedList();

	// ���������� ��������� ����������.
	const LinkedList<T>& operator = (const LinkedList<T>&);

	// ���������� �����������
	LinkedList(const LinkedList<T>& otherList);

	// ���������� true, ���� ������ �� ���� � false � ��������� ������
	bool isEmpty() const;

	// ������� ������ ������
	void print() const;

	// ����������� ���������� �������� � ������.
	int length() const;

	// ������� ��� ���� ������.
	// � ���������� ������: 
	//	first = nullprt,
	//	last = nullptr,
	//	cont = 0;
	void clear();

	// ���������� ������ ������� �������� ������
	T front() const;

	// ���������� ������ ���������� �������� ������.
	T end() const;

	// ��������� ������� � ������ ������.
	void prepend(const T& item);

	// ��������� ������� � ����� ������.
	void append(const T& item);

	// ��������� ������� item ����� �������� curr � ���������� ��������� �� ����.
	Node<T>* insert(const T& item, Node<T>* curr);

	// ���� � ������ ������� item � ���������� ��������� �� ���� �������.
	Node<T>* find(const T& item);

	// ���������� ��������� �� ������ ������� ������.
	Node<T>* beg();

	// ���������� ��������� �� ��������� ������� ������.
	Node<T>* end();

	// ������� ������� item �� ������.
	void delete(const T& item);

private:

	// �������, ��������� ����� ������ otherList.
	void copy(const LinkedList<T>& otherList);

	// ���-�� ��������� ������.
	int count;

	// ��������� �� ������ ������� ������.
	Node<T>* first;

	// ��������� �� ��������� ������� ������.
	Node<T>* last;
};


int main()
{
	std::cout << "Hello World!\n";
}

