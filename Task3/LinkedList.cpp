#include "Node.h"
#include "LinkedList.h"

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

// ���������� ��������� �� ������ ������� ������.
template <class T>
node<T>* linked_list<T>::beg() {
	return this->first_;
}

// ���������� ��������� �� ��������� ������� ������.
template <class T>
node<T>* linked_list<T>::end() {
	return this->last_;
}
