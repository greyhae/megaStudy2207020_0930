#include <iostream>

using namespace std;

class Object
{
public:
	int Number;

	Object() : Number(0) {}

	Object(int _number) : Number(_number)
	{

	}
};

int main(void)
{
	// ** [C ��Ÿ��]
	//Object* Obj = (Object*)malloc(sizeof(Object));
	//Object* Obj = (Object*)malloc(sizeof(Object) * count);
	
	/*
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << Obj[i][j]->Number << endl;
		}
	}
	*/

	//free(Obj);
	

	// ** [C++ ��Ÿ��]
	//Object* Obj = new Object[sizeof(Object) * count];
	//Object* Obj = new Object;
	
	// ** ������ 1���� �迭
	//Object* Obj = new Object[sizeof(Object) * 5];

	// ** ������ 2���� �迭 (������ �迭)
	//Object (*Obj)[10] = new Object[5][10];
	Object (*Obj)[5][10];

	/*
	for (Object* o = (*Obj); o != nullptr; o++)
	{
		
	}
	*/

	/*
	for (auto o = Obj; o != nullptr; o++)
	{

	}
	*/

	/*
	for(Object* o : Obj)
	{ 
		cout << o->Number << endl;
	}
	*/



	int numbers[5];

	for (int i : numbers)
	{
		cout << i << endl;
	}
	

	
	//delete Obj;

	// ** �����͸� �迭ó�� �Ǵ� �迭�� ������ó�� ����� �� ������, ���� ������ ���� �ڷ����� ���� �迭�� �����ų� �ϴ� ������ �߻��� �� �����Ƿ�, �ڷ����� �°� ó������� �Ѵ�.
	delete[] Obj;

	// ** �������� ����
	/*
	int Number = 10;
	void* value = &Number;

	cout << value << endl;

	int* num = (int*)value;
	cout << *num << endl;
	*/


	return 0;
}