// ** 기본 입출력
#include <stdio.h>
// ** system 함수
#include <stdlib.h>
// ** input 및 윈도우창을 제어할 때 사용되 라이브러리
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

	// ** 플레이어 좌표
	Vector2 PlayPostion;
	PlayPostion.x = 0;
	PlayPostion.y = 0;

	char* Texture = (char*)"△";

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** 화면 클리어
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

// ** 커서의 위치를 이동시킨다.
void SetCursorPosition(int _x, int _y)
{
	// ** 좌표를 설정
	COORD pos = { (short)_x, (short)_y };

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

void InputKey(Vector2* _Position, char* _Texture)
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
			// ** y 좌표가 0보다 클 때만 입력을 받은다.
			if (_Position->y > 0)
				_Position->y--;
			/*
			if (y <= 0)
				y = 0;
			*/

			_Texture = (char*)"△";
			Vertical = true;
		}
		else
			Vertical = false;

		if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
		{
			// ** y 좌표가 39보다 작을 때만 입력을 받은다.
			if (_Position->y > 39)
				_Position->y++;
			_Texture = (char*)"▽";
			Vertical = true;
		}
		else
			Vertical = false;

		if (GetAsyncKeyState(VK_LEFT) && !Vertical)
		{
			if (_Position->x > 0)
				_Position->x--;
			_Texture = (char*)"◁";
			Horzontal = true;
		}
		else
			Horzontal = false;

		if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
		{
			// ** y 좌표가 39보다 작을 때만 입력을 받은다.
			if (_Position->x > 118)
				_Position->x++;
			_Texture = (char*)"▷";
			Horzontal = true;
		}
		else
			Horzontal = false;
}