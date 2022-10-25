#include "Child.h"
#include "SceneManager.h"
#include "CursorManager.h"

Child::Child()
{
	cout << "Child 持失切 " << endl;
}
Child::~Child()
{
	cout << "Child 社瑚切 " << endl;
}

void Child::Start(void)
{
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);

	Tex[0] = "-";
	Tex[1] = "-";
	Tex[2] = "-";
}
void Child::Update(void)
{
	++Info.Position.x;

	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(EXITID);
}
void Child::Render(void)
{
	/*Transform t;
	Vector3 v = Vector3(0.0f, 0.0f, 0.0f);

	t.Position = Vector3(0.0f, 0.0f, 0.0f);

	t.Position += v;
	*/

	for(int i = 0; i < 3; ++i)
		CursorManager::Renderer(
		Info.Position.x,
		Info.Position.y + i,
		Tex[i], 5);

}
void Child::Release(void)
{

}
