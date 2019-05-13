#pragma once

// ��������� ��������� �������������� ����
template <class _Type>
struct Node {

	_Type data;        // ������ ����

	Node<_Type>* next; // ��������� �� ��������� ����


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
