#include "Logo.h"
#include "SceneManager.h"

Logo::Logo(void)
{

}

Logo::~Logo(void)
{

}

void Logo::Start(void)
{

}

void Logo::Update(void)
{
	if(GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MENUID);

}

void Logo::Render(void)
{

}

void Logo::Release(void)
{

}

