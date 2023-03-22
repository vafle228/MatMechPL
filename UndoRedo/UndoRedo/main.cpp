#include <iostream>

#include "Texteditor.h"


std::string* CommandSplit(std::string command)
{
    std::string* args = new std::string[2];
    if (command.find(" ") == std::string::npos)
    {
        args[1] = "";
        args[0] = command; 
    }
    else 
    {
        args[0] = command.substr(0, command.find(" "));
        args[1] = command.substr(command.find(" ") + 1);
    }
    return args;
}


int main()
{
    std::string command;
    TextEditor* editor = new TextEditor();

    while (true) 
    {
        std::getline(std::cin, command);
        std::string* args = CommandSplit(command);

        if (args[0] == "exit") break;
        
        else if (args[0] == "undo") editor->Undo();
        else if (args[0] == "redo") editor->Redo();
        
        else if (args[0] == "print") editor->Print();
        else if (args[0] == "add") editor->Add(args[1]);
        else if (args[0] == "del") editor->Del(std::stoi(args[1]));
    }
}
