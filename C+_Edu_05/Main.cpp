#include "Headers.h"

#define _CRT_SECURE_NO_WARNINGS

// ** ��� ���� (scene ��ȯ)
// ** ���� �Լ�
// ** �Լ� ����

bool Horzontal = false;
bool Vertical = false;
SceneID SceneState = SceneID::LOGO;

// �Լ����� ������ �Ʒ� �ʿ� �ִ� �Լ����� ������ ���ƾ� �Ѵ�.
void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(Vector2 _Position, char* _Texture);
void Render(char* _str, int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);

int main(void)
{
	// ** Ŀ���� �� ���̰� ����
	ShowCursor(false);

	// ** �ð� ����
	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object* pPlayer = CreateObject(
		Vector2(int(120 * 0.3333f), 40 >> 1), (char*)"��");

	// ** Enemy �ʱ�ȭ
	Object Enemy;
	Enemy.Position = Vector2(int(120 * 0.3333f * 2), 40 >> 1);
	Enemy.Texture = (char*)"��";
	Enemy.Scale = Vector2((int)strlen(Enemy.Texture), 1);

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** ȭ�� Ŭ����
			system("cls");

			SetScene(pPlayer, &Enemy);
		}
	}

	return 0;
}

void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
		Render((char*)"LOGO", 58, 20);
		if(GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
		{
			SceneState = SceneID::MENU;
		}
		break;
	case SceneID::MENU:
		Render((char*)"MENU", 58, 20);
		if (GetAsyncKeyState('S'))
		{
			SceneState = SceneID::STAGE;
		}
		break;
	case SceneID::STAGE:
		// ** Progress
		InputKey(_pPlayer);

		// ** Render

		// ** Player
		Render(_pPlayer->Texture,
			_pPlayer->Position.x,
			_pPlayer->Position.y);

		// ** Enemy
		Render(_pEnemy->Texture,
			_pEnemy->Position.x,
			_pEnemy->Position.y);

		// ** �浹
		if (_pPlayer->Position.x + 2 > _pEnemy->Position.x &&
			_pEnemy->Position.x + 2 > _pPlayer->Position.x &&
			_pPlayer->Position.y == _pEnemy->Position.y)
		{
			SetCursorPosition(120 >> 1, 1);
			printf("�浹�Դϴ�.");
		}

		if (GetAsyncKeyState('Q'))
		{
			SceneState = SceneID::EXIT;
		}
		break;
	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

Object* CreateObject(Vector2 _Position, char* _Texture)
{
	Object* pObj = (Object*)malloc(sizeof(Object));

	pObj->Position = Vector2(_Position.x, _Position.y);

	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);
	strcpy(pObj->Texture, _Texture);

	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	return pObj;
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

void Render(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
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