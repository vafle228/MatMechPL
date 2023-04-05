#pragma once


template<typename T>
struct Node 
{
public:
	T* value;
	Node* next_node;

	Node();
	Node(T* value, Node* next);
	
	bool IsEmpty();
};

#pragma region Node

template<typename T>
inline Node<T>::Node() 
{
	value = nullptr;
	next_node = nullptr;
}

template<typename T>
inline Node<T>::Node(T* value, Node* next) : value(value), next_node(next) { }

template<typename T>
inline bool Node<T>::IsEmpty() 
{
	return value == nullptr && next_node == nullptr;
}

#pragma endregion

