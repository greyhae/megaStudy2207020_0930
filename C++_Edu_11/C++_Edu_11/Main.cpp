#include "Headers.h"
#include "Child.h"
#include "MainUpdate.h"

// 2022.10.20 - SingleTone Ãß°¡
/*
int Sum(const int& num1, const int& num2) 
{
	cout << &num1 << endl << &num2 << endl;
	return num1 + num2;
}
*/

/*
void SetColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}
*/

int main(void)
{
	/*
	SetColor(4);
	cout << "Hello ";

	SetColor(6);
	cout << "Wordl!!" << endl;

	SetColor(15);
	*/

	/*
	int num1 = 0, num2 = 0;
	cout << &num1 << endl << &num2 << endl;

	cout << Sum(num1, num2) << endl;
	*/

	//Child c;
	//c.Render();

	/*
	Object* pc = new Child();
	//Child* pc = new Child();

	delete pc;
	pc = nullptr;

	Transform Objects[MAX];

	Objects[Player].Position;
	Objects[Enemy].Rotation;
	Objects[Bullet].Scale;
	*/

	//ObjectID::MAX;

	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}