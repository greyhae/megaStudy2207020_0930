/*
* Chapter 05 : 조건문
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// if ~ else문
	{
		//char* Name;
		int Number;

		printf("입력 : ");
		scanf_s("%d", &Number);

		if (Number == 1)
		{
			//Name = (char*)"홍길동";
			printf("홍길동");
		}
		else if (Number == 2)
		{
			//Name = (char*)"임꺽정";
			printf("임꺽정");
		}
		else if (Number == 3)
		{
			//Name = (char*)"이몽룡";
			printf("이몽룡");
		}
		else
		{
			printf("잘못 입력하였습니다.");
		}

		//printf("결과값 : %s\n", Name);
		printf("\n");
	}

	// switch ~ case문
	{
		int Number;

		printf("입력 : ");
		scanf_s("%d", &Number);

		switch (Number)
		{
		case 1:
			printf("홍길동");
			break;
		case 2:
			printf("임꺽정");
			break;
		case 3:
			printf("이몽룡");
			break;
		default:
			printf("잘못 입력하였습니다.");
			break;
		}

		printf("\n\n");
	}

	return 0;
}