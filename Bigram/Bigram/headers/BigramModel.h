#pragma once
#include <map>
#include <string>
#include <vector>

#include "Tokinezer.h"
#include "WordChance.h"

#define Tokens std::vector<Token>
#define BigramFreq std::map<Token, float>
#define WordFreq std::map<std::string, int>
#define WordsChances std::vector<WordChance>


class BigramModel 
{
public:
	void Train(std::string file_path);
	std::string GenerateText(std::string word, int counts);

private:
	std::map<std::string, WordsChances> model;

	std::string PickRandomStart();
	std::string RandomWord(WordsChances words_chances);
	void CountFreqs(Tokens tokens, BigramFreq& bigram_freq, WordFreq& word_freq);
};