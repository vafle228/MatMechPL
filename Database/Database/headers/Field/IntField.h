#pragma once
#include "IField.h"


class IntField : public IField 
{
public:
	int value = 0;

	std::string ToString() override;
	unsigned long long Sizeof() override;
	unsigned long long StrMaxLen() override;

	bool Validate(std::string value) override;
	void Normalize(std::string value) override;

	void ReadBinary(std::fstream* stream) override;
	void WriteBinary(std::fstream* stream) override;
};