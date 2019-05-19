#pragma once

// шаблонная структура представляющая узел
template <class _Type>
struct node {

	_Type data;        // данные узла

	node<_Type>* next; // указатель на слудующий узел

	~node();
};

template<class _Type>
node<_Type>::~node()
{
	delete next;
}
