#include "ObjectPool.h"
#include "Prototype.h"
#include "Object.h"

// ** 생성 / 읽기,쓰기(덮어쓰기, 변경)

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{
	Release();
}

bool ObjectPool::CreateObject(string _key)
{
	// 복사생성
	Object* ProtoObject = Prototype::GetInstance()->FindObject("Player");
	//FALIED(ProtoObject, __LINE__);

	//Counts.find(_key)->second

	if (ProtoObject != nullptr)
	{
		auto iter = DisableList.find(_key);
		if (iter == DisableList.end())
		{
			Counts.insert(make_pair(_key, 0));

			list<Object*> temp;
			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = ProtoObject->Clone();
				pObj->SetSpace(&temp);
				//pObj->SetSpace(Counts.find);
				temp.push_back(pObj);
			}
			DisableList.insert(make_pair(_key, temp));
		}
		else
		{
			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = ProtoObject->Clone();
				pObj->SetSpace(&temp);
				temp.push_back(pObj);
			}
		}
		return true;
	}
	return false;
}

list<Object*>* ObjectPool::FindObjectList(string _key)
{
	return nullptr;
}


Object* ObjectPool::Insert(string _key)
{
	START;
	auto iter = FindObjectList(_key);


	if (iter == nullptr)
	{
		CREAT;
		if (CreateObject(_key))
			ErrorMessage(__LIME__);
			goto START;
	}
	else
	{
		if (iter->empty())
		{
			Object* pObj = iter->back();
			iter->pop_back();
			return pObj;
		}
		else
			goto CREAT;
	}

}

void ObjectPool::Erase(Object* _Obj)
{
	auto iter = _Obj->GetInstance();

	// 이 부분 문제 발생
	for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
	{
		if(_Obj)

	}
	//auto iter = EnableList.find(_Obj->GetKey());

	
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