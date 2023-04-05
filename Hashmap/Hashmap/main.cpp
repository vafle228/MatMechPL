#include <string>
#include <iostream>

#include "Hashmap.h"


int GenerateRandomNumber(int min_val, int max_val) 
{
	return min_val + std::rand() % (max_val - min_val);
}

std::string* GenerateRandomString(int len, int min_val, int max_val) 
{
	std::string* str = new std::string();
	for (int i = 0; i < len; i++) 
		str->append(1, (char)GenerateRandomNumber(min_val, max_val));
	return str;
}

int main()
{
	setlocale(0, "rus");
	std::srand(std::time(nullptr));

	Hashmap maps[]{ Hashmap(10, 71), Hashmap(9, 27), Hashmap(2, 113) };

	for (int i = 0; i < 3; i++) 
	{
		std::string* rand_str;
		
		for (int j = 0; j < 100000; j++) 
		{
			rand_str = GenerateRandomString(4, 97, 123);
			while (maps[i].Contains(rand_str))
			{
				rand_str = GenerateRandomString(4, 97, 123);
			}
			maps[i].AddElement(rand_str);
		}

		maps[i].Statistics();
		std::cout << "----------------------------" << std::endl;
	}
}
