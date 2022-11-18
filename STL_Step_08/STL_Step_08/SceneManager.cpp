#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

// 초기화
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
	// inline : 앞에 :: 사용
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