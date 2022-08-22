/*
	Chapter 16 : 전처리 지시자
*/

#include "Test.cpp"


struct Object
{
	char* Name;
	int Age;
};

Object* CreateObject(bool _b);

int Count = 0;


int main(void)
{
	printf("%f\n", PI);
	/*{
		Object* o = CreateObject(false);

		if (!o) // ** Err 발생!!
		{
			ERRMSG("경로");
			exit(0);
		}
	}*/

	{
		printf("두 수의 합은 : %d\n", SUM(10, 20));
		printf("두 수의 곱은 : %d\n", MUL(10, 20));
	}

	
//#if
	// ** 실행할 코드와 실행시키지 않을 코드를 구분
//#endif
/*
#ifdef 1
	
#endif // !1

#define DEBUG

#ifdef DEBUG
	printf("DEBUG 정의되었습니다.\n");
#else
	printf("DEBUG 정의되지 않았습니다.\n");
#endif
*/
	Count = 100;

	Func();

	return 0;
}


Object* CreateObject(bool _b)
{
	Object* Obj = nullptr;

	if (_b)
		Obj = (Object*)malloc(sizeof(Object));

	return Obj;
}