#include <stdio.h>
#include <Windows.h>

// ** const

// ** 상수화
//const int NUMBER = 10;

// ** 충돌처리
// ** 생성자 & 복사생성자

// ** 장면 관리 (scene 전환)
// ** 생성 함수
// ** 함수 정리

struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0)
	{
		//printf("생성자\n");
		//system("pause");
	}

	Vector2(int _x, int _y) : x(_x), y(_y)
	{
		printf("복사 생성자\n");
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
	// ** 커서를 안 보이게 설정
	ShowCursor(false);

	// ** 시간 세팅
	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 초기화
	Object Player;
	Player.Position = Vector2(int(120 * 0.3333f), 40 >> 1);
	Player.Texture = (char*)"△";
	Player.Scale = Vector2((int)strlen(Player.Texture), 1);
	//Player.Position.x = int(120 * 0.3333f);
	//Player.Position.y = 40>>1;
	
	// Texture 길이를 미리 확인할 수 없다.
	// ** Texture 를 먼저 초기화 하고 이후에 사이즈를 아래와 같이 초기화 한다.
	//Player.Scale.x = (int)strlen(Player.Texture);
	//Player.Scale.y = 1;

	// ** Enemy 초기화
	Object Enemy;

	Enemy.Position = Vector2(int(120 * 0.3333f * 2), 40 >> 1);
	Enemy.Texture = (char*)"■";
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

			// ** 화면 클리어
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

			// ** 충돌
			if (Player.Position.x + 2 > Enemy.Position.x &&
				Enemy.Position.x + 2 > Player.Position.x &&
				Player.Position.y == Enemy.Position.y)
			{
				SetCursorPosition(120 >> 1, 1);
				printf("충돌입니다.");
			}
		}
	}

	return 0;
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
	// ** 키 입력
	// GetAsyncKeyState() = 키입력 함수
	// 상황에 따라서 다음을 반환함
	// 0x0000,  0x0001,  0x8000,  0x8001

	// ** 뒤쪽 0과 1의 차이
	// ** 0 : 이전에 눌릭적 있음
	// ** 1 : 이전에 눌린적 없음

	// ** 앞쪽 8과 0의 차이
	// 0 : 현재 눌리 않음
	// 8 : 현재 눌림

	// ** 매개 변수로 Virtual Key를 입력 받는다.

	//printf("%x\n", GetAsyncKeyState(VK_UP));
	//if(GetAsyncKeyState(VK_UP) & 0x01)\
					printf("zzz\n");

	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		// ** y 좌표가 0보다 클 때만 입력을 받은다.
		if (_Object->Position.y > 0)
			_Object->Position.y--;
		/*
		if (y <= 0)
			y = 0;
		*/

		_Object->Texture = (char*)"△";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
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