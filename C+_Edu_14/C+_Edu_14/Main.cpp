/*
	Vector
	
	벡터 삭제 pop_back 함수 실습 해볼 것!!!!!
*/

#include <stdio.h>
#include <malloc.h>

int* Front;
int* Back;

int size = 0;
int* Vector = nullptr;

void push_back(int _value);

int main(void)
{

	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);

	printf("%d\n", *Front);
	printf("%d\n", *Back);
	printf("%d\n", size);

	/*
	for (int i = 0; i < 10; ++i)
	{
		Vector[i] = i;
	}

	Front = &Vector[0];
	Back = &Vector[9];

	printf("%d\n", *Front);
	printf("%d\n", *Back);
	*/

	return 0;
}

void push_back(int _value)
{

	int* Temp = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		Temp[i] = Vector[i];

	free(Vector);

	++size;

	Vector = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		Vector[i] = Temp[i];

	// ** 동적할당이 끝난 데이터 삭제
	free(Temp);

	Vector[size - 1] = _value;

	Front = &Vector[0];
	Back = &Vector[size - 1];
}