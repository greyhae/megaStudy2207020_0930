#pragma once
#include "Headers.h"

class Prototype
{
private:
	static Prototype* Instance;
public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype;
		return Instance;
	}
private:
	Prototype() {}
public:
	~Prototype() {}
};

Prototype* Prototype::Instance = nullptr;