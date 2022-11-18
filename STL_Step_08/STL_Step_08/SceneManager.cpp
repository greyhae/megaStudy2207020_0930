#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// �ʱ�ȭ
SceneManager* SceneManager::Instance = nullptr;


SceneManager::SceneManager() : SceneState(nullptr)
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
	case SCENEID_LOGO:
		SceneState = new Logo;
		break;
	case SCENEID_MENU:
		SceneState = new Menu;
		break;
	case SCENEID_STAGE:
		SceneState = new Stage;
		break;
	case SCENEID_EXIT:
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
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Release(SceneState);
}