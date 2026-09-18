#pragma once
#include <string>
#include <fstream>


class IField 
{
public:
	virtual std::string ToString() = 0;
	virtual unsigned long long Sizeof() = 0;
	virtual unsigned long long StrMaxLen() = 0;
	
	virtual bool Validate(std::string value) = 0;
	virtual void Normalize(std::string value) = 0;

	virtual void ReadBinary(std::fstream* stream) = 0;
	virtual void WriteBinary(std::fstream* stream) = 0;
};