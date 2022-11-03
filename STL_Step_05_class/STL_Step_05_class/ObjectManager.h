#pragma once
#include "Headers.h"
#include "Object.h"

class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<int, list<Object*>> Objects;
public:
	void AddObject(Object*);
	void Render();
private:
	ObjectManager() {};

public:
	~ObjectManager() {};
};

