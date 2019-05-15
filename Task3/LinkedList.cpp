#include "Node.h"
#include "LinkedList.h"
#include <iostream>

//template<class T>
//const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>&)
//{
//	// TODO: insert return statement here
//}


//template<class T>
//LinkedList<T>::LinkedList(const LinkedList<T>& otherList)
//{
//}

template <class T>
bool linked_list<T>::is_empty() const {
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

template <class T>
int linked_list<T>::length() const {
	return this->count_;
}

template<class T>
void linked_list<T>::clear()
{
	node<T>* ptr = this->first_, tmptr;

	this->count_ = 0;

	while (ptr != nullptr) {
		tmptr = ptr;
		ptr = ptr->next;
		delete tmptr;
	}

	first_ = nullptr;
	last_ = nullptr;

	delete ptr;
	delete tmptr;
}

template<class T>
T linked_list<T>::front() const
{
	return this->first_->data;
}

template<class T>
T linked_list<T>::end() const
{
	return this->last_->data;
}

template <class T>
void linked_list<T>::prepend(const T& item) {

	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

	temp->data = item;
	temp->next = first_;

	first_ = temp;

	++this->count_;
}

//template <class T>
//void linked_list<T>::append(const T& item)
//{
//	T* temp = new T;
//
//	temp->data = item;
//	temp->next = first_;
//
//	first_ = temp;
//
//	++this->count_;
//}

//template <class T>
//void linked_list<T>::append(const T& item) {

//}

template<class T>
node<T>* linked_list<T>::insert(const T& item, node<T>* current)
{
	auto afterCurrent = this->find(current)->next;

	node<T> newNode = new node<T>{};
	newNode->data = item;

	newNode->next = afterCurrent;

	current->next = newNode;

}

template<class T>
node<T>* linked_list<T>::find(const T& item)
{
	node* temp = this->first_;
	
	auto i = 0;
	auto c = this->count_;
	while (i < c) {

		if (temp.data == item.data) {
			return temp;
		}

		temp->temp->next;
		i++;
	}
}

// Возвращает указатель на первый элемент списка.
template <class T>
node<T>* linked_list<T>::beg() {
	return this->first_;
}

// Возвращает указатель на последний элемент списка.
template <class T>
node<T>* linked_list<T>::end() {
	return this->last_;
}

//template<class T>
//void linked_list<T>::deleteItem(const T& item)
//{
//	Node* q;
//	Node* temp = this->first_;
//
//	auto i = 0;
//	auto c = this->count_;
//	while (i < c) {
//
//		if (temp.data->next == item.data) {
//			q = temp->next;
//			break;
//		}
//
//		temp->temp->next;
//		i++;
//	}
//	
//
//	temp->next = q->next;
//
//	delete q;
//}

//template<class T>
//void LinkedList<T>::copy(const LinkedList<T>& otherList)
//{
//}
