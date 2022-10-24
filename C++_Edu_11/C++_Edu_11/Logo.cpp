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
	//cout << "Logo Start" << endl;
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	Color = 0;
	SwitchColor = 0;
	Time = GetTickCount64();
	DelayTime = 50;


}
void Logo::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MENUID);


	if (Time + DelayTime < GetTickCount64())
	{
		Time = GetTickCount64();

		//++SwitchColor;
	}
}

void Logo::Render(void)
{
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 0, "	⋱ ⋮ ⋰", 5);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 1, "⋯ ◯ ⋯ ︵ 　　　　　　^v^", 5);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 2, "¸︵︵( ░░ )︵.︵.︵　　", 5);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 3, "(''░░░░░░ ') ░░░' )", 5);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 4, "'''︶'¯'︶''︶'︶'　^v^　　^v^", 5);

}

void Logo::Release(void)
{


}