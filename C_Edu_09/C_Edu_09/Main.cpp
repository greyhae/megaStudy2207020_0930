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

	return 0;
}