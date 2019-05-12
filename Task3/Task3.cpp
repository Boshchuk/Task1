#include <iostream>
#include <string>

#include <forward_list>

using namespace std;

// шаблонная структура представляющая узел
template <class _Type>
struct Node {

	_Type data;        // данные узла

	Node<_Type>* next; // указатель на слудующий узел
	

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
	// Конструтор по умолчанию. Создает пустой список.
	LinkedList();

	// Деструктор
	~LinkedList();

	// Перегрузка оператора присваивая.
	const LinkedList<T>& operator = (const LinkedList<T>&);

	// Копирующий конструткор
	LinkedList(const LinkedList<T>& otherList);

	// Вовзращает true, если список не пуст и false в противном случае
	bool isEmpty() const;

	// Выводит данные списка
	void print() const;

	// Возваращает количество элементов в списке.
	int length() const;

	// удаляет все узлы списка.
	// В результате список: 
	//	first = nullprt,
	//	last = nullptr,
	//	cont = 0;
	void clear();

	// Возвращает данные первого элеметна списка
	T front() const;

	// Возвращает данные последнего элеметна списка.
	T end() const;

	// Добавляет элемент в начало списка.
	void prepend(const T& item);

	// Добавляет элемент в конец списка.
	void append(const T& item);

	// Добавляет элемент item после элемента curr и возвращает указатель на него.
	Node<T>* insert(const T& item, Node<T>* curr);

	// Ищет в списке элемент item и возвращает указатель на этот элемент.
	Node<T>* find(const T& item);

	// Возвращает указатель на первый элемент списка.
	Node<T>* beg();

	// Возвращает указатель на последний элемент списка.
	Node<T>* end();

	// Удаляет элемент item из списка.
//	void delete(const T &item);

private:

	// Функция, создающая копию списка otherList.
	void copy(const LinkedList<T>& otherList);

	// кол-во элементов списка.
	int count;

	// Указатель на первый элемент списка.
	Node<T>* first;

	// Указатель на последний элемент списка.
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




// Возвращает указатель на первый элемент списка.
template <class T>
Node<T>* LinkedList<T>::beg() {
	return data;
}

// Возвращает указатель на последний элемент списка.
template <class T>
Node<T>* LinkedList<T>::end() {
	return last;
}