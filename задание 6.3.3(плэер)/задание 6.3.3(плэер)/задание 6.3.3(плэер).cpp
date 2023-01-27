#include <iostream>
using namespace std;

class Device
{
public:
    Device(int batteryLife) : _batteryLife(batteryLife)
    {
    }


    virtual void ShowSpec()
    {
        cout << "Battery Life: " << _batteryLife << endl;
    }
protected:
    int _batteryLife;
};

class Player : public Device
{
private:
    int _totalTracks;
public:
    Player(int batteryLife, int totalTracks) : Device(batteryLife), _totalTracks(totalTracks)
    {
    }

    void ShowSpec()
    {
        cout << "Battery Life: " << _batteryLife << endl;
        cout << "Total tracks: " << _totalTracks << endl;
    }

};