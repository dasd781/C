#include <stack>
#include <iostream>
using namespace std;
int main()
{
    stack<int>   s;

    s.push(3);
    s.push(6);
    s.push(65);
    cout << "is empty: " << s.empty() << endl;
    cout << s.size() << " elements on stack" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << s.size() << " elements on stack" << endl;

    s.pop();
    cout << s.size() << " elements on stack after pop" << endl;

    cout << "Top element after pop: " << s.top() << endl;
    return 0;
}