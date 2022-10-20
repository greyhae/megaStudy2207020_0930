#include "Logo.h"
#include "SceneManager.h"
#include "Child.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start(void)
{
	cout << "Logo" << endl;
}
void Logo::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(LOGOID);
}

void Logo::Render(void)
{

}

void Logo::Release(void)
{

}


