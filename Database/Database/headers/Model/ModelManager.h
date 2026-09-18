#pragma once
#include <map>
#include <string>
#include <fstream>

#include "IModel.h"
#include "ModelSet.h"
#include "ModelConnect.h"

#include "../Utils/Utils.h"

#define ModelParams std::map<std::string, std::string>


class ModelManagerBase
{
public:
	void Print(ModelSetBase* set);
	unsigned int Delete(ModelSetBase* set);

	void SetModelStream(std::string path);
	virtual std::string GetModelName() = 0;

	ModelSetBase* Create(ModelParams params);
	ModelSetBase* Update(ModelSetBase* set, ModelParams params);

	virtual ModelSetBase* GetSet(ModelParams params, bool filter) = 0;

protected:
	std::fstream model_stream;

	virtual IModel* CreateInstance() = 0;
};

template<typename ModelT>
class ModelManager : public ModelManagerBase 
{
public:
	std::string GetModelName() override;
	ModelSetBase* GetSet(ModelParams params, bool filter) override;

protected:
	IModel* CreateInstance() override;
};

#pragma region ModelManager
template<typename ModelT>
inline std::string ModelManager<ModelT>::GetModelName() 
{ 
	return Split(typeid(ModelT).name())[1];
}

template<typename ModelT>
inline ModelSetBase* ModelManager<ModelT>::GetSet(ModelParams params, bool filter)
{
	return new ModelSet<ModelT>(ModelConnect(&model_stream), params, filter);
}

template<typename ModelT>
inline IModel* ModelManager<ModelT>::CreateInstance()
{
	return new ModelT();
}
#pragma endregion
