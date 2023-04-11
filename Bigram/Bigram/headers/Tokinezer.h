#pragma once
#include <regex>
#include <vector>
#include <string>
#include <fstream>

#include "Token.h"


class Tokenizer 
{
public:
	Tokenizer(std::string path);
	std::vector<Token> GetTokens();

private:
	std::ifstream connect;
	
	std::regex word_exp = std::regex("[À-ÿ]+");
	std::regex sentence_exp = std::regex("[À-ÿ][^\.!?]*[\.!?]");

	std::string ReadAllFile();
	std::string NormalizeString(std::string str);
};