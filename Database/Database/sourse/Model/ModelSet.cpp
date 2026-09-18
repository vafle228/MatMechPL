#include "../../headers/Model/ModelSet.h"


ModelSetBase::ModelSetBase(ModelConnect connect, ModelParams condition, bool filter)
	: connect(connect), filters(condition), is_filter(filter)
{ }

IModel* ModelSetBase::FindNextModel()
{
	LoopFile: while (!connect.IsEOF())
	{
		IModel* instance = CreateInstance();
		ModelAttrs attrs = instance->GetAttrs();
		
		try { connect.ReadModel(attrs); }
		catch (std::exception) { return nullptr; }

		for (auto it = filters.begin(); it != filters.end(); it++) 
		{
			if (attrs.find(it->first) == attrs.end())
				throw std::exception("Key error");
			
			std::string value = attrs.at(it->first)->ToString();
			if ((value == it->second) != is_filter) goto LoopFile;
		}
		return instance;
	}
	return nullptr;
}
