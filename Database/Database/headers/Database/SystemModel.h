#pragma once
#include "../Field.h"
#include "../Model/IModel.h"


const std::string MODEL_PATH = "static/SystemModel.bin";

class SystemModel : public IModel 
{
public:
	IntField last_id = IntField();
	IntField del_cnt = IntField();

	StringField db_name = StringField(24);

private:
	ModelAttrs attrs
	{
		{ "last_id", &last_id },
		{ "del_cnt", &del_cnt },
		{ "db_name", &db_name },
	};

protected: ModelAttrs Attrs() override;
};
