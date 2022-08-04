/*
* Chapter 05 : Á¶°Ç¹®
*/

#include <stdio.h>

using namespace std;

int main(void) {

	// if

	char* Name;
	int Number;

	printf("ÀÔ·Â : ");
	//scanf("%d", &Number);

	if (Number == 1)
	{
		Name = (char*)"È«±æµ¿";
	}
	else if(Number == 2)
	{
		Name = (char*)"ÀÓ²©Á¤";
	}
	else 
	{
		Name = (char*)"ÀÌ¸ù·æ";
	}

	printf("°á°ú°ª : %s\n", Name);
	printf("\n");

	return 0;
}