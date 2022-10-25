#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
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

}