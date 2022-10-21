#include "Logo.h"
#include "SceneManager.h"
#include "Child.h"
#include "CursorManager.h"

//http://patorjk.com/software/taag/
Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start(void)
{
	cout << "Logo Start" << endl;
}
void Logo::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MENUID);
}

void Logo::Render(void)
{

}

void Logo::Release(void)
{

}


