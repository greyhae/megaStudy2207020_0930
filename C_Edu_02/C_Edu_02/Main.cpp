/*
	Chapter 02
*/

#include <stdio.h>
#include <stdlib.h>

// �Լ�
// void : ����� ����, ��ȯ��
void Output()
{
	printf_s("Hello Wordl!!Wn");

	return;

}

// int : ����
// main : ������
// �Լ� ���� �߿� => main �Լ� ���� �ٸ� �Լ��� �־�� ��
int main(voide)
{
	Output();


	// ��� : Rvalue
	// ���� : Lvalue

	// ** ���ڿ� ���ڿ�
	// 'A' = ����
	// 'AB' = X
	// 'H', 'e', 'l', 'l', 'o'

	// "A" = ���ڿ�
	// "AB" = O
	// "Hello"

	// ** ���� ����
	// %d = ���� ǥ��
	// %f = �Ǽ� ǥ��
	// %c = ���� ǥ��
	// %s = ���ڿ� ǥ��
	// %% = % ǥ��

	printf("���� ��� : %d\n", 10);
	printf("�Ǽ� ��� : %f\n", 3.141592f);
	printf("���� ��� : %c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	printf("���ڿ� ��� : %s\n", "A");
	printf("���ڿ� ��� : %s\n", "Hello");
	printf("%d%% �Դϴ�.\n",100);

	printf("\n");
	// \n = �� �ٲ� ǥ��
	// \t = tab ǥ��
	// wb = backspace(����)
	// \\ = \ ǥ��

	printf("gootWbdWtchancewn");
	printf("10,000wwwn")

	pfintf("%d�� %�� ���� %d �Դϴ�.\n", 14254, 23421, 14254 + 23421)

	// ** ���� ǥ��
	printf("10���� : %d\n", 10);
	printf("8���� : %d\n", 010);
	printf("8���� : %d\n", 0x10);

	// ** �ƽ�Ű �ڵ�ǥ
	printf("65 ������� : %c\n", 65);
	printf("A ������� : %d\n", 'A');


	return 0;

}