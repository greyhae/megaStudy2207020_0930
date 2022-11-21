#include "ObjectPool.h"
#include "Prototype.h"
// ** 생성 / 읽기,쓰기(덮어쓰기, 변경)

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{
	Release();
}

void ObjectPool::CreateObject(string key)
{

}

Object* ObjectPool::Pop(string _key)
{
	auto iter = DisableList.find(_key);

	START;

	if (iter == DisableList.end())
	{
		// 생성
		Object* ProtoObject = Prototype::GetInstance()->FindObject("Player");

		if (ProtoObject != nullptr)
		{
			list<Object*> temp;
			for (int i = 0; i < 5; ++i)
			{
				temp.push_back(ProtoObject->Clone());
				DisableList.insert(make_pair(_key, temp));
			}
			goto START;

		}
		else
			return nullptr;
	}
	else
	{
		Object* pObj = iter->second.back();
		return iter->second.pop_back();
		retrun pObj;
	}

}

void ObjectPool::Release()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
	}
	DisableList.clear();

	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
	}
	EnableList.clear();
}