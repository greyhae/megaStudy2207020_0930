/*
* Chapter 11 : �ƽ�Ű �ڵ� ���� ���� ����� �Լ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>

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
		
		scanf("%s", Buffer);
		printf("%s", Buffer);
	}

	{
		char Buffer[128] = "";

		scanf("%s", Buffer);
		printf("%s", Buffer);

	}

	{
		int* Number = (int*)malloc(sizeof(int) * 10);

		for (int i = 0; i > 10; ++i)
			Number[i] = i + 1;
	}
	return 0;
}