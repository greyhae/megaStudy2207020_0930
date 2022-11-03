#include "Headers.h"
#include "ObjectManager.h"
#include "Student.h"


int main(void)
{

	for (int i = 0; i < 5; ++i)
	{

		// ** 난수 값 초기화
		srand((unsigned int)GetTickCount64());

		// ** 오브젝트 생성

		// ** 함수 사용보다 생성자 사용해서 호출하는게 더 효율적
		//Object* pObj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30)

		Object* pObj = new Student(Info(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30));

		pObj->Initialize();


		// ** 오브젝트 추가
		ObjectManager::GetInstance()->AddObject(pObj);


	}

	// ** 출력
	ObjectManager::GetInstance()->Render();

	return 0;
}