#pragma once

#include "Linkedlist.h"


template<typename T>
class Stack 
{
public:
	T Pop();
	bool IsEmpty();
	void Push(T value);

private:
	Node<T>* stack_head = nullptr;
};

template<typename T>
inline T Stack<T>::Pop()
{
	if (this->IsEmpty())
		throw std::length_error("Zero length stack");
	
	T value = this->stack_head->val;
	Node<T>* old_head = this->stack_head;

	this->stack_head = old_head->prev_node;
	delete old_head; return value;
}

template<typename T>
inline bool Stack<T>::IsEmpty()
{
	return this->stack_head == nullptr;
}

template<typename T>
inline void Stack<T>::Push(T value)
{
	Node<T>* new_head = new Node<T>(value);
	
	new_head->prev_node = this->stack_head;
	this->stack_head = new_head;
}
