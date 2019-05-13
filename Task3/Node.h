#pragma once

// шаблонная структура представляющая узел
template <class _Type>
struct Node {

	_Type data;        // данные узла

	Node<_Type>* next; // указатель на слудующий узел


	~Node();
	/*{
		delete next
	}*/
};

template<class _Type>
inline Node<_Type>::~Node()
{
	delete next;
}
