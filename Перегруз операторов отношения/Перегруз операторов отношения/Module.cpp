#include "Module.h"

bool Module::operator>(const Module &other)
{
    return this->moduleSize < other.moduleSize;
    //���������� ���� ������ ���������� true
}
bool Module::operator<(const Module& other)
{
    return this->moduleSize > other.moduleSize;
    //���������� ���� ������ ���������� true
}
