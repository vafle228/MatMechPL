#pragma once
#include <string>


struct WordChance 
{
public:
	float chance;
	std::string word;

	WordChance(float chance, std::string word);
};