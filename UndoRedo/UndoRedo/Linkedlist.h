#pragma once


template<typename T>
struct Node 
{
	T val = T();
	Node* prev_node = nullptr;

	Node(T value);
};

template<typename T>
inline Node<T>::Node(T value) : val(value) { }
