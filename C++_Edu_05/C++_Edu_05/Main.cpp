#include "Headers.h"

#include "Child1.h"
#include "Child2.h"


// ** ��� 
//  ** ������ Ŭ����, �Լ� ���� ����� �� �ֵ��� ���ش�.
// ** namespace


// ** �߻�
// ** �����Լ� & ���������Լ�

// ** ������
// ** �����ε� & �������̵�
// ** ������ �����ε�


namespace std
{

}



int main(void)
{
	/*
	Parent* pP = new Parent;
	Child* pC = new Child;
	*/

	// ** Number�� int�� ����Ǿ� �ִ�.
	// ** float ���� ����ȯ �ؼ� �شٰ� �ص�,
	// ** Number�� ���´� ���� ������ �ʴ´�.
	int Number = (float)3.141592f;

	// ** Parent* pP1�� ���������̴�.
	// ** new Child1 �� �ؼ� pP1 �� Child1 �� �־��ٰ� �ص�,
	// ** pP1�� Parent* Ÿ���� Child1* Ÿ������ ������� �ʴ´�.
	Parent* ObjectList[2];

	ObjectList[0] = new Child1;

	// ** ���� Parent �� �Լ��� �����ϱ� �ʱ� ������
	// ** ����ȯ�� ���� Child1 �� Ŭ������ �ִ� �Լ��� ȣ���Ͽ��� �Ѵ�.
	//((Child1*)pP1)->Initialize();
	//((Child1*)pP1)->Render();
	ObjectList[0]->Initialize();
	ObjectList[0]->Render();

	// ** Child2 �� ����
	//Parent* pP2 = new Child2;
	ObjectList[1] = new Child2;

	// ** Child1 �� �Լ��� ȣ���Ͽ� ���� �ʱ�ȭ.
	//((Child1*)pP2)->Initialize();
	ObjectList[1]->Initialize();

	// ** �Ӳ����� ���;� ������ ȫ�浿�� ���´�.
	//((Child2*)pP2)->Render();
	ObjectList[1]->Render();

	// ** �θ� ������ ������ Ÿ���� ��쿡�� �ڽ� Ŭ������ ����ȯ�� �����ϴ�.
	// ** �ٸ� �����ϰ� �ִ� �����ͱ��� ���� �Ǵ� ���� �ƴϱ� ������
	// ** �������� ���� ����ϰų� ����� ��� �����ϰ� ��������.

	// ** �ϳ��� ������ Ÿ������ �Ʒ� �ڽ� Ŭ������ �� �� �ִ�.
	// ** �ϰ� ȣ��
	for (int i = 0; i < 2; ++i)
	{
		ObjectList[i]->Render();
	}

	return 0;

}