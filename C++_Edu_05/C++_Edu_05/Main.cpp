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
	Parent* ObjectList[2] = new Child1;

	// ** ���� Parent �� �Լ��� �����ϱ� �ʱ� ������
	// ** ����ȯ�� ���� Child1 �� Ŭ������ �ִ� �Լ��� ȣ���Ͽ��� �Ѵ�.
	((Child1*)pP1)->Initialize();
	((Child1*)pP1)->Render();

	// ** Child2 �� ����
	Parent* pP2 = new Child2;

	// ** Child1 �� �Լ��� ȣ���Ͽ� ���� �ʱ�ȭ.
	((Child1*)pP2)->Initialize();

	// ** �Ӳ����� ���;� ������ ȫ�浿�� ���´�.
	((Child2*)pP2)->Render();

	// ** �θ� ������ ������ Ÿ���� ��쿡�� �ڽ� Ŭ������ ����ȯ�� �����ϴ�.
	// ** �ٸ� �����ϰ� �ִ� �����ͱ��� ���� �Ǵ� ���� �ƴϱ� ������
	// ** �������� ���� ����ϰų� ����� ��� �����ϰ� ��������.

	//for(int i = 0; i)

	return 0;

}