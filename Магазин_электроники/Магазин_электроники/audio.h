#pragma once
#include"Texnic.h"

class audio : virtual public Texnic
{
public:
	audio(int disk);
	void Show()override;
protected:
	int _disk;
};
class kolonka final : public audio
{
public:
	kolonka(int disk, string color);
	void Show() override;
private:
	string _color;
};
class pleir final : public audio
{
public:
	pleir(int disk, int headphone);
	void Show() override;
private:
	int _headphone;
};
