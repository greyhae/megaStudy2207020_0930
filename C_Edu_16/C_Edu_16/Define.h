#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ** 상수
// 뒤에 f를 붙여야 한다. 없으면 double로
#define PI 3.141529f

// ** 메세지 출력
// 뒤에 ;(세미콜론)을 붙이면 ;까지 가져감
#define Output(str) printf("%s\n", str)
#define ERRMSG(FineName) printf("%d라인에서 Err가 발생했습니다.%s 에서 File을 찾을 수 없습니다.\n", __LINE__)

// ** 연산
#define SUM(a, b) (a + b)
#define MUL(a, b) (a * b)

// global 변수
extern int Count = 0;