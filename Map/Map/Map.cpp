#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map <string, int> myMap = { { "John", 27 },
                              { "Bob", 20 },
                              { "Alice", 19 },
                              { "Tony", 23 } };


    for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    vector<string> Cities{ "Moscow", "Madrid", "London", "New York", "Helsinki" };
    map <int, string> CitiesGrade;
    for (int i = 0; i < 5; ++i)
    {
        CitiesGrade.insert(pair<int, string>(i, Cities[i]));
    }

    for (map<int, string>::iterator it = CitiesGrade.begin(); it != CitiesGrade.end(); ++it)
    {
        cout << (*it).first << " : " << (*it).second << endl;
    }
    return 0;

    /*
    map <string,int> myMap;
  pair<string,int> bob = make_pair<string,int>("Bob", 20);
  
  myMap.insert(bob);
  myMap.insert({ "John", 23 });
  myMap["Tony"] = 33;
  
  for (map<string,int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
  {
      cout << it->first << " : " << it->second << endl;
  }
 
 
 myMap["Tony"] = 21;
 
   for (map<string,int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
  {
      cout << it->first << " : " << it->second << endl;
  }
    */

}