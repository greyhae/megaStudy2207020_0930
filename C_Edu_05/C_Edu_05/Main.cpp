/*
* Chapter 05 : ���ǹ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// if ~ else��
	{
		//char* Name;
		int Number;

		printf("�Է� : ");
		scanf_s("%d", &Number);

		if (Number == 1)
		{
			//Name = (char*)"ȫ�浿";
			printf("ȫ�浿");
		}
		else if (Number == 2)
		{
			//Name = (char*)"�Ӳ���";
			printf("�Ӳ���");
		}
		else if (Number == 3)
		{
			//Name = (char*)"�̸���";
			printf("�̸���");
		}
		else
		{
			printf("�߸� �Է��Ͽ����ϴ�.");
		}

		//printf("����� : %s\n", Name);
		printf("\n");
	}

	// switch ~ case��
	{
		int Number;

		printf("�Է� : ");
		scanf_s("%d", &Number);

		switch (Number)
		{
		case 1:
			printf("ȫ�浿");
			break;
		case 2:
			printf("�Ӳ���");
			break;
		case 3:
			printf("�̸���");
			break;
		default:
			printf("�߸� �Է��Ͽ����ϴ�.");
			break;
		}

		printf("\n\n");
	}

	return 0;
}