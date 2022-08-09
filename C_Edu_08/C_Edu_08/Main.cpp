/*
* Chapter 08 : 배열
*/

#include <stdio.h>

int main(void)
{
	//변수 선언은 앞에 변수 앞에 유형이 있는 걸로 확인 : ex: int

	// 변수 선언을 각각
	int Number1 = 1;
	int Number2 = 2;
	int Number3 = 3;
	int Number4 = 4;
	int Number5 = 5;

	printf("Number1 : %d\n", Number1);
	printf("Number2 : %d\n", Number2);
	printf("Number3 : %d\n", Number3);
	printf("Number4 : %d\n", Number4);
	printf("Number5 : %d\n", Number5);
	printf("\n");

	// ** 단점 : 각각의 변수명을 직접 작성하여야 한다. 번거롭다.

	// ** 하나의 배열을 선언하여 출력
	// ** int => 자료형, Number => 배열명, [5] => 배열 길이
	int Number[5] = { 1, 2, 3, 4, 5 };

	printf("Number[0] : %d\n", Number[0]);
	printf("Number[1] : %d\n", Number[1]);
	printf("Number[2] : %d\n", Number[2]);
	printf("Number[3] : %d\n", Number[3]);
	printf("Number[4] : %d\n", Number[4]);
	printf("\n");

	// ** 장점 1 : 배열로 선엄함으로써, 초기화 구문이 현저히 줄었다.

	// ** 응용 ********** //

	// ** 배열을 사용하여 출력할 때에는 아래와 같이 반복문을 통해 배열을 활용할 수 잇다
	for (int i = 0; i < 5; ++i) 
	{
		printf("Number[%d] : %d\n", i, Number[i]);
	}	
	printf("\n");

	// ** 장점 2 : 

	return 0;

}