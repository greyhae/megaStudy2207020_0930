/*
* Chapter 05 : ���ǹ�
*/

#include <stdio.h>

using namespace std;

int main(void) {

	// if

	char* Name;
	int Number;

	printf("�Է� : ");
	//scanf("%d", &Number);

	if (Number == 1)
	{
		Name = (char*)"ȫ�浿";
	}
	else if(Number == 2)
	{
		Name = (char*)"�Ӳ���";
	}
	else 
	{
		Name = (char*)"�̸���";
	}

	printf("����� : %s\n", Name);
	printf("\n");

	return 0;
}