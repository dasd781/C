#include"Fruit.h"

Fruit::Fruit(int sugar) : _sugar(sugar)
{
}
void Fruit::Show()
{
	cout << "Basic Fruit sugar :" << _sugar << endl;
}
Apple::Apple(int sugar, string color) : Fruit(sugar), _color(color)
{
}
void Apple::Show()
{
	cout << _color << "Apple, sugar per 100g :" << _sugar << endl;
}
Banana::Banana(int sugar, int ripeness) : Fruit(sugar)
, _ripeness(ripeness)
{
}
void Banana::Show()
{
	cout << "Banana , ripeness :" << _ripeness << "sugar per 100g"
		<< _sugar << endl;
}