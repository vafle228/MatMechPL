#include "../../headers/Field/IntField.h"


unsigned long long MAX_INT_LEN = 10;

std::string IntField::ToString()
{
	return std::to_string(value);
}

unsigned long long IntField::Sizeof()
{
	return sizeof(int);
}

unsigned long long IntField::StrMaxLen()
{
	return MAX_INT_LEN;
}

bool IntField::Validate(std::string value)
{
	return true;
}

void IntField::Normalize(std::string value)
{
	this->value = std::stoi(value);
}

void IntField::ReadBinary(std::fstream* stream)
{
	stream->read((char*)&value, sizeof(int));
}

void IntField::WriteBinary(std::fstream* stream)
{
	stream->write((char*)&value, sizeof(int));
}
