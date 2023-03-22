#pragma once

#include <string>
#include "Stack.h"


class TextEditor 
{
public:
	void Undo();
	void Redo();

	void Print();
	void Del(int n);
	void Add(std::string str);
private:
	void SaveState();

	std::string state = "";

	Stack<std::string> undo = Stack<std::string>();
	Stack<std::string> redo = Stack<std::string>();
};