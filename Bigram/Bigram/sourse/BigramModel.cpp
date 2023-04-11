#include "../headers/Token.h"
#include "../headers/Tokinezer.h"
#include "../headers/BigramModel.h"


void BigramModel::Train(std::string file_path)
{
	Tokenizer tokenizer = Tokenizer(file_path);
	std::vector<Token> tokens = tokenizer.GetTokens();

	std::map<Token, float> bigram_freq;
	std::map<std::string, int> word_freq;

	CountFreqs(tokens, bigram_freq, word_freq);

	for (auto it = bigram_freq.begin(); it != bigram_freq.end(); it++) 
	{
		if (model.find(it->first.first) == model.end())
			model[it->first.first] = WordsChances();
		
		std::string word = it->first.second;
		float chance = it->second / word_freq[it->first.first];
		
		model[it->first.first].push_back(WordChance(chance, word));
	}
}

int RandomNumber(int min_val, int max_val)
{
	return min_val + std::rand() % (max_val - min_val);
}

std::string BigramModel::PickRandomStart()
{
	auto new_element = model.begin();
	int pos = RandomNumber(0, model.size());
	
	for (int i = 0; i < pos; i++) new_element++;

	return new_element->first;
}


std::string BigramModel::GenerateText(std::string word, int count)
{
	std::string text;

	std::string last_word = word;
	for (int i = 0; i < count; i++) 
	{
		text += last_word + " ";

		if (model.find(last_word) == model.end()) 
		{
			text.pop_back(); text += ". ";
			last_word = PickRandomStart();
		}
		else last_word = RandomWord(model.at(last_word));
	}
	return text;
}

std::string BigramModel::RandomWord(WordsChances words_chances)
{
	float chance = (float)RandomNumber(1, 1000) / 1000;

	WordChance nearest_word = WordChance(2, "");
	for (WordChance word_chance : words_chances) 
	{
		if (std::abs(word_chance.chance - chance) < nearest_word.chance) 
		{
			nearest_word = word_chance;
		}
	}
	return nearest_word.word;
}

void BigramModel::CountFreqs(Tokens tokens, BigramFreq& bigram_freq, WordFreq& word_freq)
{
	for (Token token : tokens)
	{
		if (bigram_freq.find(token) == bigram_freq.end())
			bigram_freq[token] = 0;

		if (word_freq.find(token.first) == word_freq.end())
			word_freq[token.first] = 0;

		bigram_freq[token] += 1; word_freq[token.first] += 1;
	}
}
