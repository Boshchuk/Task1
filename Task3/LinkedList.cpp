#include "Node.h"
#include "LinkedList.h"
#include <iostream>

//template<class T>
//const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>&)
//{
//	// TODO: insert return statement here
//}


template <class T>
int linked_list<T>::length() const {
	return this->count_;
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
