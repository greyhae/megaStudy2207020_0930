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
	Player.Position.x = 0;
	Player.Position.y = 0;

	Player.Scale.x = 2;
	Player.Scale.y = 1;

	Player.Texture = (char*)"△";

	// ** 여분의 총알을 준비해둔다
	Object Bullet[128];// 2의 보수

	// ** 총알이 발사 되었는지 확인하는 용도
	bool ShowBullet[128];

	// ** 총알의 생성간의 간격을 주기 위함
	ULONGLONG BulletDelay = GetTickCount64();

	for (int i = 0; i < 128; i++)
	{
		// ** srand = 랜덤하숨 초기화
		srand(
			// ** 현재 시간을 제곱하여 알수없는 값으로 초기화
			GetTickCount64() * GetTickCount64());

		// ** rand() = 랜덤 함수
		// ** rdad() % 40 = 0 ~ 39 사이의 랜덤값
		Bullet[i].Position.x = 118;
		Bullet[i].Position.y = rand() % 40;
		Bullet[i].Texture = (char*)"*";

		ShowBullet[i] = false;
	}

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** 화면 클리어
			system("cls");

			InputKey(&Player);

			SetCursorPosition(
				Player.Position.x,
				Player.Position.y);

			printf("%s", Player.Texture);

			/*
			* 총알 생성
			* 2.5초 간격으로 총알을 생성하고, 생성하는 과정에서 현재 비활성화 되어있는 총알을 찾아 좌료를 수정하고,
			* 활성화 상태로 변경한다. 총알을 1발만 생성할 것이므로 활성화로 변경이 완료되면 즉시 반복문을 탈출한다.
			*/
			for (int i = 0; i < 128; i++)
			{
				// ** 총알이 2.5초 다윈로 생성됨
				if (BulletDelay + 2500 < GetTickCount64())
				{
					// if(ShowBullet[i] == false)
					// ** 총알이 비활성화 상태라면
					if (!ShowBullet[i])
					{
						// ** 재생성 되었다면 좌표를 다시 초기화 해준다.
						Bullet[i].Position.x = 118;
						Bullet[i].Position.y = rand() % 40;

						// ** 현재 상태를 활성화 상태로 변경한다.
						ShowBullet[i] = true;

						// ** 시간값을 재 초기화 한다.
						BulletDelay = GetTickCount64();

						// ** 총알을 1개만 활성화 할 것이기 때문에
						// ** 반복문을 빠져나간다.
						break;
					}
				}
			}

			for (int i = 0; i < 128; i++)
			{

				// if(ShowBullet[i] == true)
				// ** 총알이 활성화 상태라면
				if (ShowBullet[i])
				{
					// ** 총알의 이동
					// ** 이동방향 : ←←←
					Bullet[i].Position.x--;

					// ** 충돌판정 : 총알 좌표가 0이 되면 총알 좌표 초기화 해준다.
					if (Bullet[i].Position.x <= 0)
					{
						ShowBullet[i] = false;
						continue;
					}

					// ** 크기밧을 함께 설정해서 범위 충돌 만들어야 함 : 집에서 Scale를 이용해서 해 볼것
					if (Bullet[i].Position.x == Player.Position.x &&
						Bullet[i].Position.y == Player.Position.y)
					{
						ShowBullet[i] = false;
						continue;
					}

					// ** 총알이 제 위치에 그려질 수 있도록 커서를 이동시킨다.
					SetCursorPosition(
						Bullet[i].Position.x,
						Bullet[i].Position.y);

					// ** 총알을 그린다.
					printf("%s", Bullet[i].Texture);
				}
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