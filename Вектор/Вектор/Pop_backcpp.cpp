#include <vector>
#include <iostream>
using namespace std;


//��� �������� ��������� ���������� ������ 
//pop_back � �������� � ����� ������� � clear � �������� ����� �������:
int main()
{
    std::vector<int> v;

    v.push_back(2);
    v.push_back(4);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    v.pop_back();
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    v.clear();
    cout << "is empty: " << v.empty() << endl;
    return 0;
}