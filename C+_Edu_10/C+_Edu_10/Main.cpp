#include "Headers.h"

// ** Ű �Է� �Լ� ����.
// ** ���� �����.
char* LogoTex[23];

static char* MenuTex[16] = {
	(char*)"MMMMMMMM               MMMMMMMM",
	(char*)"M:::::::M             M:::::::M",
	(char*)"M::::::::M           M::::::::M",
	(char*)"M:::::::::M         M:::::::::M",
	(char*)"M::::::::::M       M::::::::::M    eeeeeeeeeeee    nnnn  nnnnnnnn    uuuuuu    uuuuuu",
	(char*)"M:::::::::::M     M:::::::::::M  ee::::::::::::ee  n:::nn::::::::nn  u::::u    u::::u",
	(char*)"M:::::::M::::M   M::::M:::::::M e::::::eeeee:::::een::::::::::::::nn u::::u    u::::u",
	(char*)"M::::::M M::::M M::::M M::::::Me::::::e     e:::::enn:::::::::::::::nu::::u    u::::u",
	(char*)"M::::::M  M::::M::::M  M::::::Me:::::::eeeee::::::e  n:::::nnnn:::::nu::::u    u::::u",
	(char*)"M::::::M   M:::::::M   M::::::Me:::::::::::::::::e   n::::n    n::::nu::::u    u::::u",
	(char*)"M::::::M    M:::::M    M::::::Me::::::eeeeeeeeeee    n::::n    n::::nu::::u    u::::u",
	(char*)"M::::::M     MMMMM     M::::::Me:::::::e             n::::n    n::::nu:::::uuuu:::::u",
	(char*)"M::::::M               M::::::Me::::::::e            n::::n    n::::nu:::::::::::::::uu",
	(char*)"M::::::M               M::::::M e::::::::eeeeeeee    n::::n    n::::n u:::::::::::::::u",
	(char*)"M::::::M               M::::::M  ee:::::::::::::e    n::::n    n::::n  uu::::::::uu:::u",
	(char*)"MMMMMMMM               MMMMMMMM    eeeeeeeeeeeeee    nnnnnn    nnnnnn    uuuuuuuu  uuuu" };

// ** �����ȯ�� �ϱ����� ����
// ** ���� ����� �����Ѵ�.
SceneID SceneState = SceneID::LOGO;

// ** � Ű�� �Է� �޾Ҵ��� Ȯ���ϱ� ���� ����.
static DWORD KeyState = 0;



void SetScene(Object* _pPlayer, Object* _pEnemy, Object* _pBullet);
char* ReadAll(char* _FileName);
void ReadLine(char* _FileName, char** _LogoTex);

Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey();

void LogoInitialize();
void LogoProgress();
void LogoRender(char* _str[], int _size, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str[], int _size, int _x, int _y);

void StageInitialize();
void StageProgress(Object* _Player, Object* _Enemy, Object* _pBullet);
void StageRender(Object* _Player, Object* _Enemy, Object* _pBullet);
bool Collision(Object* _Temp, Object* _Dest);

bool Check[128];

int main(void)
{
	//BulletInitialize �Լ���
	Object* Bullet = (Object*)malloc(sizeof(Object) * 128);
	//Bullet = nullptr;
	for (int i = 0; i < 128; ++i)
		Check[i] = false;
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"��");

	// ** Enemy �ʱ�ȭ
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"��");

	LogoInitialize();
	StageInitialize();

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			InputKey();
			SetScene(pPlayer, Enemy, Bullet);
		}
	}




	return 0;
}


void SetScene(Object* _pPlayer, Object* _pEnemy, Object* _pBullet)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
	{
		LogoProgress();
		LogoRender(LogoTex, 23, 22, 5);
	}
	break;

	case SceneID::MENU:
	{
		MenuProgress();
		MenuRender(MenuTex, 16, 17, 8);
	}
	break;

	case SceneID::STAGE:
		StageProgress(_pPlayer, _pEnemy, _pBullet);
		StageRender(_pPlayer, _pEnemy, _pBullet);
		break;

	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

