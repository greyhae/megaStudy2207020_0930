#include "Headers.h"

int main(void)
{

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();
		}
	}

	return;
}