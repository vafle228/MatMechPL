#include <iostream>
#include "Texteditor.h"

void TextEditor::Print()
{
	std::cout << this->state << std::endl;
}

void TextEditor::Del(int n)
{
	this->SaveState();
	this->state = this->state.substr(0, this->state.length() - n);
}

void TextEditor::Add(std::string str)
{
	this->SaveState();
	this->state += str;
}

void TextEditor::Undo()
{
	this->redo.Push(this->state);
	this->state = this->undo.Pop();
}

void TextEditor::Redo()
{
	this->undo.Push(this->state);
	this->state = this->redo.Pop();
}

void TextEditor::SaveState()
{
	if (!this->redo.IsEmpty())
		this->redo = Stack<std::string>();
	this->undo.Push(this->state);
}
