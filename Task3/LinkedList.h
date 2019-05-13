#pragma once

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
	//	count = 0;
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
	void deleteItem(const T &item);

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
