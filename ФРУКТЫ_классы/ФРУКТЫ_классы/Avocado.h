#pragma once
#include"Vegetable.h"
#include"Fruit.h"

class Avocado final : public Fruit, Vegetable
{
public:
	Avocado(int sugar, int salt);
	void Show() override;
};
