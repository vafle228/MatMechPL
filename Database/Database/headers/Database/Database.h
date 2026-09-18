#pragma once
#include <vector>

#include "SystemModel.h"
#include "../Model/ModelSet.h"
#include "../Model/ModelManager.h"

#define SystemManager ModelManager<SystemModel>
#define ModelData std::pair<SystemModel*, ModelManagerBase*>
#define RegisteredManagers std::map<std::string, ModelData>


class Database 
{
public:
	Database();

	void ExecuteCommand(std::string command);

	void RegisterManagers(std::vector<ModelManagerBase*> managers);

	void DeleteModelInstance(std::string model_name, ModelParams condition);
	void PrintModelInstance(std::string model_name, ModelParams condition, bool filter);

	ModelSetBase* CreateModelInstance(std::string model_name, ModelParams params);
	ModelSetBase* UpdateModelInstance(std::string model_name, ModelParams condition, ModelParams params);

private:
	SystemManager system_manager = SystemManager();
	RegisteredManagers managers = RegisteredManagers();

	void AddNewModel(std::string model_name);
};