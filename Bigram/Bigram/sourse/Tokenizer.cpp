#include "../headers/Tokinezer.h"


Tokenizer::Tokenizer(std::string path)
{
	connect = std::ifstream(path);
}

std::vector<Token> Tokenizer::GetTokens()
{
	std::string text = ReadAllFile();
	
	std::smatch sentence_m, word_m;
	std::string sentence_str, word_str = "";

	while (std::regex_search(text, sentence_m, sentence_exp))
	{
		sentence_str = sentence_m[0];
		while (std::regex_search(sentence_str, word_m, word_exp)) 
		{
			word_str = word_m[0];
		}
	}

	return std::vector<Token>();
}

std::string Tokenizer::ReadAllFile()
{
	std::string text = "";
	std::string temp_str = "";

	while (!connect.eof()) 
	{
		getline(connect, temp_str);
		text += temp_str;
	}
	return text;
}

std::string Tokenizer::NormalizeString(std::string str)
{
	for (int i = 0; i < str.length(); i++) 
		str.replace(i, 1, std::to_string(tolower(str[i])));
	return str;
}