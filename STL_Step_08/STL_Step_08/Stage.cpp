#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "Prototype.h"


Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Start()
{
	//Prototype::GetInstance()->Initialize();
	Object* Prototype = Prototype:GetInstance()->FindObject("Player");

	/*
	try
	{

		if (ProtoObject == nullptr)
			throw __LINE__;

			pPlayer = nProtoObject->Clone();
			pPlayer->Start();
	}
	catch (string s)
	{

	}
	// catch (...) : switch의 default와 같은 형식
	catch (...)
	{
		cout << "Error : where (" << __FILE__ << ") line (" << __LINE__ << ")" << endl;
		system("pause");

		pPlayer = (new Player)->Initialize("nullptr_key");
		pPlayer->Start();
	}
	*/
}

void Stage::Update()
{
	pPlayer->Render();
	/*
	cout << "Stage" << endl;
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
	*/
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{

}