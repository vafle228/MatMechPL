#pragma once
#include <map>
#include <string>

#define ModelParams std::map<std::string, std::string>


class DatabaseCommand
{
public:
	ModelParams params;
	ModelParams filters;
	std::string command;
	std::string db_name;

	DatabaseCommand operator () (std::string str);
};