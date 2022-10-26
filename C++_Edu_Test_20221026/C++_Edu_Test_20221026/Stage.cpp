#include "Stage.h"
#include "SceneManager.h"

Stage::Stage(void)
{

}

Stage::~Stage(void)
{

}

void Stage::Start(void)
{

}

void Stage::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(EXITID);
}

void Stage::Render(void)
{

}

void Stage::Release(void)
{

}

