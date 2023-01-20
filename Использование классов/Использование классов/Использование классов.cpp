#include <iostream>
using namespace std;

class Module
{
public:
    void setSize(int size)
    {
        if (size > 0)
            moduleSize = size;
        else cout << "Нет нет нет, такое значение задать нельзя";
    }
    void initModule(const char* name, short tasks, int units, long size)
    {
        moduleName = name;
        tasksCount = tasks;
        unitsCount = units;
        moduleSize = size;
    }
    void setName(const char* name)
    {
        moduleName = name;
    }
    void displayModule()
    {
        cout << "Имя модуля: " << moduleName << endl;
        cout << "Количество задач: " << tasksCount << endl;
        cout << "Количество юнитов: " << unitsCount << endl;
        cout << "Размер модуля в страницах: " << moduleSize << endl;
    }
private:
    const char* moduleName;
    short tasksCount;
    int unitsCount;
    long moduleSize;
};

int main()
{
    Module m;  //Производим какие-то операции с модулем 
    return 0;
}