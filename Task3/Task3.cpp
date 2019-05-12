#include <iostream>
#include <string>

#include <forward_list>

using namespace std;

// ��������� ��������� �������������� ����
template <class _Type>
struct Node {

	_Type data;        // ������ ����

	Node<_Type>* next; // ��������� �� ��������� ����
	

	//Node(const Node&) = delete;
	//Node& operator=(const Node&) = delete;

	/*template <class _Alnode>
	static void _Freenode(_Alnode& _Al, _Nodeptr _Pnode) {
		using _Alnode_traits = allocator_traits<_Alnode>;
		_Alnode_traits::destroy(_Al, _STD addressof(_Pnode->_Next));
		_Alnode_traits::destroy(_Al, _STD addressof(_Pnode->_Myval));
		_Al.deallocate(_Pnode, 1);
	}*/
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

	// ����������� ���������� ��������� � ������.
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
//	void delete(const T &item);

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

//
int main()
{
	std::cout << "Hello World!\n";

	std::forward_list<int> mylist = { 10, 20, 30 };
	mylist.clear();
}


template <class T>
LinkedList<T>::LinkedList() {

	count = 0;

	first = nullptr;
	last = nullptr;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	if (count == 0 &&
		first == nullptr &&
		last == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void LinkedList<T>::print() const {
	struct Node* temp = this->first;

	while (temp != nullptr) {
		cout << temp->data << endl;
		temp->temp->next;
	}
}

template <class T>
int LinkedList<T>::length() const {
	return this->count;
}

template <class T>
void LinkedList<T>::prepend(const T& item) {

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

	temp->data = item;
	temp->next = first;

	first = temp;

	this->count++;
}

template <class T>
void LinkedList<T>::append(const T& item) {
	T* temp = new T;

	temp->data = item;
	temp->next = first;

	first = temp;

	this->count++;
}




// ���������� ��������� �� ������ ������� ������.
template <class T>
Node<T>* LinkedList<T>::beg() {
	return data;
}

// ���������� ��������� �� ��������� ������� ������.
template <class T>
Node<T>* LinkedList<T>::end() {
	return last;
}