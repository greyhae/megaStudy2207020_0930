/*
	Chapter 16 : ��ó�� ������
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

		if (!o) // ** Err �߻�!!
		{
			ERRMSG("���");
			exit(0);
		}
	}*/

	{
		printf("�� ���� ���� : %d\n", SUM(10, 20));
		printf("�� ���� ���� : %d\n", MUL(10, 20));
	}

	
//#if
	// ** ������ �ڵ�� �����Ű�� ���� �ڵ带 ����
//#endif
/*
#ifdef 1
	
#endif // !1

#define DEBUG

#ifdef DEBUG
	printf("DEBUG ���ǵǾ����ϴ�.\n");
#else
	printf("DEBUG ���ǵ��� �ʾҽ��ϴ�.\n");
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