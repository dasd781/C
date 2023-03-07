#include<iostream>
#include<memory>
using namespace std;

class Int
{
public:
	Int(int i = 0) : _int(i)
	{
		cout << "constructor : " << _int << endl;
	}
	~Int()
	{
		cout << "destructor : " << _int << endl;
	}
	void SetInt(int i)
	{
		_int = i;
		cout << " Int set to : " << _int << endl;
	}
	int GetInt()
	{
		return _int;
	}
private:
	int _int;
};
int main()
{
	auto_ptr<Int> ptr(new Int(3));// создали обьект Int с значением 3 и поместили его в умный указатель
	(*ptr).SetInt(1);//получили обьект с помощью операции разменования и присвоили значение 1
	cout << "object value : " << ptr->GetInt() << endl;//получили значение от обьекта int
	cout << "object value using get : " << ptr.get()->GetInt() << endl;// тоже с помощью get

	return 0;
}