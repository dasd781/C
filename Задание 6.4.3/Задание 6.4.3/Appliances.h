#pragma once

#include "IElectronics.h"

class Appliances : public IElectronics
{
public:
    Appliances(int weight);
    void ShowSpec() override;

protected:
    int _weight;
};
