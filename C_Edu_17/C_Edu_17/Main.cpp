/*
	Chapter 17
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	{
		// ** ���� �ʱ�ȭ �׹�
		char Array[10] = {'A','B','C','D','E','F','G','H','I','J'};

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);

		}
		printf("\n");
		printf("%s\n\n", Array);
	}

	{
		// ** ���ڿ� �ʱ�ȭ ���
		char Array[10] = { "ABCDEFGHI" };

		// ** ���ڿ� �ʱ�ȭ �ÿ��� ������ ���ڿ��� ������ ������ NULL ���� ���� �Ѵ�.
		// ** NULL ���� ������ 1byte ��ŭ �ʿ��ϹǷ� �����ʱ�ȭ ������� ������ 1 �� �ʿ���.

		{
			// ** �� ����
			NULL;
			//'\0';
		}

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);

		}
		printf("\n");
		printf("%s\n\n", Array);
	}


	{
		//(int* Pointer = &int)
		//(short* Pointer = &short)
		//(long* Pointer = &long)
		//(char* Pointer = &char)

		// ** ���� �迭 �ʱ�ȭ
		char Buffer[] = { 'A','B','C','D','E','F','G','H','I','J', NULL };

		// ** Buffer�� �ּҸ� str1 �� ����
		char* str1 = Buffer;

		// ** str1 ������ ���� �ּҸ� str2�� �����ϰ� �Ѱ��ش�.
		char* str2 = str1;

		// �̶� str1d�� �ּҿ� �ִ� ������ �����ϰ� �ȴٸ�
		str1[3] = 'A';

		// ** str2�� ���� �ּҸ� �����޾ұ� ������ ������ �Բ� ���� �Ǵ°��� �� ���ִ�.
		printf("str2 : %s\n", str2);

		int* Pointer = (int*)malloc(sizeof(int));
	}

	{
		// ** ���� ����� 
		// ** ���� �����ϱ�

		FILE* pf = fopen("../Datas/Data.txt", "w");

		if (pf == NULL)
			printf("������ ���� ���߽��ϴ�.\n");
		else
		{ 
			int Age = 32;
			char Name[128] = "ȫ�浿";

			int n = fscanf(pf, "%d", &Age);
			
			fgets(Name, sizeof(Name), pf);
			fprintf(pf, "%s : %d", Name, Age);

			fclose(pf);
		}

	}

	{
		// ** ���� �ҷ�����

		FILE* pf = fopen("../Datas/Data.txt", "r");

		int Age[20];
		char Name[128];

		int Count = 0;

		while (fgetc(pf) != NULL)
		{
			fgets(Name, sizeof(Name), pf);

			printf("%s\n", Name);

			fflush(pf);

		}
	}

	return 0;
}