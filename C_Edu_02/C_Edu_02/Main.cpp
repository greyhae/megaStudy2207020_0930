/*
	Chapter 02
*/

#include <stdio.h>
#include <stdlib.h>

// 함수
// void : 출력의 형태, 반환값
void Output()
{
	printf_s("Hello Wordl!!Wn");

	return;

}

// int : 정수
// main : 진입점
// 함수 순서 중요 => main 함수 위로 다른 함수가 있어야 함
int main(voide)
{
	Output();


	// 상수 : Rvalue
	// 변수 : Lvalue

	// ** 문자와 문자열
	// 'A' = 문자
	// 'AB' = X
	// 'H', 'e', 'l', 'l', 'o'

	// "A" = 문자열
	// "AB" = O
	// "Hello"

	// ** 서식 문자
	// %d = 정수 표현
	// %f = 실수 표현
	// %c = 문자 표현
	// %s = 문자열 표현
	// %% = % 표현

	printf("정수 출력 : %d\n", 10);
	printf("실수 출력 : %f\n", 3.141592f);
	printf("문자 출력 : %c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	printf("문자열 출력 : %s\n", "A");
	printf("문자열 출력 : %s\n", "Hello");
	printf("%d%% 입니다.\n",100);

	printf("\n");
	// \n = 줄 바꿈 표현
	// \t = tab 표현
	// wb = backspace(삭제)
	// \\ = \ 표현

	printf("gootWbdWtchancewn");
	printf("10,000wwwn")

	pfintf("%d과 %의 합은 %d 입니다.\n", 14254, 23421, 14254 + 23421)

	// ** 진수 표현
	printf("10진수 : %d\n", 10);
	printf("8진수 : %d\n", 010);
	printf("8진수 : %d\n", 0x10);

	// ** 아스키 코드표
	printf("65 문자출력 : %c\n", 65);
	printf("A 정수출력 : %d\n", 'A');


	return 0;

}