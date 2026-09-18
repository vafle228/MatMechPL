#pragma once
#include <vector>
#include <string>


std::vector<std::string> Split(std::string str, char delim = ' ');

std::string FillSpaces(std::string str, unsigned long long max_len, char sign = ' ');
