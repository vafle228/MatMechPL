#include <fstream>

#include "../../headers/Model/ModelManager.h"

#include "../../headers/Database/Database.h"
#include "../../headers/Database/CommandParser.h"


const std::string MODEL_ROOT = "static/";

Database::Database()
{
	system_manager.SetModelStream(MODEL_PATH);
	std::string system_model = system_manager.GetModelName();

	SystemModel* blank = new SystemModel();
	((IModel*)blank)->UpdateModel({ {"db_name", system_model} });
	managers[system_model] = ModelData(blank, &system_manager);

	RegisterManagers({ &system_manager });
}

void Database::ExecuteCommand(std::string command)
{
	DatabaseCommand db_command; 
	db_command = db_command(command);
	ModelManagerBase* manager = managers[db_command.db_name].second;

	if (db_command.command == "PRINT")
		PrintModelInstance(db_command.db_name, {}, true);

	if (db_command.command == "CREATE")
		CreateModelInstance(db_command.db_name, db_command.params);

	if (db_command.command == "SELECT")
		PrintModelInstance(db_command.db_name, db_command.filters, true);

	if (db_command.command == "EXCLUDE")
		PrintModelInstance(db_command.db_name, db_command.filters, false);

	if (db_command.command == "UPDATE")
		UpdateModelInstance(db_command.db_name, db_command.filters, db_command.params);

	if (db_command.command == "DELETE")
		DeleteModelInstance(db_command.db_name, db_command.filters);
}

void Database::RegisterManagers(std::vector<ModelManagerBase*> managers)
{	
	for (auto manager : managers)
	{
		ModelParams fiter{ {"db_name", manager->GetModelName()} };
		
		ModelSetBase* set = system_manager.GetSet(fiter, true);
		auto system_data = (SystemModel*)set->FindNextModel();
		
		if (system_data == nullptr) 
		{
			AddNewModel(manager->GetModelName());
			ModelSetBase* set = system_manager.GetSet(fiter, true);
			system_data = (SystemModel*)set->FindNextModel();
		}
		manager->SetModelStream(MODEL_ROOT + manager->GetModelName() + ".bin");
		this->managers[manager->GetModelName()] = ModelData(system_data, manager);
	}
}

void Database::PrintModelInstance(std::string model_name, ModelParams condition, bool filter)
{
	ModelManagerBase* manager = managers.at(model_name).second;
	manager->Print(manager->GetSet(condition, filter));
}

void Database::DeleteModelInstance(std::string model_name, ModelParams condition)
{
	ModelData metadata = managers.at(model_name);

	ModelManagerBase* manager = metadata.second;
	ModelSetBase* set = manager->GetSet(condition, true);
	
	ModelParams upd_condition = { {"db_name", model_name} };
	metadata.first->del_cnt.value += manager->Delete(set);

	UpdateModelInstance(system_manager.GetModelName(), upd_condition, metadata.first->GetParams());
}

ModelSetBase* Database::CreateModelInstance(std::string model_name, ModelParams params)
{
	ModelData metadata = managers.at(model_name);
	params["id"] = std::to_string(metadata.first->last_id.value + 1);
	
	ModelParams upd_condition = { {"db_name", model_name} };
	ModelSetBase* return_set = metadata.second->Create(params);
	
	metadata.first->last_id.value += 1;
	UpdateModelInstance(system_manager.GetModelName(), upd_condition, metadata.first->GetParams());

	return return_set;
}

ModelSetBase* Database::UpdateModelInstance(std::string model_name, ModelParams condition, ModelParams params)
{
	ModelData metadata = managers.at(model_name);
	
	ModelManagerBase* manager = metadata.second;
	ModelSetBase* set = manager->GetSet(condition, true);

	return manager->Update(set, params);
}

void Database::AddNewModel(std::string model_name)
{
	auto system_model = system_manager.GetModelName();
	std::ofstream f(MODEL_ROOT + model_name + ".bin"); f.close();

	if (model_name == system_manager.GetModelName())
		system_manager.SetModelStream(MODEL_ROOT + model_name + ".bin");

	ModelParams params
	{
		{"id", managers.at(system_model).first->last_id.ToString()},
		{"del_cnt", "0"}, {"last_id", "0"}, {"db_name", model_name},
	};
	CreateModelInstance(system_model, params);
}
