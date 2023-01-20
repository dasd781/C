#include "Choco.h"
#include <iostream>
using namespace std;

namespace study
{

    Module::Module(const char* name, short slot, short snickers, short bounty)
    {
        moduleName = name;
        SlotCount = slot;
        SnickersCount = snickers;
        BountyCount = bounty;
    }

    Module::Module(const char* name, short slot)
    {
        moduleName = name;
        SlotCount = slot;
    }

    Module::Module(const char* name)
    {
        moduleName = name;
    }

    Module::Module(const Module& other)
    {
        this->moduleName = other.moduleName;
        this->SlotCount = other.SlotCount;
        this->SnickersCount = other.SnickersCount;
        this->BountyCount = other.BountyCount;
    }

    Module& Module::operator++()
    {
        ++BountyCount;
        return *this;
    }

    Module& Module::operator--()
    {
        --BountyCount;
        return *this;
    }

    const char* Module::getModuleName() const
    {
        return moduleName;
    }

    void Module::setModuleName(const char* value)
    {
        moduleName = value;
    }

    short Module::getSlotCount() const
    {
        return SlotCount;
    }

    void Module::setSlotCount(short value)
    {
        SlotCount = value;
    }

    short Module::getSnickersCount() const
    {
        return SnickersCount;
    }

    void Module::setSnickersCount(short value)
    {
        char s = 0;
        if (value > 0)
            SnickersCount = value;
        else
            cout << "Шоколад кончился";

    }

    short Module::getBountyCount() const
    {
        return BountyCount;
    }

    void Module::setBountyCount(short value)
    {
        char b = 0;
        if (value > 0)
            BountyCount = value;
        else
            cout << "Шоколад кончился";
    }

    ostream& operator<<(ostream& output, const Module& m)
    {
        output << "Имя аппарата: " << m.moduleName << endl
            << "Количество слотов: " << m.SlotCount << endl
            << "Количество батончиков Snickers: " << m.SnickersCount << endl
            << "Количество батончиков Bounty: " << m.BountyCount << endl;
        return output;
    }

}