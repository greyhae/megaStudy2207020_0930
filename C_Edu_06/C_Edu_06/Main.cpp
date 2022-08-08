/*
* Chapter 06 : while��, for��, do ~ while��
*/

#include <stdio.h>

int main(void)
{

	{
		// ** �ݺ��� while

		// ** ������ ���ѷ��� �����϶�
		while (true)
		{
			// ** Ż���� �� �ִ� ��Ұ� �ʿ��ϴ�.
			if (true)
				break;
		}

	}

	{
		// ** ���� Ƚ����ŭ �ݺ��ؾ��� ��...

		int i = 0; // �ʱ⹮

		while (i < 10) // ���ǹ�
		{
			printf("while �ݺ��� %d\n", i + 1);
			i++; // ������
		}

		// ** �ʱ⹮, ���ǹ�, ������ �� ������ ��Ұ� �ʿ��ϴ�.

		printf("\n");
	}

	{
		// �ݺ��� for

		// ** for���� ���ѷ��� �����϶�
		for (; true;)
		{
			printf("for �ݺ���\n");

			// ** Ż���� �� �ִ� ��Ұ� �ʿ��ϴ�.
			if (true)
				break;
		}

		// ** ������ Ƚ���� ���س��� �ݺ� �ؾ��ϴ� �ܿ�
		// for(�ʱ⹮; ���ǹ�; ������)
		// ** �ʱ⹮, ���ǹ�, ������ �� ������ ��Ұ� �ʿ��ϴ�.
		// ��������(i++)���� ��������(++i)�� ������ 2�� ���� �� ����.
		for (int i = 0; i < 10; ++i)
		{
			printf("for �ݺ��� %d\n", i + 1);
		}

		printf("\n");
	}

	{
		do
		{
			// ** ���� 1ȸ�� �ݵ�� �����
			printf("���ʿ� �ѹ��� �����");
			break;

			// ** �� �Ŀ� ������ Ȯ���ϰ� ������ true�� ��� �ݺ�
		} while (false);
		printf("\n");
	}

	// ** �ݺ����� �ߺ� ���
	// [������]
	{
		int x, y;

		printf_s("���۴�/���� �Է� : ");
		scanf_s("%d %d", &x, &y);
		for (int i = x; i < y + 1; ++i)
		{
			for (int j = 2; j < 10; ++j)
			{
				/*
				if ((j % 2 == 1)) {
					continue;
				}*/
				//if (i % 2 || !(j % 2))
					//continue;

				//if (i % 2 && !(j % 2))
					printf_s("%d x %d = %d\n", i, j, i * j);
				
			}
			printf("\n");
		}
		printf("\n");
	}

	{
		int i, j;
		
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("*");
			}
			printf("\n");
		}

	}


	return 0;
}
