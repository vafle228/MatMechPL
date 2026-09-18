#include <vector>

#include "../../headers/Utils/Utils.h"
#include "../../headers/Database/CommandParser.h"


DatabaseCommand DatabaseCommand::operator()(std::string str)
{
	DatabaseCommand command_args;

	auto vectstr = Split(str, ' ');
	
	command_args.command = vectstr[0];
	command_args.db_name = vectstr[1];

	for (int i = 2; i + 1 < vectstr.size(); i += 2)
	{
		ModelParams tmp;
		
		auto args = Split(vectstr[i + 1], ',');
		for (int i = 0; i < args.size(); i++)
		{
			auto params = Split(args[i], '=');
			tmp.emplace(params[0], params[1]);
		}

		if (vectstr[i] == "WHERE") command_args.filters = tmp;

		else if (vectstr[i] == "WITH") command_args.params = tmp;

		else throw std::exception("Wrong arguments in command");
	}

	return command_args;
}
