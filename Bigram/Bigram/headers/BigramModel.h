#pragma once
#include <map>
#include <string>
#include <vector>

#include "Tokinezer.h"
#include "WordChance.h"
#include "ModelSerializer.h"

#define Tokens std::vector<Token>
#define BigramFreq std::map<Token, float>
#define WordFreq std::map<std::string, int>
#define WordsChances std::vector<WordChance>


class BigramModel 
{
public:
	void DumpModel();
	void LoadModel();

	void Train(std::vector<std::string> file_paths);
	std::string GenerateText(std::string word, int counts);

private:
	std::map<std::string, WordsChances> model;
	ModelSerializer serializer = ModelSerializer(&model);

	std::string PickRandomStart();
	std::string RandomWord(WordsChances words_chances);
	void CountFreqs(Tokens tokens, BigramFreq& bigram_freq, WordFreq& word_freq);
};