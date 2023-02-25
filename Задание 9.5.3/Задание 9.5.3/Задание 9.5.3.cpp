#include <iostream>
using namespace std;

template <class T>
class DynamicArray
{
private:
    T* _array;
    int _length;

public:
    DynamicArray(int length)
        : _array(new T[length]), _length(length)
    {
    }

    ~DynamicArray()
    {
        delete[] _array;
    }

    DynamicArray(const DynamicArray& other)
    {
        _length = other._length;
        delete[] _array;
        _array = new T[_length];
        for (int i = 0; i < _length; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        _length = other._length;
        delete[] _array;
        _array = new T[_length];
        for (int i = 0; i < _length; ++i)
        {
            _array[i] = other._array[i];
        }

        return *this;
    }

    int getLength() const { return _length; }
    T& operator[](int index) { return _array[index]; }
    const T& operator[](int index) const { return _array[index]; }
};