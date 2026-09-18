#include <iostream>

#include "../../headers/Utils/Utils.h"
#include "../../headers/Model/ModelManager.h"


void PrintAlignedRow(ModelAttrs attrs, bool is_head)
{
	std::string line = "";
	for (auto it = attrs.begin(); it != attrs.end(); it++)
	{
		IField* field = it->second;
		std::string title = it->first;

		auto row_len = std::max(title.length(), field->StrMaxLen());
		line += FillSpaces("", row_len + 1, '-') + "+-";

		if (is_head) std::cout << FillSpaces(title, row_len) << " | ";
		else std::cout << FillSpaces(field->ToString(), row_len) << " | ";
	}

	std::cout << std::endl << line << std::endl;
}

void ModelManagerBase::Print(ModelSetBase* set)
{
	IModel* record = CreateInstance();
	
	PrintAlignedRow(record->GetAttrs(), true);
	while ((record = set->FindNextModel()) != nullptr)
	{
		PrintAlignedRow(record->GetAttrs(), false);
	}
}

unsigned int ModelManagerBase::Delete(ModelSetBase* set)
{
	IModel* record;
	unsigned int del_count = 0;
	ModelConnect* connect = &set->connect;

	while ((record = set->FindNextModel()) != nullptr)
	{
		del_count++;
		connect->DeletePrev();
	}

	return del_count;
}

void ModelManagerBase::SetModelStream(std::string path)
{
	if (model_stream.is_open()) return;
	model_stream.open(path, std::ios::binary | std::ios::in | std::ios::out);
}

ModelSetBase* ModelManagerBase::Create(ModelParams params)
{
	IModel* model = CreateInstance();
	ModelConnect connect(&model_stream);

	model->CreateModel(params);
	connect.AddModel(model->GetAttrs());
	
	return GetSet({ {"id", model->id.ToString()} }, true);
}

ModelSetBase* ModelManagerBase::Update(ModelSetBase* set, ModelParams params)
{
	IModel* record;
	ModelConnect* connect = &set->connect;

	while ((record = set->FindNextModel()) != nullptr)
	{
		record->UpdateModel(params);
		connect->UpdatePrev(record->GetAttrs());
	}

	return GetSet(set->filters, set->is_filter);
}
