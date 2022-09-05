#include "Headers.h"

// ** Ű �Է� �Լ� ����.
// ** ���� �����

// ** �ָ� �ǽ�
// ** �Ʒ� LogoTex ���� ���Ϸ� �ҷ�����

static char* MnuTex[9] = {
	(char*)"__       __  ________  __    __  __    __",
	(char*)"/ M     /  |/        |/  M  /  |/  |  /  |",
	(char*)"$$  M / $$ | $$$$$$$$ / $$  M $$ | $$ | $$ |",
	(char*)"$$$  M / $$$ | $$ | __    $$$  M$$ | $$ | $$ |",
	(char*)"$$$$ / $$$$ | $$ | $$$$  $$ | $$ | $$ |",
	(char*)"$$ $$ $$ / $$ | $$$$$ / $$ $$ $$ | $$ | $$ |",
	(char*)"$$ | $$$ / $$ | $$ | _____ $$ | $$$$ | $$ M__$$ |",
	(char*)"$$ | $ / $$ | $$ | $$ | $$$ | $$    $$ /",
	(char*)"$$ / $$ / $$$$$$$$ / $$ / $$ / $$$$$$ /"
};

// ** �����ȯ�� �ϱ����� ����
// ** ���� ����� �����Ѵ�.
SceneID SceneState = SceneID::LOGO;

// ** � Ű�� �Է¹޾Ҵ��� Ȯ���ϱ� ���� ����
static DWORD KeyState = 0;


void SetScene(Object* _pPlayer, Object* _pEnemy);
void ReadAll(char* _FileName);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey();

void LgoInitialize();
void LogoProgress();
void LogoRender(char* _str, int _size, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str[], int _size, int _x, int _y);

void StageInitialize();
void StageProgress(Object* _Player, Object* _Enemy);
void StageRender(Object* _Player, Object* _Enemy);
bool Collision(Object* _Temp, Object* _Dest);



int main(void)
{
	FILE* pFile = fopen("Test.txt", "r");
	//printf("%s", ReadAll((char*)"Test.txt"));
	
	char* LogoTex[9] = { (char*)"" };
	int size = 0;

	while (!feof(pFile))
	{
		// ** ������ ���پ� �ҷ�����
		char str[1024] = "";
		fgets(str, 1024, pFile);

		LogoTex[size] = (char*)malloc(strlen(str));
		strcpy(LogoTex[size++], str);
	}

	for (int i = 0; i < 9; ++i)
		printf("%s", LogoTex[i]);

	fclose(pFile);


	/*
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"��");

	// ** Enemy �ʱ�ȭ
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"��");

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			InputKey();
			SetScene(pPlayer, Enemy);
		}
	}
	*/

	return 0;
}


void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
	{
		LogoProgress();
		//LogoRender(LogoTex, 9, 38, 10);
	}
	break;

	case SceneID::MENU:
	{
		MenuProgress();
		MenuRender(MenuTex, 9, 38, 10);
	}
	break;

	case SceneID::STAGE:
		StageProgress(_pPlayer, _pEnemy);
		StageRender(_pPlayer, _pEnemy);
		break;

	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

// ** ������ ���� �ҷ�����
void ReadAll(char* _FileName)
{
	/*
	* r  = �б� ����
	* r+ = �б� + ���� �Բ� ���������� ������ ������ �ȵ�.
	* w  = ���� ���� (����⸦ �ϱ� ������ ����)
	* w+ = �б� + ���� �Բ� ���������� ����⸦ �ϱ⶧���� ����
	
	* [���� ����� �Լ�]
	* fopen : ���� ����, ������ ���� ������ �����Ϳ� ������ �Ұ�
	* fclose : ���� �ݱ�, ������ �����ִ� ���·� ��� ������
	* fgetc : ���Ͽ��� ���� �б�
	* fgetc : ���Ͽ��� ���ڿ� �б�
	
	* fputc : ���Ͽ��� ���� ���
	* fputs : ���Ͽ��� ���ڿ� ���
	
	* fscanf : ���Ͽ��� ������ �Է�(����);
	* feof : ������ ������ �ִ��� ������ Ȯ��
	*/
	
	FILE* pFile = fopen("Test.txt", "r");

	char Buffer[1024];
	fread(Buffer, 1, 1024, pFile);

	char* str = (char*)malloc(strlen(Buffer) + 1);
	strcpy(str, Buffer);
	
	//return str;
}

