#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello ";
    string str2 = "world!";

    string str3 = str1 + str2; //присваивание (=) и конкатенация (+) строк 
    cout << str3 << endl; //Hello world!  

    str1 += str2; //присваивание с конкатенацией
    cout << str1 << endl; //Hello world!  

    bool boolean;
    boolean = str1 == str2; //сравнение строк (==)
    cout << boolean << endl; //0 - false

    boolean = str1 != str2; //сравнение (не равно)
    cout << boolean << endl;//1 - true
    boolean = str1 > str2; //сравнение больше (>)
    cout << boolean << endl; //0 - false 

    boolean = str1 < str2; //сравнение меньше (<)
    cout << boolean << endl; //1 - true

    boolean = str1 >= str2; // сравнение больше или равно (>=)
    cout << boolean << endl; //0 - false 

    boolean = str1 <= str2;// сравнение меньше или равно (<=)
    cout << boolean << endl; //1 - true

    char indexOfString;
    indexOfString = str1[0]; //индексация (по индексу извлекаем элемент строки)     
    cout << indexOfString << endl; // "H"
    return 0;
}