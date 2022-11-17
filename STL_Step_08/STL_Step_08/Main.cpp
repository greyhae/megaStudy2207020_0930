#include "Headers.h"
#include "MainUpdate.h"
#include "DataManager.h"

int main(void)
{
	/*
	Vector3 v1 = Vector3();
	Vector3 v2 = Vector3(1, 2);
	Vector3 v3 = Vector3(10, 20, 30);

	Vector3 v4 = v3 - v2;

	cout << v4.x << ", " << v4.y << ". " << v4.z << endl;
	*/

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	/*
	DataManager::saveData("images\\background.png");
	DataManager::saveData("images\\logo.png");
	DataManager::saveData("images\\menu.png");
	DataManager::saveData("images\\stage.png");
	DataManager::saveData("images\\player.png");
	DataManager::saveData("images\\enemy.png");
	DataManager::saveData("images\\bullet.png");
	*/

	while (true)
	{
		if (Time < GetTickCount64())
		{
			system("cls");

			//DataManager::loadData();

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}