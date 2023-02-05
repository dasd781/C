#include <iostream>
using namespace std;

class BaseException
{
public:
    BaseException() {}
};

class DerivedException : public BaseException
{
public:
    DerivedException() {}
};

class MoreDerivedException : public DerivedException
{
public:
    MoreDerivedException() {}
};

int main()
{
    try
    {
        throw DerivedException();
    }
    catch (const MoreDerivedException& derived)
    {
        cout << "Exception: caught MoreDerived class" << endl;
    }
    catch (const DerivedException& derived)
    {
        cout << "Exception: caught Derived class" << endl;
    }
    catch (const BaseException& base)
    {
        cout << "Exception: caught Base class" << endl;
    }


    return 0;
}
