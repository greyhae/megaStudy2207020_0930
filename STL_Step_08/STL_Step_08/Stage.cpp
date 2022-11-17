#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"


Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
}

void Stage::Update()
{
	cout << "Stage" << endl;
	if(GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene
}

void Stage::Render()
{

}

void Stage::Release()
{

}