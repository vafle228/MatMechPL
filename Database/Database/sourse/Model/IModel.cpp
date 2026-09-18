#include "../../headers/Model/IModel.h"

#define AttrsPair std::pair<std::string, IField*>


void FillModel(ModelAttrs attrs, ModelParams params)
{
	for (auto it = params.begin(); it != params.end(); it++)
	{
		if (attrs.find(it->first) == attrs.end())
			throw std::exception("Key error");

		if (!attrs.at(it->first)->Validate(it->second))
			throw std::exception("Validation error");

		attrs.at(it->first)->Normalize(it->second);
	}
}

ModelAttrs IModel::GetAttrs()
{
	ModelAttrs attrs = Attrs();
	attrs.insert(AttrsPair("id", &id)); return attrs;
}

IModel* IModel::UpdateModel(ModelParams params)
{
	ModelAttrs attrs = Attrs();

	if (attrs.size() < params.size())
		throw std::exception("Arguments error");

	FillModel(attrs, params); return this;
}

IModel* IModel::CreateModel(ModelParams params)
{
	ModelAttrs attrs = GetAttrs();

	if (attrs.size() != params.size())
		throw std::exception("Arguments error");

	FillModel(attrs, params); return this;
}

ModelParams IModel::GetParams()
{
	ModelAttrs attrs = Attrs();
	ModelParams model_params = ModelParams();

	for (auto it = attrs.begin(); it != attrs.end(); it++)
		model_params[it->first] = it->second->ToString();
	return model_params;
}