// ** ������ ��ü �ҷ�����.
char* ReadAll(char* _FileName)
{
	/*
	* r = �б� ����
	* r+ = �б�+���� �Բ� ���������� ������ ������ �ȵ�.
	* w = ���� ���� (����⸦ �ϱ⶧���� ����)
	* w+ = �б�+���� �Բ� ���������� ����⸦ �ϱ⶧���� ����

	* [���� ����� �Լ�]
	* fopen : ���� ����, ������ ���� ������ �����Ϳ� ������ �Ұ�.
	* fclose : ���� �ݱ�, ������ �����ִ� ���·� ��� ������.
	* fgetc : ���Ͽ��� ���� �б�
	* fgets : ���Ͽ��� ���ڿ� �б�

	* fputc : ���Ͽ��� ���� ���
	* fputs : ���Ͽ��� ���ڿ� ���

	* fscanf : ���Ͽ� ������ �Է�(����)
	* feof : ������ ������ �ִ��� ������ Ȯ��.
	*/
	FILE* pFile = fopen("Test.txt", "r");

	char Buffer[1024];
	fread(Buffer, 1, 1024, pFile);

	char* str = (char*)malloc(strlen(Buffer) + 1);
	strcpy(str, Buffer);

	return str;
}

// ** ������ ��ü �ҷ�����.
void ReadLine(char* _FileName, char** _Tex)
{
	FILE* pFile = fopen("Test.txt", "rt");

	int size = 0;
	while (!feof(pFile))
	{
		// ** ������ ���پ� �ҷ�����
		char str[1024] = "";
		fgets(str, 1024, pFile);

		_Tex[size] = (char*)malloc(strlen(str));
		strcpy(_Tex[size], str);
		size++;
	}

	fclose(pFile);
}




// ** ������Ʈ ���� �Լ�.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ** Object�� �������� �����Ѵ�.

	//Object* pObj = nullptr;

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
		KeyState |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		KeyState |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		KeyState |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		KeyState |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_RETURN))
		KeyState |= KEYID_ESCAPE;

	if (GetAsyncKeyState(VK_ESCAPE))
		KeyState |= KEYID_ENTER;

	if (GetAsyncKeyState(VK_SPACE))
		KeyState |= KEYID_SPACE;

	if (GetAsyncKeyState(VK_SHIFT))
		KeyState |= KEYID_SHIFT;
}

void LogoInitialize()
{
	//LogoTex = ReadAll((char*)"Test.txt");

	for (int i = 0; i < 23; ++i)
		ReadLine((char*)"Test.txt", LogoTex);
}

void LogoProgress()
{
	if (KeyState & KEYID_ESCAPE)
		SceneState = SceneID::MENU;
}

void LogoRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
}


void MenuProgress()
{
	if (KeyState & KEYID_ENTER)
		SceneState = SceneID::STAGE;
}

void MenuRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
}



void StageInitialize()
{
	for (int i = 0; i < 128; ++i)
	{
		//Bullet[i] = CreateObject(0, 0, (i % 2) == 0 ? (char*)"*" : (char*)".");
		//Check[i] = false;
	}
}

void StageProgress(Object* _Player, Object* _Enemy, Object* _pBullet)
{
	if (KeyState & KEYID_UP)
	{
		if (_Player->Position.y > 0)
			_Player->Position.y--;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEYID_DOWN)
	{
		if (_Player->Position.y < 39)
			_Player->Position.y++;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEYID_LEFT)
	{
		if (_Player->Position.x > 0)
			_Player->Position.x--;

		_Player->Texture = (char*)"��";
	}

	if (KeyState & KEYID_RIGHT)
	{
		if (_Player->Position.x < 118)
			_Player->Position.x++;

		_Player->Texture = (char*)"��";
	}
	
	if (KeyState & KEYID_SPACE)
	{
		for (int i = 0; i < 128; ++i)
		{
			if (!Check[i])
			{
				_pBullet[i] = 
				_pBullet[i].Position.x = 118;
				_pBullet[i].Position.y = rand() % 40;
				break;
			}
		}
	}

	for (int i = 0; i < 128; ++i)
	{

			_pBullet[i].Position.x -= 1;

			if (_Player->Position.x + _Player->Scale.x > )
			{
				//SetCursorPosition(120 >> 1, 1);
				//printf("Bullet �浹 �Դϴ�.");
			}
		}

	if (_pBullet[i]->Position.x <= 1)
	{

	}
			
	}

	if (Collision(_Player, _Enemy))
	{
		SetCursorPosition(120 >> 1, 1);
		printf("�浹 �Դϴ�.");
	}

	if (GetAsyncKeyState('Q'))
		SceneState = SceneID::EXIT;
}

void StageRender(Object* _Player, Object* _Enemy, Object* _pBullet)
{
	SetCursorPosition(_Player->Position.x, _Player->Position.y);
	printf("%s", _Player->Texture);

	for (int i = 0; i < 128; ++i)
	{

		SetCursorPosition(_pBullet[i]->Position.x, _pBullet[i]->Position.y);
		printf("%s", _pBullet[i]->Texture);
	
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