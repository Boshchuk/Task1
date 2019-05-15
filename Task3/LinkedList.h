#pragma once

#include "Node.h"
#include <iostream>

template <class T>
class linked_list {
public:
	// ���������� �� ���������. ������� ������ ������.
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

	// ����������
	~linked_list()
	{
		//clear all items
		this->clear();
	}

	// ���������� ��������� ����������.
	//const LinkedList<T>& operator = (const LinkedList<T>&);

	// ���������� �����������
	//LinkedList(const LinkedList<T>& otherList);

	// ���������� true, ���� ������ �� ���� � false � ��������� ������
	bool is_empty() const;

	// ������� ������ ������
	void print() const
	{
		auto temp = this->first_;

		while (temp != nullptr) {
			temp->data.print();
			temp = temp->next;
		}
	}

	// ����������� ���������� ��������� � ������.
	int length() const;

	// ������� ��� ���� ������.
	// � ���������� ������: 
	//	first = nullprt,
	//	last = nullptr,
	//	count = 0;
	void clear();

	// ���������� ������ ������� �������� ������
	T front() const;

	// ���������� ������ ���������� �������� ������.
	T end() const;

	// ��������� ������� � ������ ������.
	void prepend(const T& item);

	// ��������� ������� � ����� ������.
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

	// ��������� ������� item ����� �������� current � ���������� ��������� �� ����.
	node<T>* insert(const T& item, node<T>* current);

	// ���� � ������ ������� item � ���������� ��������� �� ���� �������.
	node<T>* find(const T& item);

	// ���������� ��������� �� ������ ������� ������.
	node<T>* beg();

	// ���������� ��������� �� ��������� ������� ������.
	node<T>* end();

	// ������� ������� item �� ������.
	void delete_item(const T &item);

private:

	// �������, ��������� ����� ������ otherList.
	//void copy(const LinkedList<T>& otherList);

	// ���-�� ��������� ������.
	int count_;

	// ��������� �� ������ ������� ������.
	node<T>* first_;

	// ��������� �� ��������� ������� ������.
	node<T>* last_;
};
