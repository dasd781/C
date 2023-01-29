#pragma once
#include"Texnic.h"

class Video : virtual public Texnic
{
public:
	Video(int sound);
	void Show() override;
protected:
	int _sound;
};
class Camera final : public Video
{
public:
	Camera(int sound, int focus);
	void Show() override;
private :
	int _focus;
};
class  television_set final : public Video
{
public:
	television_set(int sound, string wifi);
		void Show() override;
protected:
	string _wifi;
};