#include "Headers.h"
#include "ObjectManager.h"
#include "Student.h"


int main(void)
{

	for (int i = 0; i < 5; ++i)
	{

		// ** ���� �� �ʱ�ȭ
		srand((unsigned int)GetTickCount64());

		// ** ������Ʈ ����

		// ** �Լ� ��뺸�� ������ ����ؼ� ȣ���ϴ°� �� ȿ����
		//Object* pObj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30)

		Object* pObj = new Student(Info(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30));

		pObj->Initialize();


		// ** ������Ʈ �߰�
		ObjectManager::GetInstance()->AddObject(pObj);


	}

	// ** ���
	ObjectManager::GetInstance()->Render();

	return 0;
}