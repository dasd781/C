#pragma once
#include"IFood.h"

class Fruit :  virtual public IFood
{
public:
	Fruit(int sugar);

	void Show() override;
protected:
	int _sugar;
};
class Apple final : public Fruit
{
public:
	Apple(int sugar, string color);
	void Show() override;
private:
	string _color;
 };
class Banana final :public Fruit
{
public:
	Banana(int sugar, int ripeness);
	void Show() override;
private:
	int _ripeness;
};
