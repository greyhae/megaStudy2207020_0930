#include "MainUpdate.h"

class Test
{
public:
	static int Number;
};

int Test::Number;

// ** 객체 관리 클래스
int main(void)
{
	/*
	// ** static
	Test t1;
	t1.Number = 10;

	Test t2;
	t2.Number = 20;

	Test t3;
	t3.Number = 1000;

	cout << t1.Number << endl;
	cout << Test::Number << endl;
	*/


	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();

			Main.Progress();
			Main.Release();

			if (GetAsyncKeyState('Q'))
			{
				break;
			}
		}
	}

	return 0;
}