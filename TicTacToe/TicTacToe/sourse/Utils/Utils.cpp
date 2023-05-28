#include "../../headers/Utils/Utils.h"


std::vector<std::string> Split(std::string str, char delim)
{
    std::string word = "";
    std::vector<std::string> words_vec;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != delim) word += str[i];
        else { words_vec.push_back(word); word = ""; }
    }
    words_vec.push_back(word); return words_vec;
}
