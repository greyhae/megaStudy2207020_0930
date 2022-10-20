#include "Stage.h"
#include "Child.h"

Stage::Stage(void)
{

}

Stage::~Stage(void)
{

}

void Stage::Start(void)
{
	// ** 생성하기 위해서는 해당하는 클래스 파일을 인클루드 해야함
	//Testcase = new Child;
	//Testcase->Start();
}
void Stage::Update(void)
{
	//Testcase->Update();

	//if (GetAsyncKeyState(VK_RETURN))
		//SceneManager::GetInstance()->SetScene(EXITID);

	for (int i = 0; i < MaxID; ++i)
		Objects[EnemyID][i]->Update();
}

void Stage::Render(void)
{
	//Testcase->Render();

	for (int i = 0; i < MaxID; ++i)
		Objects[EnemyID][i]->Render();
}

void Stage::Release(void)
{
	//delete Testcase;
	//Testcase = nullptr;
}
