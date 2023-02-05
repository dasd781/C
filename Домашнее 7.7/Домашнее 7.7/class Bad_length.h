#pragma once
#include<exception>
#include<string>

class Bad_lenght :public _exception
{
public:
	virtual const char* what()const noexcept
	{
		return "EROR: Bad_Lenght!";
	}
};