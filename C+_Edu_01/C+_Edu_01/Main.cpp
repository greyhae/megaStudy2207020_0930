// ** �⺻ �����
#include <stdio.h>

// ** system �Լ�
#include <stdlib.h>

// ** input �� ������â�� ������ �� ���� ���̺귯��
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

	// ** ����
	//DWORD Time = GetTickCount();// ��ǻ�Ͱ� ���� �������� 49.7��
	
	// ** Uunsigned long long 64bit int��
	// ** GetTickCount64() = 1/1000 �� => 0.001�� ����
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
		// if Ư�� �̺�Ʈ�� �߻��Ѵٸ�....
		// else �ƴ϶��

		// ��, ��
		if (lTime + 999 < GetTickCount64())
		{
			// ** ����
			lTime = GetTickCount64();

			// ** ȭ���� �����ش�
			system("cls");

			//printf("%d\n", ++Count);

			// ** �ð��� ���
			printf("%02d:%02d:%02d\n", tTime.Hour, tTime.Minute, ++tTime.Second);


			// ** ��ħ�� 60�� �Ǹ� ��ħ�� �ٽ� 0���� ����� ��ħ 1 ����
			if (tTime.Second >= 61)
			{
				tTime.Second = 0;
				++tTime.Minute;
			}

			// ** ��ħ�� 60�� �Ǹ� ��ħ�� �ٽ� 0���� ����� �ð� 1 ����
			if (tTime.Minute >= 61)
			{
				tTime.Minute = 0;
				++tTime.Hour;
			}

			// ** ��ħ�� 24�ð� �Ǹ� �ð��� 0���� ����
			if (tTime.Minute >= 24)
			{
				tTime.Hour;
			}
		}
	}



	return 0;
}