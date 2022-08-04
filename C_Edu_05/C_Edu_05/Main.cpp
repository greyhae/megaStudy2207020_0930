/*
* Chapter 05 : Á¶°Ç¹®
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// if ~ else¹®
	{
		char* Name;
		int Number;

		printf("ÀÔ·Â : ");
		scanf("%d", &Number);

		if (Number == 1)
		{
			Name = (char*)"È«±æµ¿";
		}
		else if (Number == 2)
		{
			Name = (char*)"ÀÓ²©Á¤";
		}
		else
		{
			Name = (char*)"ÀÌ¸ù·æ";
		}

		printf("°á°ú°ª : %s\n", Name);
		printf("\n");
	}

	return 0;
}