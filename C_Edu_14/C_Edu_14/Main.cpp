/*
	Chapter 14
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	{
		int Num = 1;
		switch (Num)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		}
	}
	*/

	{
		// ** 열거형 : 정수, 상수
		enum {
			AAA, // 0
			BBB, // 1
			CCC, // 2
			DDD = 10, // 10
			EEE, // 11
			FFF // 12
		};
	}

	{
		struct Object
		{
			char* Name;
			int Lev;
		};

		// ** 열거형의 이름을 붙임.
		enum ObjectID
		{
			PLAYER,
			ENEMY,
			BULLET,
			BOSS,
			IETEM,
			MAX,
		};

		Object ObjectList[MAX];

		ObjectList[PLAYER].Name = (char*)"Player";
		ObjectList[PLAYER].Lev = 10;

		ObjectList[ENEMY].Name = (char*)"Enmy";
		ObjectList[ENEMY].Lev = 5;

		ObjectList[BULLET].Name = (char*)"Bullet";
		ObjectList[BULLET].Lev = 10;

		ObjectList[BOSS].Name = (char*)"Boss";
		ObjectList[BOSS].Lev = 0;

		for (int i = 0; i < MAX; ++i)
		{
			printf("%s의 레벨은 : %d\n",
				ObjectList[i].Name,
				ObjectList[i].Lev);
		}
		printf("\n");
	}

	{
		// ** 열거형의 이름을 붙임.
		enum class SceneID
		{
			LOGO,
			MENU,
			STAGE,
			EXIT,
		};

		SceneID StateID = SceneID::LOGO;
		while(true)
		{ 
			// ** 콘솔 버퍼 청소
			// sysstem("cls");
			switch (StateID)
			{
			case SceneID::LOGO:
				printf("LOGO\n");
				StateID = SceneID::MENU;
				break;
			case SceneID::MENU:
				printf("MENU\n");
				StateID = SceneID::STAGE;
				break;
			case SceneID::STAGE:
				printf("STAGE\n");
				StateID = SceneID::EXIT;
				break;
			case SceneID::EXIT:
				exit(0);
				break;
			}
		}
	}

	{
		{
			struct Student
			{
				char* Name;
				int KorScore;
				int EngSCore;
				int MathScore;
			};

			// ** 타입을 재정의
			typedef Student STD;

			STD Stds;

			Stds.Name = (char*)"홍길동";
			Stds.KorScore = 100;
			Stds.EngSCore = 100;
			Stds.MathScore = 100;
		}

		{
			typedef int INT;
			INT Number = 10;

			printf("%d\n", Number);
		}

		{
			// ** 구조체를 만들면서 이름을 정의할 수 있음
			typedef struct Student
			{
				char* Name;
				int KorScore;
				int EngSCore;
				int MathScore;
			};
		}

		{
			// ** 여허 형태로 재정의 가능
			typedef struct Student
			{
				char* Name;
				int KorScore;
				int EngSCore;
				int MathScore;
			}STD1, STD2, STD3, *PSTD;
		}
	}


	// ** 
	typedef struct Student
	{
		char* Name;
		int KorScore;
		int EngSCore;
		int MathScore;
	}STD1, STD2, STD3, *PSTD, STD;

	PSTD Test = (PSTD)malloc(sizeof(STD));
	

	return 0;
}
