#include <vector>
#include <iostream>
using namespace std;

int main()
{
//��� ������� � ������ ������ �������� ���������� ������ push_back, 
//emplace_back, insert � emplace.
    std::vector<int> v;

    v.push_back(2);
    v.push_back(4);
    int a = 5;
    v.push_back(a);

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
    return 0;
}