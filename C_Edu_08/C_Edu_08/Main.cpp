/*
* Chapter 08 : �迭
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main(void)
{
	//���� ������ �տ� ���� �տ� ������ �ִ� �ɷ� Ȯ�� : ex: int

	// ���� ���� �����Ͽ� ���
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

	// ** ���� : ������ �������� ���� �ۼ��Ͽ��� �Ѵ�. ���ŷӴ�.

	// ** �ϳ��� �迭�� �����Ͽ� ���
	// ** int => �ڷ���, Number => �迭��, [5] => �迭 ����
	int Number[5] = { 1, 2, 3, 4, 5 };

	printf("Number[0] : %d\n", Number[0]);
	printf("Number[1] : %d\n", Number[1]);
	printf("Number[2] : %d\n", Number[2]);
	printf("Number[3] : %d\n", Number[3]);
	printf("Number[4] : %d\n", Number[4]);
	printf("\n");

	// ** ���� 1 : �迭�� ���������ν�, �ʱ�ȭ ������ ������ �پ���.

	// ** ���� ********** //

	// ** �迭�� ����Ͽ� ����� ������ �Ʒ��� ���� �ݺ����� ���� �迭�� Ȱ���� �� �մ�
	for (int i = 0; i < 5; ++i) 
	{
		printf("Number[%d] : %d\n", i, Number[i]);
	}	
	printf("\n");

	// ** ���� 2 : ���� ���� ��������ν�, ����� ������ ������ �پ���.

	{
		// ** ����� �Ұ����� �迭 ��.
		// Int Number[5] = 10;
		// Number[5] = 10;
	}

	{
		// ** �������� ����� ��
		int Array[5];

		//Array[0];
		//Array[1];
		//Array[2];
		//Array[3];
		//Array[4];

		/*
		printf("1. �Է� : ");
		scanf_s("%d", Array[0]);
		printf("2. �Է� : ");
		scanf_s("%d", Array[1]);
		printf("3. �Է� : ");
		scanf_s("%d", Array[2]);
		printf("4. �Է� : ");
		scanf_s("%d", Array[3]);
		printf("5. �Է� : ");
		scanf_s("%d", Array[4]);
		*/
	}

	{
		// ** �迭�� �ʱ�ȭ
		{
			// ** ��ü �ʱ�ȭ
			int Array[5] = { 1, 2, 3, 4, 5 };

			// ** 5���� ���ҿ� ���� 1, 2, 3, 4, 5�� ���� �ʱ�ȭ ��
		}

		{
			// ** �κ� �ʱ�ȭ
			int Array[5] = { 1, 2 };

			// ** ù��°�� �ι�° ���Ҹ� ���� 1�� 2�� �ʱ�ȭ�ǰ�
			// ** ������ ���ҵ��� 0���� �ʱ�ȭ�ȴ�.

		}

		{
			// ** 0 �ʱ�ȭ
			int Array[5] = { 0 };

			// ** ��ü ���Ұ� 0���� �ʱ�ȭ �ȴ�.
		}


		{
			// ** �迭�� ���̸� ������ �ʰ� �ʱ�ȭ
			int Array[] = { 1, 2, 3, 4, 5 };
			// ** ��ü ���Ұ�����ŭ ���̸� �ʱ�ȭ�Ѵ�.

			// �迭�� �ѱ��̸� ���� 1���� ������ ũ��� ������ ������ ������ Ȯ���� �� �ִ�.
			//int Count = sizeof(�迭�� �ѱ���) / sizeof(���� 1���� ũ��);
			int Count = sizeof(Array) / sizeof(int);

			printf("Count : %d\n", Count);
			printf("\n");
		}
	}

	{
		// ** 2�� n�¿� �ش��ϴ� ������ �迭�� ���̸� �ʱ�ȭ ���ش�.
		// ** ex) 10���� ����ϰ� �ʹٸ� 16��ŭ�� ���̷� �ʱ�ȭ�� ������ ��
		int Array[16];

		// ** �Ʒ��� ���� 10��ŭ ����ϸ� �ȴ�
		for (int i = 0; i < 10; ++i)
		{
			Array[i] = 0;
		}
	}

	// ** ���ڿ� �迭 ******************** //
	{
		{
			// ** null ���ڰ� ���� ���
			char Array[5] = { 'A', 'p', 'p', 'l', 'e' };

			printf_s("null ���ڰ� ���� ��� : %s", Array);
		}
		printf("\n");

		{
			// ** null ���ڰ� �ִ� ���
			char Array[6] = { 'A', 'p', 'p', 'l', 'e', '\0' };

			printf_s("null ���ڰ� �ִ� ��� : %s", Array);
		}
		printf("\n");
	}

	
	{
		// ** ���ڿ� �ʱ�ȭ
		// ** �Ʒ��� ���� ���ڿ��� �ʱ�ȭ�� ��� �ڵ����� �� ���ڰ� ���Ե�
		char str1[128] = "cat";
		char str2[128];

		// ** ���ڿ� ����
		strcpy(str1, "tiger");
		strcpy(str2, str1);

		printf("str2 : %s\n", str2);
	}

	return 0;

}