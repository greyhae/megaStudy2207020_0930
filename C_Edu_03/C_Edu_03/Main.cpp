/*
* Chapter 03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1bit = 0 or 1
// 2bit = 00, 01, 10, 11
// 3bit = 000, 001, 010, 100, 101, 110, 111 = 8개
/* 4bit = 16개
	0000, 0001, 0010, 0011, 0100. 0101, 0110, 0111, 
	1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
*/

// 5bit = 32개
// 6bit = 64개
// 7bit = 128개
// 8bit = 256개 = 1byte

// 10000000 = -128
//	.
//	.
//	.
//	.
// 11111110 = -2
// 11111111 = -1
// 00000000 = 0
// 00000001 = 1
// 00000010 = 2
// 00000011 = 3
// 00000100 = 4
//	.
//	.
//	.
//	.
// 01111111 = 127


int main(void)
{
	// ** sizeof() = 데이터의 크기를 정수로 변환
	printf("char : %d\n", sizeof(char));
	printf("short : %d\n", sizeof(short));
	printf("int : %d\n", sizeof(int));
	printf("long : %d\n", sizeof(long));
	printf("__int64 : %d\n", sizeof(__int64));
	printf("\n");


	// ** sizeof() = 데이터의 크기를 정수로 변환
	printf("unsigned char : %d\n", sizeof(unsigned char));
	printf("unsigned short : %d\n", sizeof(unsigned short));
	printf("unsigned int : %d\n", sizeof(unsigned int));
	printf("unsigned long : %d\n", sizeof(unsigned long));
	printf("unsigned __int64 : %d\n", sizeof(unsigned __int64));
	printf("\n");

	// ** 변수 선언
	char c;// (자료형 : char) (변수이름 : c)

	// ** 볁수 초기화
	c = 127; // (변수이름 : C) (대입연산자 : =) (값 : 127)
	
	// ** 변수 선언 및 초기화
	short s = 32767;	// (short : char)(변수이름 : s) (대입연산자 : =) (값 : 32767)
	int i = 2147483647;	
	long n = 2147483647;

	// ** 초기화된 변수의 값을 출력
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");

	// 데이터 타입의 최대 표현범위보다 +1 씩 더 갖게된 경우
	c = c + 1;
	s = s + 1;
	i = i + 1;
	n = n + 1;

	// ** 어떻게 출력되는지 확인
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");

	unsigned char uc = 127;
	unsigned short us = 32767;
	unsigned int ui = 2147483647;
	unsigned long un = 2147483647;

	// 값을 1씩 더해줌
	uc = uc + 1;
	us = us + 1;
	ui = ui + 1;
	un = un + 1;

	// ** 어떻게 출력되는지 확인
	printf("char : %d\n", uc);
	printf("short : %d\n", us);
	printf("int : %u\n", ui);
	printf("long : %u\n", un);
	printf("\n");

	// ** 실수형 데이터 타입 크기 확인
	printf("float : %d\n", sizeof(float));
	printf("double : %d\n", sizeof(double));
	printf("long double : %d\n", sizeof(long double));
	printf("\n");


	// ** 입력
	int Number;// = 0;

	printf_s("입력 : ");
	scanf_s("%d", &Number);

	printf_s("입력받은 값 : %d", Number);


	int age;// 나이 : 정수형
	double height; // 키 : 실수형

	printf("나이와 키를 입력하세요 : "); // 입력 안내 메시지 출력
	scanf("%d%lf", &age, &height); // 나이와 키를 함께 입력
	printf("나이는 %d살, 키는 %.1fcm입니다\n", age, height); // 입력값 출력



	return 0;
}