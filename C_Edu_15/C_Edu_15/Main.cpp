/*
	Chapter 15
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	{
		// ** 1���� �迭 �� �ʱ�ȭ
		int Array[2] = { 1,2 };
	}

	{
		// ** 2���� �迭 �� �ʱ�ȭ
		int Array[2][2] = {{ 0,1 }, { 2, 3 }};
	}

	{
		// ** ������ �迭 �� �ʱ�ȭ
		int Array[2][3][4][5] = {
			{
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
			}, 
			{
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
				{
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
				},
			}
		};
	}

	{
		// ** 2���� �迭 �� �ʱ�ȭ
		int Array[][2] = { 0, 1, 2, 3 };

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				printf("%d\n", Array[i][j]);

	}

	{
		// ** 3���� �迭 �� �ʱ�ȭ
		int Array[][3][4] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 6; ++k)
				printf("%02d\n", Array[i][j][k]);
	}

	printf("\n");
	;
	// ** duble pointer
	{
		int Number = 10;
		int* pNum = &Number;

		int** ppNum = &pNum;

		// �ʱ�ȭ
		pNum = nullptr;

		// ���쳪���� �ʱ�ȭ
		free(pNum);
		*ppNum = nullptr;
		ppNum = nullptr;

		if (ppNum != nullptr)
		{
			printf("%p\n", ppNum);
			printf("%p\n", *ppNum);
			printf("%d\n", **ppNum);
		}


	}
	return 0;
}