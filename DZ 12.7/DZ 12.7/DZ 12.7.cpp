#include <iostream>
#include <string>

using namespace std;

bool IsKPeriodic(const string& s, int K)
{
    if (s.length() % K != 0)
    {
        cout << "Строка не делится на " << K << " без остатка" << endl;
        return false;
    }

    for (int i = 1; i < s.length() / K; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            if (s[i * K + j] != s[j])
            {
                cout << "Строка не является кратной числу " << K << endl;
                return false;
            }
        }
    }
    cout << "Строка является кратной числу " << K << endl;
    return true;
}

int main()

{
    setlocale(LC_ALL, "");

    cout << "Введите строку : " << endl;
    string S;
    cin >> S;

    cout << "Введите число : " << endl;
    int K;
    cin >> K;

    IsKPeriodic(S, K);

    return 0;
}