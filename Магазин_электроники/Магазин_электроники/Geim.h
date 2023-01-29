#pragma once
#include"audio.h"
#include"Video.h"

class Geim final : public audio, public Video
{
public:
	Geim(int disk, int transxlukator);
	void Show() override;
};
