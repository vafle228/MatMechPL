#pragma once
#include <string>


struct Token 
{
public:
	const std::string first;
	const std::string second;

	Token(std::string first, std::string second);
};
