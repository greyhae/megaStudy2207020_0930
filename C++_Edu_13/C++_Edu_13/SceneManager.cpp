#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SceneID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
		
	}
}
void SceneManager::Update()
{

}
void SceneManager::Render()
{

}

void SceneManager::Release()
{

}
