#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// �ʱ�ȭ
SceneManager* SceneManager::Instance = nullptr;


SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(Scene_ID id)
{
	// inline : �տ� :: ���
	if (SceneState != nullptr)
		::Safe_Release(SceneState);

	switch (id)
	{
	case SCENE_LOGO:
		SceneState = new Logo;
		break;
	case SCENE_MENU:
		SceneState = new Menu;
		break;
	case SCENE_STAGE:
		SceneState = new Stage;
		break;
	case SCENE_EXIT:
		exit(NULL);
		break;
	}
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{

}

void SceneManager::Release()
{

}