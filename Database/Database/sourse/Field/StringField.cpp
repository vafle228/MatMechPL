#include "../../headers/Field/StringField.h"


StringField::StringField(unsigned long long max_len)
	: max_len(max_len)
{ }

std::string StringField::ToString()
{
	return value;
}

unsigned long long StringField::Sizeof()
{
	return max_len;
}

unsigned long long StringField::StrMaxLen()
{
	return max_len;
}

bool StringField::Validate(std::string value)
{
	return value.length() <= max_len;
}

void StringField::Normalize(std::string value)
{
	this->value = value;
}

void StringField::ReadBinary(std::fstream* stream)
{
	char* buffer = new char[max_len];
	stream->read(buffer, max_len); value = buffer;
}

void StringField::WriteBinary(std::fstream* stream)
{
	stream->write(value.c_str(), max_len);
}
