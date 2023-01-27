#include "Fruit.h"
class Apple :public Fruit
{
private :
	string _color;
public:
	Apple(int sugar, const string& color) :Fruit(sugar), _color(color)
	{
	}
	void ShowColor()
	{
		cout << "sugar :" << _sugar << endl;
		cout << _color << "Apple" << endl;   
	}
};


int main()
{
	Apple apple(10, "green");
	apple.Show();
	apple.ShowColor();
	return 0;
}
