/*
* Chapter 13 : ����ü
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <malloc.h>

struct Student
{
	char* Name;
	int Number;
	int Kor;
	int Eng;
	int Math;
};

void Output(Student* _std, int _size);

int main(void)
{
	Student Std[10];

	//Std.Name = (char*)"ȫ�浿";
	//Std.Kor = 100;
	//Std.Eng = 90;
	//Std.Math = 90;
	//Std.Number = 1;

	// ** �迭�� ũ�⸦ �� �� �ִ�.

	for (int i = 0; i < (sizeof(Std) / sizeof(Std[0])); ++i)
	{
		Std[i].Kor = i * 10;
		Std[i].Eng = i * 20;
		Std[i].Math = i * 30;
		Std[i].Number = i + 1;
	}

	/*
	{
		int numbe = 10;
		int* pointer = &number;
	}
	*/

	int i = 10;
	int Array[10] = { 1,2,3,4,5,6,7,8,9 };
	int* pi = &i;

	pi = Array;
	printf("%d\n", pi);
	printf("%d\n", *(pi + 1));

	//printf("%d\n", sizeof(Student));
	Output(Std, sizeof(Std) / sizeof(Std[0]));

	return 0;
}

// ** �Ű������� �迭�� ���� �� ������ �迭�� ũ�⸦ �Բ� �������־�� �Ѵ�.
void Output(Student* _std, int _size)
{
	for (int i = 0; i < _size; ++i)
	{ 
		//printf("�л� �̸� : %s\n", _std->Name);
		printf("�л� ��ȣ : %d\n", (_std + 1)->Number);
		printf("���� ���� : %d\n", (_std + 1)->Kor);
		printf("���� ���� : %d\n", (_std + 1)->Eng);
		printf("���� ���� : %d\n", (_std + 1)->Math);
		printf("\n");
	}
}