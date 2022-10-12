#pragma once
#include "Player.h"
#include "Enemy.h"

// ** ������ Ŭ������ ����ϱ� ����
// ** �� �ϳ��� �ν��Ͻ��� ����ϰ� ���� �� ����Ѵ�.
class Object;
class SingletonManager
{
private:
	// ** static ������ ��Ÿ�� ����
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
	Object* CreatePlayer() {return new Player;}
	Object* CreateEnemy() { return new Enemy;}

	// ** private ������ �Լ� ������ָ� �ٸ� ������ new SingletonManager ������ �� ����(���ʿ��� �ν��Ͻ� ���� �ȵǰ�)
private:
	SingletonManager()
	{

	}
};

// �ʱ�ȭ
SingletonManager* SingletonManager::Instance = nullptr;
