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

	// Вовзращает true, если список не пуст и false в противном случае
	bool is_empty() const
	{
		if (count_ == 0 &&
			first_ == nullptr &&
			last_ == nullptr)
		{
			return true;
		}
		else {
			return false;
		}
	}

	// Выводит данные списка
	void print() const
	{
		if (this->is_empty())
		{
			std::cout<< "Cписок пуст" << std::endl;
		}
		else
		{
			auto temp = this->first_;

			while (temp != nullptr) {
				temp->data.print();
				temp = temp->next;
			}
		}
	}

	// Возваращает количество элементов в списке.
	int length() const;

	// удаляет все узлы списка.
	// В результате список: 
	//	first = nullprt,
	//	last = nullptr,
	//	count = 0;
	void clear()
	{
		node<T> * ptr = this->first_;
		node<T>* tmptr;

		this->count_ = 0;

		while (ptr != nullptr) {
			tmptr = ptr;
			ptr = ptr->next;

			delete tmptr;
		}

		first_ = nullptr;
		last_ = nullptr;

		delete ptr;
	}

	// Возвращает данные первого элеметна списка
	T front() const;

	// Возвращает данные последнего элеметна списка.
	T end() const;

	// Добавляет элемент в начало списка.
	void prepend(const T& item)
	{
		auto new_node = new node<T>{};

		new_node->data = item;
		new_node->next = first_;

		if (this->is_empty())
		{
			first_ = new_node;
			last_ = new_node;
		}
		else
		{
			auto temp = this->first_;

			this->first_ = new_node;
			this->first_->next = temp;
		}

		++this->count_;
	}

	// Добавляет элемент в конец списка.
	void append(const T& item)
	{
		auto new_node = new node<T>{};

		new_node->data = item;
		new_node->next = nullptr;

		if (this->is_empty())
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
	node<T>* insert(const T& item, node<T>* current)
	{
		auto new_node = new node<T>{};
		new_node->data = item;
		new_node->next = nullptr;

		if (this->is_empty())
		{
			first_ = new_node;
			last_ = new_node;
		}
		else
		{
			auto after_current = this->find(current->data)->next;

			new_node->next = after_current;

			current->next = new_node;
		}
		return new_node;
	}

	// Ищет в списке элемент item и возвращает указатель на этот элемент.
	// возвращает nullptr если элемент не найден
	node<T>* find(const T& item)
	{
		auto temp = this->first_;

		auto i = 0;
		auto c = this->count_;

		while (i < c) {

			if (temp->data == item) {
				return temp;
			}

			temp = temp->next;
			i++;
		}

		return nullptr;
	}

	// Возвращает указатель на первый элемент списка.
	node<T>* beg();

	// Возвращает указатель на последний элемент списка.
	node<T>* end();

	// Удаляет элемент item из списка.
	void delete_item(const T &item)
	{
		node<T>* q;
		node<T>* temp = this->first_;

		auto i = 0;
		auto c = this->count_;
		while (i < c) {

			if (temp->next->data == item) {
				q = temp->next;

				temp->next = q->next;

				delete q;

				break;
			}

			temp = temp->next;
			i++;
		}
	}

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
