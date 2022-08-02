#include <stdio.h> 
//stdio.h : std -> standard, io -> input / output, .h : 확장자
//앞쪽에 #이 붙어있다면 전처리기, 전처리 지시문, 전처리기 지시문 등으로 표현

#include <stdlib.h>
//lib -> library

//** 보안을 위한 경고 메시지를 띄우지 말라고 지시함
#define _CRT_SECCURE_NO_WARNINGS

//** main 함수는 매우 특별한 함수
//** 컴파일러가 프로그램을 실행시킬 때 main 함수를 찾기 때문에
int main(void)
{
	//출력 함수
	printf("Be happy!");

	//** 콘솔 출력 화면을 일시 정지시켜준다.
	system("pause");

	return 0;
}