/*
* Chapter 04
*/

#include <stdio.h>

int main(void)
{
	// ** 산술 연산자
	// +, -, *, / , %
	
	// ** 대입 연산자
	// =
	
	// ** 복합대입 연산자
	// +=, -=, *=, /=, %=
	
	{
		int a = 10, b = 20;
		// a = a + b
		a += b;

		// a = a - b
		a -= b;

		// a = a * b
		a *= b;

		// a = a / b
		a /= b;

		// a = a % b
		a %= b;

	}
	// ** 단항 연산자(증감 연산자)
	// ++, --
	// * 전위 연산 : ++ or -- (항목)
	// * 후위 연산 : (항목) ++ or --
	
	// { } 안에서 변수는 지역 변수
	{
		// ** 1씩 증가하거나 1씩 감소한다.
		int i = 0;

		// ** 전위연산 : 전위 연산을 우선순위로 한다.
		printf("%d\n", ++i);

		// ** 후위연산 : 후위 연산을 우선순위로 한다.
		printf("%d\n", --i);


		// ** 현재값 출력
		printf("현재값 : %d\n", i);

	}
	
	// ** 2항 연산자
	// ** (항목 A ) +  (항목 B)
	// ** (항목 A ) +  (항목 B) - (항목 c)
	// ** (항목 A ) +  (항목 B) - (항목 C) * (항목 D)
	
	// ** 3항 연산자
	// (조건) ? trus : false

	{
		int i = 10;
		int n = (i > 10) ? i : 0;

		printf("n : %d\n", n);
		printf("\n");

	}
	// ** 관계 연산자
	// >, <, >=, <=
	
	// ** 논리 연산자
	// ==, !=, !, &&, ||

	{
		// A = 10, B = 11
		int A = 10, B = 11;
		printf("int A = 10 B= 11;\n", (A == B));

		// ** [A = B} : A와 B는 같은가? false
		printf("조건 (A == B) ? 참 : 1/거짓:0 = %d\n", (A ==B));

		// ** [A != B} : A와 B는 같지 않은가? true
		printf("조건 (A != B) ? 참 : 1/거짓:0 = %d\n", (A != B));

	}

	// A= 0
	// ** [!(항목ㅁ)]
	{
		int A = 0;
		printf("A : %d\n", !A);
		printf("A : %d\n", !A);
		printf("A : %d\n", !A);
	}


	{
		// &&
		// ** 항목 A와 항목 B 가 모두 true일 때 true를 반환
		int A = 0, B = 0;
		
		printf("&& 연산자\n");
		printf("A && B ? 참 :1/거짓:0=%d\n", A && B);
		printf("\n");

		int a, b, c, d;
		a = 20;
		b = 10;
		c = 30;
		d = 40;
		printf("(a > b) && (c < d) %d\n", (a > b) && (c < d));


	}

	{
		// [||]
		// ** 항목 A와 항목 B 중 1개만 true라도 true를 반환
		int A = 0, B = 0;
		printf("|| 연산자\n");
		printf("A || B ? 참 :1/거짓:0=%d\n", A || B);
		printf("\n");

		int a, b, c, d;
		a = 10;
		b = 20;
		c = 30;
		d = 40;
		printf("(a > b) || (c < d) %d\n", (a > b) || (c < d));
	}

	// ** 비트 연산자
	// & [AND]
	// | [OR]
	// ^ [XOR]

	// ** 형변환
	{
		char c = 'A';
		short s = 32767;
		int i = 100000000;

		float f = 3.141592f;

		{

			i = (int)f;

			printf("%d\n", i);
		}

	}

	return 0;
}