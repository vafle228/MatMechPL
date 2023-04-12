#pragma once
#include <map>
#include <vector>
#include <string>

#include "WordChance.h"

#define WordsChances std::vector<WordChance>


class ModelSerializer
{
public:
	ModelSerializer(std::map<std::string, WordsChances>* model);

	void DumpModel();
	void LoadModel();

private:
	std::map<std::string, WordsChances>* model;
};
