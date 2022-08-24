// ** 기본 입출력
#include <stdio.h>

// ** system 함수
#include <stdlib.h>

// ** input 및 윈도우창을 제어할 때 사용되 라이브러리
#include <Windows.h>

struct Student 
{
	char* Name;
	int Kor;
	int Eng;
	int Math;
};
typedef struct Object
{
	Student Std;
	int Age;
	int Number;
	int IClass;
}HOBJ;

struct Time
{
	int Hour;
	int Minute;
	int Second;
};

int main(void)
{

	// ** 루프
	//DWORD Time = GetTickCount();// 컴퓨터가 켜진 순간부터 49.7일
	
	// ** Uunsigned long long 64bit int형
	// ** GetTickCount64() = 1/1000 초 => 0.001초 단위
	ULONGLONG lTime = GetTickCount64();

	/*
	printf("%d\n", GetTickCount64());
	Sleep(50);
	printf("%d\n", GetTickCount64());
	Sleep(50);
	printf("%d\n", GetTickCount64());
	*/

	int Count = 0;
	
	Time tTime;

	tTime.Hour = 23;
	tTime.Minute = 59;
	tTime.Second = 0;


	while (true)
	{
		// if 특정 이벤트가 발생한다면....
		// else 아니라면

		// 분, 초
		if (lTime + 999 < GetTickCount64())
		{
			// ** 루프
			lTime = GetTickCount64();

			// ** 화면을 지워준다
			system("cls");

			//printf("%d\n", ++Count);

			// ** 시간을 출력
			printf("%02d:%02d:%02d\n", tTime.Hour, tTime.Minute, ++tTime.Second);


			// ** 초침이 60이 되면 초침은 다시 0으로 만들고 분침 1 증가
			if (tTime.Second >= 61)
			{
				tTime.Second = 0;
				++tTime.Minute;
			}

			// ** 분침이 60이 되면 분침은 다시 0으로 만들고 시간 1 증가
			if (tTime.Minute >= 61)
			{
				tTime.Minute = 0;
				++tTime.Hour;
			}

			// ** 시침이 24시가 되면 시간을 0으로 셋팅
			if (tTime.Minute >= 24)
			{
				tTime.Hour;
			}
		}
	}



	return 0;
}