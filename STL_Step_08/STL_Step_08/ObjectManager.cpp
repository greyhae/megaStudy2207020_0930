#include "ObjectManager.h"
#include "ObjectPool.h"
#include "ObjectPool.h"

ObjectManager* ObjectManager::Instance = nullptr;


ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::DisableFormEnable()
{
	// ** null이 있는 경우는 try ~ catch 문 사용
	// ** 지금은 null이 없다고 가장

	auto iter = EnableList->find("Player");
	ErrorMessage(__LINE__);

	// 생성
	Object* pObj = ObjectPool::GetInstance()->Pop("Player");

	if (iter == EnableList->end())
	{
		list<Object*> temp;
		for (int i = 0; i < 5; ++i)
		{
			temp.push_back(ProtoObject->Clone());
			DisableList.insert(make_pair(_key, temp));
		};

	}
	else
		iter->second.push_back(pObj);
	

	EnableList->Insert(make_pair(pObj->GetKey(), pObj));
}

void ObjectManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			
		}
	}
}
