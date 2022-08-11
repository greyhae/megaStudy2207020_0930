/*
* Chapter 09 : ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main(void)
{
	{
		// ** 1�ܰ�
		
		// ** �Ϲ� ����
		int Number = 10;
		// ** �Ϲ� ������ �����͸� ���´�.

		// ** ������ ����
		int* pNumber;
		// ** ������ ������ [*]�� �ٿ��ش�.
		// ** ������ ������ �Ϲ� ������ �ּҸ� ���´�.
	}

	{
		// ** 2�ܰ�

		int Number = 10;

		// ** �ּҴ� ������ ���� ǥ���� �� �ִ�.
		printf_s("�ּ� : %p\n", &Number);
		printf_s("������ : %d\n", Number);
	}

	{
		// ** 3�ܰ�

		int Number = 10;

		// ** ������ ������ �Ϲ� ������ �ּҸ� ���´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Pointer : %d\n", *pNumber);
		printf_s("\n");

	}

	{
		// ** 4�ܰ�

		int Number = 10;

		// ** ������ ������ �Ϲ� ������ �ּҸ� ���´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("Number �ּ� : %p\n", &Number);
		printf_s("Pointer �� ����Ű�� �� : %p\n", pNumber);
		printf_s("Pointer �� �ּ� : %p\n", &pNumber);
		printf_s("\n");

	}

	{
		// ** ������ ������ �Ϲ� ������ �����͸� �����Ѵ�.
		// ** ����

		int Number = 10;

		// ** ������ ������ �Ϲ� ������ �ּҸ� ���´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");

		// ** �Ϲ� ������ ���� ����
		Number = 100;

		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");

		// ** ������ ������ ���� ����
		*pNumber = 1000;

		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");
	}

	{
		// ** swap
		
		int a = 10;
		int b = 20;

		printf("a : %d\n", a);
		printf("b : %d\n", b);

		if (true)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		printf("a : %d\n", a);
		printf("b : %d\n", b);
	}

	{
		// ** swap

		int a = 10;
		int b = 20;
		
		a ^= b;
		b ^= a;

		printf("a : %d\n", a);
		printf("b : %d\n", b);
	}

	{
		// ** �������� ũ��� ����ȯ�濡 ���� �� ũ�Ⱑ �޶�����.
		int Number = 10;
		long long lNum = 10;
		long long* Pointer = &lNum;


		// ** �������� ũ��
		// x86 = 4byte
		// x64 = 8byte

		printf("%d\n\n", sizeof(Number));
		printf("%d\n\n", sizeof(lNum));
		printf("%d\n\n", sizeof(Pointer));

	}

	return 0;
}