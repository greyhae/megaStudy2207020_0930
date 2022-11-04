#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class vector3;
typedef vector3* vector3;
class ObjectFactory
{
public:
	// ** template은 class 위에서 사용하는 것보다 함수 위에서 사용한다.
	template <typename T>
	static Object* CreateObject()
	{
		return new T();
	}

	static Object* CreateObject(string name)
	{
		return new T(name);
	}

	/*
	static Object* CreateObject(float _x, float _y)
	{
		return new T();
	}

	static Object* CreateObject(Vector Position)
	{
		return new T();
	}

	static Object* CreateObject(float _x, float _y, string name)
	{
		Object* pObj = new T();
		return  pObj->SetName(name)->SetX(_x)->SetY(_y);
	}

	static Object* CreateObject(Vector Position, string name)
	{
		return new T(name);
	}
	*/
private:
	ObjectFactory() {};
	~ObjectFactory() {};
};
