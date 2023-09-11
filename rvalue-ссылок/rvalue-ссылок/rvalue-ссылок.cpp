void func(int&& k) {
}
int main()
{
    int n;
    func(n); // ошибка
    func(std::move(n)); // ок
    return 0;
}


class A {
};

int main()
{
    A a;
    a = A(); // A() - временный объект, r-value
}


class A {
};

int main()
{
    A a;

    A& a_ref = a;  // lvalue-ссылка
    const A& a_cref = a;  // константная lvalue-ссылка
    const A& a_cref2 = A(); // так можно

    A&& a_rref = std::move(a);  // rvalue-ссылка, полученная из lvalue
    A&& a_rref2 = A();  // rvalue-ссылка
}

class A {
};

int main()
{
    A a = A();
    // ~A()
    //some code
    {
        const A& a_cref = A();
        A&& a_rref = A();
        // some code
    } // ~A(), ~A()
}

lass A{
    public:
        void someFunc() {

        }
};

int main()
{
    A a;

    A& a_lref = a;
    A&& a_rref = std::move(a);

    a_lref.someFunc();
    a_rref.someFunc();
}


int main()
{
    std::string str = "somestr";
    std::string& lr = str;
    std::string&& rr = static_cast<std::string&&>(lr);  // плохой тон
}