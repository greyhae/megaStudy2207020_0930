/*
* Chapter 05 : ���ǹ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// if ~ else��
	{
		char* Name;
		int Number;

		printf("�Է� : ");
		scanf("%d", &Number);

		if (Number == 1)
		{
			Name = (char*)"ȫ�浿";
		}
		else if (Number == 2)
		{
			Name = (char*)"�Ӳ���";
		}
		else
		{
			Name = (char*)"�̸���";
		}

		printf("����� : %s\n", Name);
		printf("\n");
	}

	return 0;
}