#include "Module.h"

bool Module::operator>(const Module &other)
{
    return this->moduleSize < other.moduleSize;
    //сравниваем если меньше возвращаем true
}
bool Module::operator<(const Module& other)
{
    return this->moduleSize > other.moduleSize;
    //Сравниваем если больше возвращаем true
}
