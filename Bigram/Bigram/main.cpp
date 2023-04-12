#include <iostream>

#include "headers/Tokinezer.h"
#include "headers/BigramModel.h"


int main()
{
	std::srand(std::time(nullptr));

	BigramModel bigram_model = BigramModel();
	
	#pragma region Train model on russian classic

	std::vector<std::string> train_paths
	{
		"static/1.txt", "static/2.txt",
		"static/3.txt", "static/4.txt"
	};

	bigram_model.Train(train_paths);

	#pragma endregion

	bigram_model.DumpModel();

	setlocale(LC_ALL, "rus");
	
	std::cout << bigram_model.GenerateText("который", 100) << std::endl;
}
