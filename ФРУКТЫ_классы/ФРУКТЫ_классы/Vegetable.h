#pragma once
#include"IFood.h"

class Vegetable : virtual public IFood
{
public:
	Vegetable(int salat);
	void Show() override;
protected:
	int _salt;
};
class Potato final : public Vegetable
{
public:
	Potato(int salat, int starch);
	void Show() override;
private:
	int _starch;
};
class Tomato final : public Vegetable
{
public:
	Tomato(int salat, string shape);
	void Show() override;
private:
	string _shape;
};

