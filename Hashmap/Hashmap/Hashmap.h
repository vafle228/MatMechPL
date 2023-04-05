#pragma once
#include <cmath>
#include <string>

#include "List.h"


class Hashmap 
{
public:
	Hashmap(int hash_base, int capacity);
	
	void Statistics();
	bool Contains(std::string* value);
	void AddElement(std::string* value);

private:
	Node<std::string>** map;
	int hash_base, capacity;

	int GetHash(std::string* value);
};
