#include "Hashmap.h"
#include <iostream>


Hashmap::Hashmap(int hash_base, int capacity)
{
	this->capacity = capacity;
	this->hash_base = hash_base;

	this->map = new Node<std::string>*[capacity];
	
	for (int i = 0; i < capacity; i++) 
	{
		map[i] = new Node<std::string>();
	}
}

void Hashmap::Statistics()
{
	for (int i = 0; i < capacity; i++) 
	{
		Node<std::string>* list = map[i];
		int count = (int)!list->IsEmpty();

		while (list->next_node != nullptr)
		{
			count++;
			list = list->next_node;
		}

		std::cout << count << std::endl;
		// std::cout << "Ячейка: " << i << " | Кол-во значений: " << count << std::endl;
	}
}

bool Hashmap::Contains(std::string* value)
{
	Node<std::string>* list = map[GetHash(value)];

	while (list->next_node != nullptr)
	{
		if (list->value == value) return true;
		list = list->next_node;
	}
	return list->value == value;
}

void Hashmap::AddElement(std::string* value)
{
	int hash = GetHash(value);

	if (map[hash]->IsEmpty()) map[hash]->value = value;
	else map[hash] = new Node<std::string>(value, map[hash]);
}

int Hashmap::GetHash(std::string* value)
{
	int hash = 0;
	for (int i = 0; i < value->length(); i++)
	{
		hash += value->c_str()[i] * std::pow(hash_base, i);
	}
	return hash % capacity;
}
