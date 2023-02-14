#include<iostream>
#include<string>
using namespace std;

typedef unsigned int uint;
enum class Color:long long;
void foo(Color a);
enum class Color : long long { red = -30000, yellow = -3, grin = 0, blue };

struct Glass
{
	string type;
};

struct Door
{
	double width;
	double length;
	Glass glass;
};

 struct Car
 {
	 int width = 50 ;
	 int length : 16;//можно установить сколько бит будет занимать каждый элемент структуры
	 int wheels;
	 string name;
	 uint seats;
	 Door door;
	 int for_bool : 31;
	 bool a : 1;

	 struct SteeringWheel
	 {
		 string type;
	 };
 };

int main()
{
	int array[10];

	double d;
	Car my_car;

	Car::SteeringWheel wheel;
	my_car.door.glass.type;




	my_car.name = "The best car ";
	my_car.length = 100;

	cout << sizeof(Car) << "\n";
	cout << my_car.name << ", lrngth = " << my_car.length << ", width = " << my_car.width;




	/*Color a = Color::blue;

	switch (a)
	{
	case Color::blue:
	{
		cout << "it ' s blue ";
		break;
	}
	default:
	{
		cout << "not blue";
		break;
	}

	}
	int blue = -7;
	cout << (int) Color::blue << endl;*/
	return 0;

}