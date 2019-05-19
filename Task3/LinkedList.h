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

	// ���������� true, ���� ������ �� ���� � false � ��������� ������
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

	// ������� ������ ������
	void print() const
	{
		if (this->is_empty())
		{
			std::cout<< "C����� ����" << std::endl;
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

	// ����������� ���������� ��������� � ������.
	int length() const;

	// ������� ��� ���� ������.
	// � ���������� ������: 
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

	// ���������� ������ ������� �������� ������
	T front() const;

	// ���������� ������ ���������� �������� ������.
	T end() const;

	// ��������� ������� � ������ ������.
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

	// ��������� ������� � ����� ������.
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

	// ��������� ������� item ����� �������� current � ���������� ��������� �� ����.
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

	// ���� � ������ ������� item � ���������� ��������� �� ���� �������.
	// ���������� nullptr ���� ������� �� ������
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

	// ���������� ��������� �� ������ ������� ������.
	node<T>* beg();

	// ���������� ��������� �� ��������� ������� ������.
	node<T>* end();

	// ������� ������� item �� ������.
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

	// �������, ��������� ����� ������ otherList.
	//void copy(const LinkedList<T>& otherList);

	// ���-�� ��������� ������.
	int count_;

	// ��������� �� ������ ������� ������.
	node<T>* first_;

	// ��������� �� ��������� ������� ������.
	node<T>* last_;
};
