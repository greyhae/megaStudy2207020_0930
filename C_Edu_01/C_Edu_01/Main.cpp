#include <stdio.h> 
//stdio.h : std -> standard, io -> input / output, .h : Ȯ����
//���ʿ� #�� �پ��ִٸ� ��ó����, ��ó�� ���ù�, ��ó���� ���ù� ������ ǥ��

#include <stdlib.h>
//lib -> library

//** ������ ���� ��� �޽����� ����� ����� ������
#define _CRT_SECCURE_NO_WARNINGS

//** main �Լ��� �ſ� Ư���� �Լ�
//** �����Ϸ��� ���α׷��� �����ų �� main �Լ��� ã�� ������
int main(void)
{
	//��� �Լ�
	printf("Be happy!");

	//** �ܼ� ��� ȭ���� �Ͻ� ���������ش�.
	system("pause");

	return 0;
}