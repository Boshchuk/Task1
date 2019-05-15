#pragma once

#include "Node.h"
#include <iostream>

template <class T>
class linked_list {
public:
	// Конструтор по умолчанию. Создает пустой список.
	linked_list()
	{
		count_ = 0;

		first_ = nullptr;
		last_ = nullptr;
	}

	linked_list(int count, node<T>* first, node<T>* last)
		: count_(count),
		  first_(first),
		  last_(last)
	{
	}

	// Деструктор
	~linked_list()
	{
		//clear all items
		this->clear();
	}

	// Перегрузка оператора присваивая.
	//const LinkedList<T>& operator = (const LinkedList<T>&);

	// Копирующий конструткор
	//LinkedList(const LinkedList<T>& otherList);

	// Вовзращает true, если список не пуст и false в противном случае
	bool is_empty() const;

	// Выводит данные списка
	void print() const
	{
		auto temp = this->first_;

		while (temp != nullptr) {
			temp->data.print();
			temp = temp->next;
		}
	}

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
	void append(const T& item)
	{
		auto new_node = new node<T>{};

		new_node->data = item;
		new_node->next = nullptr;

		if (this->first_ == nullptr)
		{
			first_ = new_node;
			last_  = new_node;
		}
		else
		{
			last_->next = new_node;
			last_       = new_node;
		}
		
		++this->count_;
	}

	// Добавляет элемент item после элемента current и возвращает указатель на него.
	node<T>* insert(const T& item, node<T>* current);

	// Ищет в списке элемент item и возвращает указатель на этот элемент.
	node<T>* find(const T& item);

	// Возвращает указатель на первый элемент списка.
	node<T>* beg();

	// Возвращает указатель на последний элемент списка.
	node<T>* end();

	// Удаляет элемент item из списка.
	void delete_item(const T &item);

private:

	// Функция, создающая копию списка otherList.
	//void copy(const LinkedList<T>& otherList);

	// кол-во элементов списка.
	int count_;

	// Указатель на первый элемент списка.
	node<T>* first_;

	// Указатель на последний элемент списка.
	node<T>* last_;
};
