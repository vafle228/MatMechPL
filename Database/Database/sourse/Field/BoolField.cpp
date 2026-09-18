#include "../../headers/Field/BoolField.h"


std::string BoolField::ToString()
{
	return value ? "1" : "0";
}

unsigned long long BoolField::Sizeof()
{
	return sizeof(bool);
}

unsigned long long BoolField::StrMaxLen()
{
	return 1;
}

bool BoolField::Validate(std::string value)
{
	return true;
}

void BoolField::Normalize(std::string value)
{
	this->value = value == "1";
}

void BoolField::ReadBinary(std::fstream* stream)
{
	stream->read((char*)&value, sizeof(bool));
}

void BoolField::WriteBinary(std::fstream* stream)
{
	stream->write((char*)&value, sizeof(bool));
}
