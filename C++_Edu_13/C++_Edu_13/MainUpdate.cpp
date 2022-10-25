#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate(void)
{

}

MainUpdate::~MainUpdate(void)
{

}

void MainUpdate::Start(void)
{
	SceneManager::GetInstance()->SetScene(LOGOID);
}

void MainUpdate::Update(void)
{
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render(void)
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release(void)
{
	
}