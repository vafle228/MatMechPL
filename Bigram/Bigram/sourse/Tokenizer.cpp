#include "../headers/Tokinezer.h"


Tokenizer::Tokenizer(std::string path)
{
	connect = std::ifstream(path);
	word_exp = std::regex("[À-ÿ]+");
	sentence_exp = std::regex("[À-ÿ][^\.!?]*[\.!?]");
}

std::vector<Token> Tokenizer::GetTokens()
{
	std::string text = ReadAllFile();
	
	std::smatch sentence_m, word_m;
	std::string sentence_str, last_word;

	std::vector<Token> result = std::vector<Token>();
	while (std::regex_search(text, sentence_m, sentence_exp))
	{
		sentence_str = sentence_m[0];
		while (std::regex_search(sentence_str, word_m, word_exp)) 
		{
			if (last_word == "") last_word = word_m[0];
			else
			{
				result.push_back(Token(last_word, word_m[0]));
				last_word = word_m[0];
			}
			sentence_str = word_m.suffix().str();
		}
		last_word = ""; text = sentence_m.suffix().str();
	}
	return result;
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