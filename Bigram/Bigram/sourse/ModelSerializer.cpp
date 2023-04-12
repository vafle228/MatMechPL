#include <fstream>

#include "../headers/ModelSerializer.h"

#define BigramPair std::pair<std::string, WordsChances>


const std::string DUMP_FILE = "dump.txt";

ModelSerializer::ModelSerializer(std::map<std::string, WordsChances>* model) 
	: model(model)
{ }

void ModelSerializer::DumpModel()
{
	std::ofstream connect(DUMP_FILE);
	for (auto it = model->begin(); it != model->end(); it++) 
	{
		connect << it->first << ":";
		for (WordChance word_chance : it->second) 
			connect << word_chance.word << "," << word_chance.chance << ";";
		connect << std::endl;
	}
	connect.close();
}

std::vector<std::string> Split(std::string str, char delim) {
	std::string word = "";
	std::vector<std::string> words_vec;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != delim) word += str[i];
		else
		{
			words_vec.push_back(word);
			word = "";
		}
	}
	words_vec.push_back(word); return words_vec;
}

void ModelSerializer::LoadModel()
{
	std::string temp;
	std::ifstream connect(DUMP_FILE);
	
	while (!connect.eof()) 
	{
		getline(connect, temp);

		if (temp == "") continue;

		std::vector<std::string> bigram = Split(temp, ':');
		model->insert(BigramPair(bigram[0], WordsChances()));

		std::vector<std::string> words_chances = Split(bigram[1], ';');
		for (int i = 0; i < words_chances.size() - 1; i++) 
		{
			std::vector<std::string> word_chance = Split(words_chances[i], ',');
			model->at(bigram[0]).push_back(WordChance(std::stof(word_chance[1]), word_chance[0]));
		}
	}
	connect.close();
}
