#pragma once
#include "Player.h"
#include "Enemy.h"

// ** 관리자 클래스로 사용하기 위함
// ** 단 하나의 인스턴스만 사용하고 싶을 때 사용한다.
class Object;
class SingletonManager
{
private:
	// ** static 정적은 런타임 이전
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
	Object* CreatePlayer() {return new Player;}
	Object* CreateEnemy() { return new Enemy;}

	// ** private 생성자 함수 만들어주면 다른 곳에서 new SingletonManager 생성할 수 없음(불필요한 인스턴스 생성 안되게)
private:
	SingletonManager()
	{

	}
};

// 초기화
SingletonManager* SingletonManager::Instance = nullptr;
