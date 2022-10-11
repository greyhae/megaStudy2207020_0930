#include "MainUpdate.h"

#include "SingletonManager.h"
#include "Player.h"
#include "Enemy.h"

MainUpdate::MainUpadate()
{

}

MainUpdate::~MainUpadate()
{

}

void MainUpdate::Initialize()
{

}
void MainUpdate::Progress()
{
	for (Object* Element : ObjectList)
		Element->Progress();
}
void MainUpdate::Render()
{
	for (Object* Element : ObjectList)
		Element->Render();
}
void MainUpdate::Initialize()
{
	for (Object* Element : ObjectList)
	{
		deleate Element;
		Element = nullptr;
	}
		
}
