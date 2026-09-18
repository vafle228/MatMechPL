#pragma once
#include "IField.h"


class BoolField : public IField 
{
public:
	bool value = false;

	std::string ToString() override;
	unsigned long long Sizeof() override;
	unsigned long long StrMaxLen() override;

	bool Validate(std::string value) override;
	void Normalize(std::string value) override;

	void ReadBinary(std::fstream* stream) override;
	void WriteBinary(std::fstream* stream) override;
};