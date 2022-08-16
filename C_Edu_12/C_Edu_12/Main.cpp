/*
* Chapter 12 : ���ڿ��� ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>

int main(void)
{
	printf("apple�� ����� ���� �ּ� �� : %p\n", "apple");
	printf("�ι�° ���� �ּ� �ּ� �� : %p\n", "apple" + 1);
	printf("ù��° ���� : %c\n", *"apple");
	printf("�ι�° ���� : %c\n", *("apple" + 1));
	printf("�迭�� ǥ���� ����° ���� : %c\n", "apple"[2]);
	printf("\n");

	// ** 451p ����
	{ 

		int* pi;
		double* pd;

		pi = (int*)malloc(sizeof(int));
		if (pi == NULL)
		{
			printf("# �޸𸮰� �����մϴ�.\n");
			exit(1);
		}
		pd = (double*)malloc(sizeof(double));

		*pi = 10;
		*pd = 3.141592;

		printf("���������� ��� : %d\n", *pi);
		printf("�Ǽ������� ��� : %.7lf\n", *pd);

		free(pi);
		free(pd);
	}
	printf("\n");

	{
		printf("(void*) size : %d\n", sizeof(void*));
	}

	{
		// ** (void*) �� ���
		int Array[5] = { 10,20,30,40,50 };

		void* pArr = Array;

		int* i = (int*)pArr;
		float* f = (float*)pArr;

		// ** ���°� �����Ǿ����� ���
		printf("%d\n", i);

		// ** ���°� �ٲ� �߻��� �� �ִ� ����
		printf("%f\n", f);
	}

	return 0;

}