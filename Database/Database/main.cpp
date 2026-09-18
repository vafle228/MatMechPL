#include <map>
#include <fstream>
#include <iostream>

#include "headers/Model.h"
#include "headers/Field.h"

#include "headers/Database.h"

using namespace std;


class StudentModel : public IModel 
{
public:
    IntField f1 = IntField();
    BoolField f2 = BoolField();
    StringField f3 = StringField(10);

private:
    ModelAttrs attrs
    {
        { "age", &f1 },
        { "married", &f2 },
        { "name", &f3 },
    };

protected: ModelAttrs Attrs() override { return attrs; }
};

class FuckingModel : public IModel 
{
public:
    IntField f1 = IntField();
    BoolField f2 = BoolField();
    StringField f3 = StringField(10);

private:
    ModelAttrs attrs
    {
        { "age", &f1 },
        { "married", &f2 },
        { "name", &f3 },
    };

protected: ModelAttrs Attrs() override { return attrs; }
};

int main()
{
    Database database = Database();
    database.RegisterManagers
    ({
        new ModelManager<StudentModel>(),
        new ModelManager<FuckingModel>(),
    });

    string command = "";
    while (true) 
    {
        try 
        {
            getline(cin, command); cout << endl;
            database.ExecuteCommand(command); cout << endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
}