// ** ������Ʈ ���� �Լ�.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ** Object�� �������� �����Ѵ�.
	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** ��ǥ�� ����
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** �����Ҵ��� ���ش�. �����Ҵ��� �Ҷ� ���ڿ��� ũ�� + 1 ��ŭ�� ũ��� ���ش�.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);

	// ** ���ڿ��� �����Ѵ�.
	strcpy(pObj->Texture, _Texture);

	// ** ���ڿ��� ���̷� ũ�⸦ ���Ѵ�.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** ��� ������ �Ϸ�Ǿ��ٸ� 
	// ** �������� ������ Object �� �ּҸ� ��ȯ�Ѵ�.
	return pObj;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** ������ ��ǥ�� �̵���Ű�� �Լ�.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ�â�� �ڵ�.
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����.
}

// ** Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�.
// ** true ���̰�, false �Ⱥ��̰�.
void ShowCursor(bool _b)
{
	// ** Ŀ���� �⺻������ �����Ѵ�.
	CONSOLE_CURSOR_INFO Info;

	// ** Ŀ���� �⺻������ �����Ѵ�.
	// ** Ŀ���� ���̰�/�Ⱥ��̰� �Ѵ�.
	Info.bVisible = _b;

	// ** Ŀ���� ũ�⸦ �����Ѵ�.
	Info.dwSize = 1;

	// ** Ŀ���� ������ �����Ű�� �Լ�.
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// ** �÷��̾��� Ű �Է��� �ް�, �Է¿� ���� Texture �� ���� �Ѵ�.
void InputKey()
{
	KeyState = 0;

	if (GetAsyncKeyState(VK_UP))
		KeyState |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN))
		KeyState |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		KeyState |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		KeyState |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_RETURN))
		KeyState |= KEY_ESCAPE;

	if (GetAsyncKeyState(VK_ESCAPE))
		KeyState |= KEY_ENTER;

	if (GetAsyncKeyState(VK_SPACE))
		KeyState |= KEY_SPACE;

	if (GetAsyncKeyState(VK_SHIFT))
		KeyState |= KEY_SHIFT;
}

void LgoInitialize()
{
	//LogoTex = ReadAll((char*)"Test.txt");
}

void LogoProgress()
{
	if (KeyState & KEY_ESCAPE)
		SceneState = SceneID::MENU;
}

void LogoRender(char* _str, int _size, int _x, int _y)
{
	for (int i = 0; i < _size; i++)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str);
	}
}


void MenuProgress()
{
	if (KeyState & KEY_ENTER)
		SceneState = SceneID::STAGE;
}

void MenuRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; i++)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
}

Object* Bullet[128];
bool Check[128];

void StageInitialize()
{
	for (int i = 0; i < 128; ++i)
	{
		Bullet[i] = CreateObject(0, 0, (i % 2) == 0 ? (char*)"*" : (char*)".");
		Check[i] = false;
	}
}

void StageProgress(Object* _Player, Object* _Enemy)
{
	if (KeyState & KEY_UP)
	{
		if (_Player->Position.y > 0)
			_Player->Position.y--;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEY_DOWN)
	{
		if (_Player->Position.y < 39)
			_Player->Position.y++;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEY_LEFT)
	{
		if (_Player->Position.x > 0)
			_Player->Position.x--;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEY_RIGHT)
	{
		if (_Player->Position.x < 118)
			_Player->Position.x++;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEY_SPACE)
	{
		for (int i = 0; i < 128; ++i)
		{
			if (!Check[i])
			{
				Bullet[i]->Position.x = 118;
				Bullet[i]->Position.y = rand() % 40;
				Check[i] = true;
				break;
			}
		}
	}


	for (int i = 0; i < 128; ++i)
	{
		if (Check[i])
		{
			Bullet[i]->Position.x -= 1;

			if (Collision(_Player, Bullet[i]))
			{
				SetCursorPosition(120 >> 1, 1);
				printf("Bullet �浹 �Դϴ�.");
			}
		}

		if (Bullet[i]->Position.x <= 1)
			Check[i] = false;
	}

	if (Collision(_Player, _Enemy))
	{
		SetCursorPosition(120 >> 1, 1);
		printf("�浹 �Դϴ�.");
	}

	if (GetAsyncKeyState('Q'))
		SceneState = SceneID::EXIT;
}

void StageRender(Object* _Player, Object* _Enemy)
{
	SetCursorPosition(_Player->Position.x, _Player->Position.y);
	printf("%s", _Player->Texture);

	for (int i = 0; i < 128; ++i)
	{
		if (Check[i])
		{
			SetCursorPosition(Bullet[i]->Position.x, Bullet[i]->Position.y);
			printf("%s", Bullet[i]->Texture);
		}
	}

	SetCursorPosition(_Enemy->Position.x, _Enemy->Position.y);
	printf("%s", _Enemy->Texture);
}

// ** �浹ó�� �Լ�
bool Collision(Object* _Temp, Object* _Dest)
{
	if (_Temp->Position.x + _Temp->Scale.x > _Dest->Position.x &&
		_Dest->Position.x + _Dest->Scale.x > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
		return true;
	return false;
}