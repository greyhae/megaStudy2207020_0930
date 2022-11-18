#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start()
{

}

void Logo::Update()
{
	cout << "Logo" << endl;
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void Logo::Render()
{

}

void Logo::Release()
{

}
