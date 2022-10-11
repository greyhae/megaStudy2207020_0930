#pragma once
#include "Player.h"
#include "Enemy.h"

// ** ��ü ����
class Object;

class SingletonManager
{
private:
	static SingletonManager* Instance;
public:
	// ** ���� ������ ����ϴ� �Լ��� �������� �����ؾ���
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
