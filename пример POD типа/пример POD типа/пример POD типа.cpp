//создадим простой класс
class SomeClass
{
public:
    SomeClass()
    {
        //в конструкторе будем делать вывод в поток вывода, что отработал конструктор
        std::cout << "SomeClass::constructor" << std::endl;
    }

    ~SomeClass()
    {
        //в деструкторе, что отработал деструктор
        std::cout << "SomeClass::destructor" << std::endl;
    }
};


int main(int argc, char* argv[])
{
    SomeClass* obj = new SomeClass();
    delete obj;
}
Вывод:

SomeClass::constructor
SomeClass::destructor
Как видно из примера, при вызове new вызывается конструктор, при вызове delete — деструктор.Вообще, как вы помните, конструктор вызывается всегда при создании объекта, а деструктор вызывается при удалении объекта.

Например, следующий код будет иметь такой же вывод :

int main(int argc, char* argv[])
{
    //локальный объект создается на стеке...
    SomeClass obj;
    return 0;
} // и уничтожается в конце области видимости