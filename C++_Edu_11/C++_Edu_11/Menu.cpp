#include "Menu.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Child.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Start(void)
{
	cout << "Menu" << endl;

	ObjectManager::GetInstance()->SetObjects(*(*Objects));

	for (int i = 0; i < EndID; ++i)
	{
		for (int j = 0; j < MaxID; ++j)
		{
			Objects[i][j] = new Child;
			Objects[i][j]->Start();
		}
	}
	SceneManager::GetInstance()->SetScene(STAGEID);
}
void Menu::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MENUID);
}

void Menu::Render(void)
{

}

void Menu::Release(void)
{

}


