#include <stdio.h>
#include <Windows.h>

// ** const

// ** ���ȭ
//const int NUMBER = 10;

// ** �浹ó��
// ** ������ & ���������

// ** ��� ���� (scene ��ȯ)
// ** ���� �Լ�
// ** �Լ� ����

struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0)
	{
		//printf("������\n");
		//system("pause");
	}

	Vector2(int _x, int _y) : x(_x), y(_y)
	{
		printf("���� ������\n");
		system("pause");
	}
};

struct Object
{
	Vector2 Position;
	Vector2 Scale;
	char* Texture;
};

bool Horzontal = false;
bool Vertical = false;

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);


int main(void)
{
	// ** Ŀ���� �� ���̰� ����
	ShowCursor(false);

	// ** �ð� ����
	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object Player;
	Player.Position = Vector2(int(120 * 0.3333f), 40 >> 1);
	Player.Texture = (char*)"��";
	Player.Scale = Vector2((int)strlen(Player.Texture), 1);
	//Player.Position.x = int(120 * 0.3333f);
	//Player.Position.y = 40>>1;
	
	// Texture ���̸� �̸� Ȯ���� �� ����.
	// ** Texture �� ���� �ʱ�ȭ �ϰ� ���Ŀ� ����� �Ʒ��� ���� �ʱ�ȭ �Ѵ�.
	//Player.Scale.x = (int)strlen(Player.Texture);
	//Player.Scale.y = 1;

	// ** Enemy �ʱ�ȭ
	Object Enemy;

	Enemy.Position = Vector2(int(120 * 0.3333f * 2), 40 >> 1);
	Enemy.Texture = (char*)"��";
	Enemy.Position = Vector2((int)strlen(Enemy.Texture), 1);
	Enemy.Scale = Vector2((int)strlen(Enemy.Texture), 1);
	//Enemy.Position.x = int(120 * 0.3333f * 2);
	//Enemy.Position.y = 40>>1;

	//emy.Scale.x = (int)strlen(Enemy.Texture);
	//emy.Scale.y = 1;


	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** ȭ�� Ŭ����
			system("cls");

			// ** Progress
			InputKey(&Player);

			// ** Render



			// ** Player
			SetCursorPosition(
				Player.Position.x,
				Player.Position.y);

			printf("%s", Player.Texture);

			// ** Enemy
			SetCursorPosition(
				Enemy.Position.x,
				Enemy.Position.y);

			printf("%s", Enemy.Texture);

			// ** �浹
			if (Player.Position.x + 2 > Enemy.Position.x &&
				Enemy.Position.x + 2 > Player.Position.x &&
				Player.Position.y == Enemy.Position.y)
			{
				SetCursorPosition(120 >> 1, 1);
				printf("�浹�Դϴ�.");
			}
		}
	}

	return 0;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����
	COORD pos = { (SHORT)_x, (SHORT)_y };

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

void InputKey(Object* _Object)
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

	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		// ** y ��ǥ�� 0���� Ŭ ���� �Է��� ������.
		if (_Object->Position.y > 0)
			_Object->Position.y--;
		/*
		if (y <= 0)
			y = 0;
		*/

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;
}