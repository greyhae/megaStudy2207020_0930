#pragma once
#include "Headers.h"

class Object;
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
	map< string, list<Object*>>* EnableList;
	map< string, list<Object*>>* DisbleList;
public:
	void Initialize();
	void DisableFormEnable();
	//void EnableFormDisable(Object* _pObj)
	void EnableFormDisable();
	void Render();
private:
	ObjectManager();
public:
	~ObjectManager();
};

