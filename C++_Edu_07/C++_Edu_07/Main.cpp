
#include "MainUpdate.h"

// ** °´Ã¼ °ü¸® 

int main(void)
{
	MainUpdate Main;

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();

			Main.Progress();
			Main.Release();

			if (GetAsyncKeyState("Q")
			{

			}
		}
	}

	return 0;
}