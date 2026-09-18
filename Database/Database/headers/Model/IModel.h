#pragma once
#include <map>
#include <string>

#include "../Field/IField.h"
#include "../Field/IntField.h"

#define ModelAttrs std::map<std::string, IField*>
#define ModelParams std::map<std::string, std::string>


class Database;
class ModelSetBase;
class ModelManagerBase;

class IModel
{
private:
	IntField id = IntField();

	ModelAttrs GetAttrs();
	
	IModel* UpdateModel(ModelParams params);
	IModel* CreateModel(ModelParams params);

public: ModelParams GetParams();

protected: virtual ModelAttrs Attrs() = 0;

friend Database;
friend ModelSetBase;
friend ModelManagerBase;
};