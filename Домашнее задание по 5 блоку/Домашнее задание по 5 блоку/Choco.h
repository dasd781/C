#pragma once
#include <iostream>

using namespace std;

namespace study
{
    class Module
    {
    public:

        Module(const char* name, short slot, short snickers, short bounty);
        Module(const char* name, short slot);
        Module(const char* name);
        Module(const Module& other);

        ~Module() = default;

        Module& operator++();
        Module& operator--();

        friend ostream& operator<<(ostream& output, const Module& m);

        const char* getModuleName() const;
        void setModuleName(const char* value);

        short getSlotCount() const;
        void setSlotCount(short value);

        short getSnickersCount() const;
        void setSnickersCount(short value);

        short getBountyCount() const;
        void getBountyCount(short value);

        void setBountyCount(short value);

    private:
        const char* moduleName;
        short SlotCount;
        short SnickersCount;
        short BountyCount;
    };

}