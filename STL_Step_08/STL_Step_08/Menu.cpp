#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::Start()
{

}

void Menu::Update()
{
	cout << "Logo" << endl;
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
}

void Menu::Render()
{

}

void Menu::Release()
{

}