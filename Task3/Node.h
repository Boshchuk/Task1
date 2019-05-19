#pragma once

// ��������� ��������� �������������� ����
template <class _Type>
struct node {

	_Type data;        // ������ ����

	node<_Type>* next; // ��������� �� ��������� ����

	~node();
};

template<class _Type>
node<_Type>::~node()
{
	delete next;
}
