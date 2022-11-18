#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}
