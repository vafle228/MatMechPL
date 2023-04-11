#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "headers/Tokinezer.h"


int main()
{
	setlocale(0, "rus");
	Tokenizer tokenizer = Tokenizer("static/text.txt");
	std::vector<Token> result = tokenizer.GetTokens();

	for (auto token : result)
		std::cout << "1) " << token.first << " 2) " << token.second << std::endl;
}
