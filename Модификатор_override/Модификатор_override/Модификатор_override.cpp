class Base
{
public:
	virtual void Show()
	{
		cout << "Base class" << endl;
	}
};
class Derived : public Base
{
public:
	void Show(int a) override// ошибка компиляции  метод     Show родительского класса не 
		// принемает аргументов 
	{
		cout << "Derived class" << endl;
	}
};