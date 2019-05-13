#include "Node.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {

	count = 0;

	first = nullptr;
	last = nullptr;

	delete first;
	delete last;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	// clear all items
	this->clear();
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
		std::cout << temp->data << std::endl;
		temp->temp->next;
	}
}

template <class T>
int LinkedList<T>::length() const {
	return this->count;
}

template<class T>
void LinkedList<T>::clear()
{
	Node<T>* ptr = this->first, tmptr;

	this->count = 0;

	while (ptr != nullptr) {
		tmptr = ptr;
		ptr = ptr->next;
		delete tmptr;
	}

	first = nullptr;
	last = nullptr;

	delete ptr;
	delete tmptr;
}

template<class T>
T LinkedList<T>::front() const
{
	return this->first->data;
}

template<class T>
T LinkedList<T>::end() const
{
	return this->last->data;
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

template<class T>
Node<T>* LinkedList<T>::find(const T& item)
{
	struct Node* temp = this->first;
	
	auto i = 0;
	auto c = this->count;
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
Node<T>* LinkedList<T>::beg() {
	return this->first;
}

// Возвращает указатель на последний элемент списка.
template <class T>
Node<T>* LinkedList<T>::end() {
	return this->last;
}