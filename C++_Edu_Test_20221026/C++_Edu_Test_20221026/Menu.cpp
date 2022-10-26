#include "Menu.h"
#include "SceneManager.h"

Menu::Menu(void)
{

}

Menu::~Menu(void)
{

}

void Menu::Start(void)
{

}

void Menu::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(STAGEID);
}

void Menu::Render(void)
{

}

void Menu::Release(void)
{

}


