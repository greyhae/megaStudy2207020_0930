/*
* Chapter 07 : �Լ�
*/

#include <stdio.h>

// ** �Լ��� ���� ����
int sum(int x, int y);
// ** ���� ������ �׻� main(void)�� ��ܿ� ��ġ���Ѿ� �Ѵ�.

// �Լ� ���� ����� �Ű������� �̸��� �����ص� �ȴ�.
void Output(int, int);
int Compare(int _x, int _y);
void ����Լ�();

// ** �Լ��� ��������� ȣ��Ǳ� ������ ����Ǵ� ������ ���ٸ� ���� �������ο� �߻��Ѵ�.
/*
void Recursive()
{
	printf("���ȣ��");
	Recursive();
}
*/

// ** �Ű������� ����Ͽ�  ����Լ��� 
void Recursive(int _n)
{
	if(_n == 0)
		return;
	else
		printf("%d ���ȣ��\n", _n);
		Recursive(_n - 1);
		
}

int main(void)
{
	int a = 10, b = 20;
	int result;

	result = sum(a, b);
	printf("result : %d\n", result);

	// ** ���� ǥ���ϴ� �߰�ȣ {}�� ����Ͽ�, �������� ������ ���� �� �ִ�.
	{

	}

	// ** ���� ��ο����� ���� ���
	{
		// ���� �̸��� ������ ���
		int x = 10;
		{
			// ** ������ �̸��� ���� ��� �ش� ���� ���ο� �ִ� ������ �켱������ ���Ѵ�.
			int x = 20;

			printf_s("ù��° : %d\n", x);
		}

		printf_s("�ι�° : %d\n", x);

		// ** 1. ���� : ������ �ִ� ������ ���� ����� �� ����.
		// ** 2. ���� : ������ �̸��� ���� ������ ���� ��뿡 ȥ���� ���� �� �ִ�.
	}

	// ** ������ ���� �Ⱓ
	{
		// ** ������ ����� �ش� ������ ����Ǵ� �������� ��� ����
		int ����1 = 10;

		{
			int ����2 = 20;
			����1 = ����2;
			// ����1 <= ��� ����
		}
		
		// ����2 = 30; <= X ��� �Ұ�
	}


	{
		// ** ���� �̸��� �������� �ٸ� �������� ���� ���� �� �ִ�.
		int result = sum(a, b);
	}

	Output(10, 20);

	int result2 = Compare(30, 30);
	printf("%d\n", result2);

	Recursive(5);

	return 0;
}

// �Լ��� ����
// ** �Ű������� �ڿ������� �����ȴ�.
int sum(int x, int y) {
	int temp;

	temp = x + y;

	return temp;
}

// void Output(void) = > void�� ���� ����
void Output(int _x, int _y)
{
	//printf("Output �Լ� ȣ���");
	printf("%d + %d = %d �Դϴ�.\n", _x, _y, _x + _y);
}

int Compare(int _x, int _y)
{
	if (_x > _y)
		return _x;
	else if (_x < _y)
		return _y;
	else
		return 0;
}
