#include"Avocado.h"

Avocado::Avocado(int sugar, int salt) : Fruit(sugar), Vegetable(salt)
{
}
void Avocado::Show()
{
	cout << "Avocado: salt" << _salt << "sugar" << _sugar << endl;
} 