/*
	Chapter 17
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main(void)
{
	{
		// ** 개별 초기화 항법
		char Array[10] = {'A','B','C','D','E','F','G','H','I','J'};

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);

		}
		printf("\n");
		printf("%s\n\n", Array);
	}

	{
		// ** 문자열 초기화 방법
		char Array[10] = { "ABCDEFGHI" };

		// ** 문자열 초기화 시에는 마지막 문자열이 끝나는 지점에 NULL 값이 들어가야 한다.
		// ** NULL 값의 공간이 1byte 만큼 필요하므로 개별초기화 방법보다 공간이 1 더 필요함.

		{
			// ** 널 문자
			NULL;
			//'\0';
		}

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);

		}
		printf("\n");
		printf("%s\n\n", Array);
	}


	{
		//(int* Pointer = &int)
		//(short* Pointer = &short)
		//(long* Pointer = &long)
		//(char* Pointer = &char)

		// ** 문자 배열 초기화
		char Buffer[] = { 'A','B','C','D','E','F','G','H','I','J', NULL };

		// ** Buffer의 주소를 str1 로 대입
		char* str1 = Buffer;

		// ** str1 변수가 받은 주소를 str2에 동일하게 넘겨준다.
		char* str2 = str1;

		// 이때 str1d의 주소에 있는 내용을 변경하게 된다면
		str1[3] = 'A';

		// ** str2도 같은 주소를 참조받았기 때문에 내용이 함께 변경 되는것을 알 수있다.
		printf("str2 : %s\n", str2);

		int* Pointer = (int*)malloc(sizeof(int));
	}

	{
		// ** 파일 입출력 
		// ** 파일 저장하기

		FILE* pf = fopen("../Datas/Data.txt", "w");

		if (pf == NULL)
			printf("파일을 열지 못했습니다.\n");
		else
		{ 
			int Age = 32;
			char Name[128] = "홍길동";

			int n = fscanf(pf, "%d", &Age);
			
			fgets(Name, sizeof(Name), pf);
			fprintf(pf, "%s : %d", Name, Age);

			fclose(pf);
		}

	}

	{
		// ** 파일 불러오기

		FILE* pf = fopen("../Datas/Data.txt", "r");

		int Age[20];
		char Name[128];

		int Count = 0;

		while (fgetc(pf) != NULL)
		{
			fgets(Name, sizeof(Name), pf);

			printf("%s\n", Name);

			fflush(pf);

		}
	}

	return 0;
}