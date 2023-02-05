 /*float harmonic_mean(float arr[], int size)
{
    assert(size && "Array size 0!");
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        assert((arr[i] > 0.0001 || arr[i] < -0.0001) && "Array element 0!");
        sum = sum + 1.0 / arr[i];
    }

    assert((sum > 0.0001 || sum < -0.0001) && "The sum of the array elements is 0!");
    return size / sum;
}*/

/*
 гармонически среднее с применением #include<climits>
bool harmonic_mean(float arr[], int size, float& hmean)
{
    if (size != 0)
    {
        float sum = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == 0.0)
            {
                hmean = 0.0;
                return false;
            }
            sum = sum + 1.0 / arr[i];
        }

        if ((sum < -0.0001) && (sum > 0.0001))
        {
            hmean = size/sum;
            return true;
        }

    }
    hmean = 0.0;
    return false;
}
*/

#include<iostream>
#include<climits>
using namespace std;

bool Divide(int a, int b, int& result)
{
    if (b != 0)
    {
        result = a / b;
        return true;
    }
    else
    {
        result = INT_MAX;
        return false;
    }
}
int main()
{
    int a = 4;
    int b = 0;
    int result;

    
    
        if (Divide (a, b, result))
        {
            cout << "result : " << endl;
        }
        else
        {
            cout << "try agan  " << endl;
        }
        return 0;
}