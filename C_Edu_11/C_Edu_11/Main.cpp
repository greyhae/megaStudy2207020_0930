/*
* Chapter 11 : �迭�� ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>

void print_arr(int* _pArr, int _size);
//void print_arr(int _pArr[], int _size);

int main(void)
{
	{
		// ** �迭�� ����� ���� ���
		//char Buffer[5] = "�ѱ�";
		char Buffer[] = "�ѱ�";


		// ** ���
		printf("%c%c %c%c\n", 
			Buffer[0],
			Buffer[1], 
			Buffer[2], 
			Buffer[3]);
	}
	printf("\n");

	{
		// ** �����͸� ����� ���� ���

		// ** "�ѱ�" = ���ڿ��� �ʱ�ȭ �Ǿ��ֱ� ������ char[5] ��ŭ�� ���̸� �����ִ�.
		// ** ���ڿ� ���� �迭�� �ν��ϱ� ������ ������ ���� �� ��ȯ�� �ʿ��ϴ�.
		char* Buffer = (char*)"�ѱ�";

		// ** ���
		printf("%c%c %c%c\n",
			Buffer[0],
			Buffer[1],
			Buffer[2],
			Buffer[3]);
	}
	printf("\n");

	{
		// ** ������ ������ ���ڸ� ���� �Է¹��� �� ����
		char* Buffer = (char*)"�ѱ�";
		
		//scanf("%s", Buffer);
		//printf("%s", Buffer);
	}

	{
		char Buffer[128] = "";

		//scanf("%s", Buffer);
		//printf("%s", Buffer);

	}

	{
		/*int* Number = (int*)malloc(sizeof(int) * 10);

		for (int i = 0; i > 10; ++i)
			Number[i] = i + 1;

		for (int i = 0; i > 10; ++i)
			printf("%d\n", Number[i]);
		printf("sizeof : %d", sizeof(Number));*/
	}

	{
		int Array[5] = { 10,20,30,40,50 };

		int* pArr = Array;
		int* pArr2 = Array + 2;

		printf("1. �ּ� : %d\n", Array); // ���� �ּ�
		printf("1. �� : %d\n", Array); // ���� �ּ�
		printf("2 :. %d\n", *(Array + 1)); // 20
		printf("3 �ּ�. : %d\n", *pArr2 + 2); // 30�� �ּ�
		printf("3. �� : %d\n", pArr[3]); // 40
		printf("4. : %d\n", pArr[3]); // 40
		printf("5. %d\n", *pArr2); // 30
		printf("6. %d\n", pArr2 - pArr); // 2
		printf("7. %d\n", pArr2[-2]); // 10
	}
	printf("\n");

	int Array[5] = { 10,20,30,40,50 };

	print_arr(Array, 5);

	// �迭�� ����� ���� �ȿ��� �迭�� ũ�⸦ �Ʒ��� ���� ������ ���� �� ũ�⸦ �˼� �ִ�.
	int Size = sizeof(Array) / sizeof(Array[0]);

	printf("%d\n", Size);

	return 0;
}


// ** �迭�� ������ ������ [int*]�� ���� ������� �Ʒ��� ���� ���� ����
/*
void print_arr(int _pArr[], int _size)
{

	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		// �Ǵ� 
		//printf("%d\n", *(_pArr + 1));
	}
}
*/

// ** �迭�� �Լ��� ������ ������ �ݵ�� �迭�� ũ�⸦ �Բ� �����ؾ� �Ѵ�.
void print_arr(int* _pArr, int _size)
{

	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		// �Ǵ� 
		//printf("%d\n", *(_pArr + 1));
	}
}