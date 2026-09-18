#pragma once
#include "IModel.h"
#include "ModelConnect.h"

#define ModelParams std::map<std::string, std::string>


class ModelSetBase
{
public:
	ModelSetBase(ModelConnect connect, ModelParams condition, bool filter = true);
	
	IModel* FindNextModel();

protected:
	bool is_filter;
	
	ModelParams filters;
	ModelConnect connect;

	virtual IModel* CreateInstance() = 0;

friend ModelManagerBase;
};

template<typename ModelT>
class ModelSet : public ModelSetBase 
{
public:
	ModelSet(ModelConnect connect, ModelParams condition, bool filter = true);

protected:
	IModel* CreateInstance();
};

#pragma region ModelSet
template<typename ModelT>
inline ModelSet<ModelT>::ModelSet(ModelConnect connect, ModelParams condition, bool filter)
	: ModelSetBase(connect, condition, filter)
{ }

template<typename ModelT>
inline IModel* ModelSet<ModelT>::CreateInstance()
{
	return new ModelT();
}
#pragma endregion
