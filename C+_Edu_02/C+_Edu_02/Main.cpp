// ** �⺻ �����
#include <stdio.h>

// ** system �Լ�
#include <stdlib.h>

// ** input �� ������â�� ������ �� ���� ���̺귯��
#include <Windows.h>

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);

int main(void)
{
	ShowCursor(false);
	ULONGLONG Time = GetTickCount64();

	int x = 0, y = 0;
	char* Tex = (char*)"��";



	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** Ű �Է�
			// GetAsyncKeyState() = Ű�Է� �Լ�
			// ��Ȳ�� ���� ������ ��ȯ��
			// 0x0000,  0x0001,  0x8000,  0x8001

			// ** ���� 0�� 1�� ����
			// ** 0 : ������ ������ ����
			// ** 1 : ������ ������ ����

			// ** ���� 8�� 0�� ����
			// 0 : ���� ���� ����
			// 8 : ���� ����

			// ** �Ű� ������ Virtual Key�� �Է� �޴´�.

			//printf("%x\n", GetAsyncKeyState(VK_UP));
			//if(GetAsyncKeyState(VK_UP) & 0x01)\
				printf("zzz\n");

			/**
			if (GetAsyncKeyState(VK_UP) & 0x01)
				printf("UP\n");

			if (GetAsyncKeyState(VK_DOWN) & 0x01)
				printf("DOWN\n");

			if (GetAsyncKeyState(VK_LEFT) & 0x01)
				printf("LEFT\n");

			if (GetAsyncKeyState(VK_RIGHT) & 0x01)
				printf("RIGHT\n");
			*/

			if (GetAsyncKeyState(VK_UP))
			{
				y--;
				Tex = (char*)"��";
				
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				y++;
				Tex = (char*)"��";
			}
				

			if (GetAsyncKeyState(VK_LEFT))
			{
				x--;
				Tex = (char*)"��";
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				x++;
				Tex = (char*)"��";
			}

			SetCursorPosition(x, y);
			printf("%s", Tex);
		}
	}

	return 0;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����
	COORD pos = { _x, _y };

	// ** ������ �·��� �̵���Ű�� �Լ�
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ��� �ڵ�
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����
}

// ** Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�
// ** true ���̰�, false �Ⱥ��̰�
void ShowCursor(bool _b)
{
	// ** Ŀ���� �⺻������ �����Ѵ�.
	CONSOLE_CURSOR_INFO Info;

	// ** Ŀ���� �⺻������ �����Ѵ�.
	// ** Ŀ���� ���ΰ�/�Ⱥ��̰� �Ѵ�.
	Info.bVisible = _b;

	// ** Ŀ���� ũ�⸦ �����Ѵ�.
	Info.dwSize = 1;

	// ** Ŀ���� ������ �����Ű�� �Լ�
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}