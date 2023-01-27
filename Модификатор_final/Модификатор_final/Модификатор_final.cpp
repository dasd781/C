/*class Base final//обьявление финалом
{
public:
	virtual void Show()
	{
		cout << "Base class" << endl;
	}
};
class Derived : public Base // ошибка компиляции класс Base обьявлен final
*/
class Base
{
public :
	virtual void Show() final
	{
		cout << "Base class" endl;
	}
 };
class Derived : public Base
{
public:
	void Show() override // ошибка компиляции метод Show родительского класса 
		// указан как final его нельзя переопределить
	{
		cout << "Derived class" << endl;
	}
};

