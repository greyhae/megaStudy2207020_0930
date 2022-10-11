#pragma once
#include "Player.h"
#include "Enemy.h"

// ** 객체 관리
class Object;

class SingletonManager
{
private:
	static SingletonManager* Instance;
public:
	// ** 정적 변수를 사용하는 함수도 정적으로 생성해야함
	static SingletonManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SingletonManager;
		return Instance;
	}
public:
	Object* CreateObject() {return new Player;}
	Object* CreateEnemy() { return new Enemy;}
};

SingletonManager* SingletonManager::Instance = nullptr;
