#include "Headers.h"

// ** 함수 정리

// ** 장면전환을 하기 위한 변수
// 현재 장면을 보관한다.
SceneID SceneState = SceneID::LOGO;
DWORD KeySate = 0;

// 함수선언 순서와 아래 쪽에 있는 함수정의 순서가 같아야 한다.
void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);
//void Render(char* _str, int _x, int _y);

int main(void)
{
	// ** 커서를 안 보이게 설정
	ShowCursor(false);

	// ** 시간 세팅
	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 초기화
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"△");

	// ** Enemy 초기화
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"■");

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			// ** 화면 클리어
			system("cls");

			SetScene(pPlayer, Enemy);
		}
	}

	return 0;
}

void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
		LogoPress();
		Render((char*)"LOGO", 58, 20);
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

		// ** 충돌
		if (_pPlayer->Position.x + 2 > _pEnemy->Position.x &&
			_pEnemy->Position.x + 2 > _pPlayer->Position.x &&
			_pPlayer->Position.y == _pEnemy->Position.y)
		{
			SetCursorPosition(120 >> 1, 1);
			printf("충돌입니다.");
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

//** 오브젝트 생성 함수
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ** Object 를 동적으로 생성한다. 
	// (런타임 이전에 만들어지는 데이터는 정적, 이후에 만들어지는 데이터는 동적)
	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** 좌표를 셋팅
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** 동적할당을 해준다. 동적할당은 할 때 문자열의 크기 + 1 만큼의 크기로 해준다.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);

	// ** 문자열을 복사한다.
	strcpy(pObj->Texture, _Texture);

	// ** 문자열의 길이로 크기를 정한다.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** 모든 셋팅이 완료되었다면
	// ** 동적으로 생성된 Object 의 주소를 반환한다.
	return pObj;
}

// ** 커서의 위치를 이동시킨다.
void SetCursorPosition(int _x, int _y)
{
	// ** 좌표를 설정
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** 설정한 좌료포 이동시키는 함수
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = 현재 콘솔의 핸들
	// ** HANDLE : 윈도우 창의 기본 설정값을 셋팅할 수 있음
}


// ** 커서를 보이게/안보이게 하는 함수
// ** true 보이게, false 안보이게
void ShowCursor(bool _b)
{
	// ** 커서의 기본정보를 생성한다.
	CONSOLE_CURSOR_INFO Info;

	// ** 커서의 기본정보를 셋팅한다.
	// ** 커서를 보인게/안보이게 한다.
	Info.bVisible = _b;

	// ** 커서의 크기를 설정한다.
	Info.dwSize = 1;

	// ** 커서의 설정을 적용시키는 함수
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void InputKey(Object* _Object)
{
	bool Horzontal = false;
	bool Vertical = false;

	if (GetAsyncKeyState(VK_UP))
	{
		// ** y 좌표가 0보다 클 때만 입력을 받은다.
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"△";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN))
	{
		// ** y 좌표가 39보다 작을 때만 입력을 받은다.
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"▽";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"◁";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		// ** y 좌표가 39보다 작을 때만 입력을 받은다.
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"▷";
		Horzontal = true;
	}
	else
		Horzontal = false;
}



void LogoPress(char* _str, int _x, int _y)
{
	if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
	{
		SceneState = SceneID::MENU;
	}
}

void LogoRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}
void MenuRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}
void StageProgress(Object* _Player, Object*  _Enemy)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);

	if(Collision())
}
void StageRender(Object* _Player, Object* _Enemy)
{
	SetCursorPosition(_Player->Position.x, _Player->Position.y);
	printf("%s", _Player->Texture);
}

bool Collision(Object* _Temp, Object* _Dest)
{
	if (_Temp->Position.x + 2 > _Dest->Position.x &&
		_Dest->Position.x + 2 > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
		return true;
	return false;

}