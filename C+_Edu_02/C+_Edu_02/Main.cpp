// ** �⺻ �����
#include <stdio.h>
// ** system �Լ�
#include <stdlib.h>
// ** input �� ������â�� ������ �� ���� ���̺귯��
#include <Windows.h>

struct Vector2
{
	int x, y;
};

bool Horzontal, Vertical;

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);



int main(void)
{
	ShowCursor(false);
	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� ��ǥ
	Vector2 PlayPostion;
	PlayPostion.x = 0;
	PlayPostion.y = 0;

	char* Texture = (char*)"��";

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** ȭ�� Ŭ����
			system("cls");

			// 
			bool Horzontal = false;
			bool Vertical = false;

			InputKey(&PlayPostion, Texture);

			SetCursorPosition(PlayPostion.x, PlayPostion.y);
			printf("%s", Texture);
		}
	}

	return 0;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����
	COORD pos = { (short)_x, (short)_y };

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

void InputKey(Vector2* _Position, char* _Texture)
{
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

	/*
	if (GetAsyncKeyState(VK_UP) & 0x01)
		printf("UP\n");

	if (GetAsyncKeyState(VK_DOWN) & 0x01)
		printf("DOWN\n");

	if (GetAsyncKeyState(VK_LEFT) & 0x01)
		printf("LEFT\n");

	if (GetAsyncKeyState(VK_RIGHT) & 0x01)
		printf("RIGHT\n");
	*/

		if (GetAsyncKeyState(VK_UP) && !Horzontal)
		{
			// ** y ��ǥ�� 0���� Ŭ ���� �Է��� ������.
			if (_Position->y > 0)
				_Position->y--;
			/*
			if (y <= 0)
				y = 0;
			*/

			_Texture = (char*)"��";
			Vertical = true;
		}
		else
			Vertical = false;

		if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
		{
			// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
			if (_Position->y > 39)
				_Position->y++;
			_Texture = (char*)"��";
			Vertical = true;
		}
		else
			Vertical = false;

		if (GetAsyncKeyState(VK_LEFT) && !Vertical)
		{
			if (_Position->x > 0)
				_Position->x--;
			_Texture = (char*)"��";
			Horzontal = true;
		}
		else
			Horzontal = false;

		if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
		{
			// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
			if (_Position->x > 118)
				_Position->x++;
			_Texture = (char*)"��";
			Horzontal = true;
		}
		else
			Horzontal = false;
}