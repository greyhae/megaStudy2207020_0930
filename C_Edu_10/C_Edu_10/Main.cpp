/*
* Chapter 10 : �迭�� ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main(void)
{
	{
		int Array[8] = { 0 };

		for (int i = 0; i < 8; ++i)
			Array[i] = i + 1;

		printf("[�Ϲ� ���]\n");

		for (int i = 0; i < 8; ++i)
			printf("%d\n", Array[i]);
		printf("\n");


		printf("[�����͸� ����� ���]\n");

		// ** �迭�� �ε���(���ȣ)�� ���� ���·� �ּҹ�ȯ ������ ����
		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			printf("%d\n", *(iter + i));
		printf("\n");
	}

	{
		int Array[8] = { 0 };

		// ** ����
		printf("[�����͸� ����� ������� �߻��� �� �ִ� ����]\n");

		int* iter = Array;

		for (int i = 0; i < 100; ++i)
			printf("%d\n", *(iter + i));
		printf("\n");
	}

	return 0;
}