#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "headers/Tokinezer.h"
#include "headers/BigramModel.h"


int main()
{
	setlocale(LC_ALL, "rus");
	std::srand(std::time(nullptr));

	BigramModel bigram_model = BigramModel();
	
	#pragma region Train model on Tolstoy

	bigram_model.Train("static/text.txt");

	bigram_model.Train("static/1.txt");
	std::cout << "First book complete" << std::endl;
	
	bigram_model.Train("static/2.txt");
	std::cout << "Second book complete" << std::endl;

	bigram_model.Train("static/3.txt");
	std::cout << "Third book complete" << std::endl;

	bigram_model.Train("static/4.txt");
	std::cout << "Fourth book complete" << std::endl;

	#pragma endregion

	std::cout << bigram_model.GenerateText("развитие", 100) << std::endl;
}
