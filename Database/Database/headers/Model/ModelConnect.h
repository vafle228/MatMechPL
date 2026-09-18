#pragma once
#include <map>
#include <fstream>

#include "../Field/IField.h"

#define ModelAttrs std::map<std::string, IField*>


class ModelConnect 
{
public:
	ModelConnect(std::fstream* stream);

	bool IsEOF();
	
	void DeletePrev();
	void AddModel(ModelAttrs attrs);
	
	void ReadModel(ModelAttrs attrs);
	void UpdatePrev(ModelAttrs attrs);

private:
	std::fstream* stream;
	std::streampos pos = std::iostream::beg;
};