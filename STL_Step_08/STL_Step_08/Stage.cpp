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
	pPlayer->Render();
	/*
	cout << "Stage" << endl;
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
	*/
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{

}