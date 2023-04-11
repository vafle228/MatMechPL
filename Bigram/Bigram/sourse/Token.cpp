#include "../headers/Token.h"


Token::Token(std::string first, std::string second) 
	: first(first), second(second)
{ }


bool Token::operator<(const Token& obj) const
{
	return first < obj.first || (first == obj.first && second < obj.second);
}
