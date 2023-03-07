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

    // Copy constructor
    DynamicArray(const DynamicArray& arr) = delete;

    // Copy assignment
    DynamicArray& operator=(const DynamicArray& arr) = delete;

    // Move constructor
    DynamicArray(DynamicArray&& arr) noexcept
        : _length(arr._length), _array(arr.m_array)
    {
        arr._length = 0;
        arr._array = nullptr;
    }

    // Move assignment
    DynamicArray& operator=(DynamicArray&& arr) noexcept
    {
        if (&arr == this)
            return *this;

        delete[] _array;

        _length = arr._length;
        _array = arr._array;
        arr._length = 0;
        arr._array = nullptr;

        return *this;
    }

    int getLength() const { return _length; }
    T& operator[](int index) { return _array[index]; }
    const T& operator[](int index) const { return _array[index]; }
};