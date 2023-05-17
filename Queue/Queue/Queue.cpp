#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> myQueue;

    myQueue.push("Hello");
    myQueue.push("From");
    myQueue.push("Queue");

    cout << "Queue size: " << myQueue.size() << endl;
    cout << "Queue front" << myQueue.front() << endl;
    cout << "Queue back" << myQueue.back();

    myQueue.pop();
    cout << "New queue front: " << myQueue.front();
    return 0;
}