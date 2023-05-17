#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
    Person(const string& name_, int age_) : name(name_), age(age_) {}
};

int main()
{
    std::vector<Person> v;
    Person john("John", 20);
    v.push_back(john);
    v.emplace_back("Tony", 19);


    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].name << " " << v[i].age << endl;
    }
    return 0;
}