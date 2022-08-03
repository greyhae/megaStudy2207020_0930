/*
* Chapter 03
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1bit = 0 or 1
// 2bit = 00, 01, 10, 11
// 3bit = 000, 001, 010, 100, 101, 110, 111 = 8��
/* 4bit = 16��
	0000, 0001, 0010, 0011, 0100. 0101, 0110, 0111, 
	1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
*/

// 5bit = 32��
// 6bit = 64��
// 7bit = 128��
// 8bit = 256�� = 1byte

// 10000000 = -128
//	.
//	.
//	.
//	.
// 11111110 = -2
// 11111111 = -1
// 00000000 = 0
// 00000001 = 1
// 00000010 = 2
// 00000011 = 3
// 00000100 = 4
//	.
//	.
//	.
//	.
// 01111111 = 127


int main(void)
{
	// ** sizeof() = �������� ũ�⸦ ������ ��ȯ
	printf("char : %d\n", sizeof(char));
	printf("short : %d\n", sizeof(short));
	printf("int : %d\n", sizeof(int));
	printf("long : %d\n", sizeof(long));
	printf("__int64 : %d\n", sizeof(__int64));
	printf("\n");


	// ** sizeof() = �������� ũ�⸦ ������ ��ȯ
	printf("unsigned char : %d\n", sizeof(unsigned char));
	printf("unsigned short : %d\n", sizeof(unsigned short));
	printf("unsigned int : %d\n", sizeof(unsigned int));
	printf("unsigned long : %d\n", sizeof(unsigned long));
	printf("unsigned __int64 : %d\n", sizeof(unsigned __int64));
	printf("\n");

	// ** ���� ����
	char c;// (�ڷ��� : char) (�����̸� : c)

	// ** �ϼ� �ʱ�ȭ
	c = 127; // (�����̸� : C) (���Կ����� : =) (�� : 127)
	
	// ** ���� ���� �� �ʱ�ȭ
	short s = 32767;	// (short : char)(�����̸� : s) (���Կ����� : =) (�� : 32767)
	int i = 2147483647;	
	long n = 2147483647;

	// ** �ʱ�ȭ�� ������ ���� ���
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");

	// ������ Ÿ���� �ִ� ǥ���������� +1 �� �� ���Ե� ���
	c = c + 1;
	s = s + 1;
	i = i + 1;
	n = n + 1;

	// ** ��� ��µǴ��� Ȯ��
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");

	unsigned char uc = 127;
	unsigned short us = 32767;
	unsigned int ui = 2147483647;
	unsigned long un = 2147483647;

	// ���� 1�� ������
	uc = uc + 1;
	us = us + 1;
	ui = ui + 1;
	un = un + 1;

	// ** ��� ��µǴ��� Ȯ��
	printf("char : %d\n", uc);
	printf("short : %d\n", us);
	printf("int : %u\n", ui);
	printf("long : %u\n", un);
	printf("\n");

	// ** �Ǽ��� ������ Ÿ�� ũ�� Ȯ��
	printf("float : %d\n", sizeof(float));
	printf("double : %d\n", sizeof(double));
	printf("long double : %d\n", sizeof(long double));
	printf("\n");


	// ** �Է�
	int Number;// = 0;

	printf_s("�Է� : ");
	scanf_s("%d", &Number);

	printf_s("�Է¹��� �� : %d", Number);


	int age;// ���� : ������
	double height; // Ű : �Ǽ���

	printf("���̿� Ű�� �Է��ϼ��� : "); // �Է� �ȳ� �޽��� ���
	scanf("%d%lf", &age, &height); // ���̿� Ű�� �Բ� �Է�
	printf("���̴� %d��, Ű�� %.1fcm�Դϴ�\n", age, height); // �Է°� ���



	return 0;
}