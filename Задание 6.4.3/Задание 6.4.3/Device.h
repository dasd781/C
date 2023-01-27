#pragma once

#include "IElectronics.h"
class Device : public IElectronics
{
public:
    Device(int batteryLife);
    virtual void ShowSpec() override;

protected:
    int _batteryLife;
};
