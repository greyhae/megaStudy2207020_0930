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

void Output(Student* _std);

int main(void)
{
	Student Std;

	Std.Name = (char*)"ȫ�浿";
	Std.Kor = 100;
	Std.Eng = 90;
	Std.Math = 90;
	Std.Number = 1;


	/*
	{
		int numbe = 10;
		int* pointer = &number;
	}
	*/

	//printf("%d\n", sizeof(Student));
	Output(&Std);

	return 0;
}

void Output(Student* _std)
{
	printf("�л� ��ȣ : %d\n", _std->Number);
	printf("�л� �̸� : %s\n", _std->Name);
	printf("���� ���� : %d\n", _std->Kor);
	printf("���� ���� : %d\n", _std->Eng);
	printf("���� ���� : %d\n", _std->Math);
}