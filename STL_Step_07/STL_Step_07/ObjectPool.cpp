#include "ObjectPool.h"
#include "Alatreon.h"

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

list<Object*>* ObjectPool::GetDisableObjectList(string key)
{
	// ** 오브젝트가 담겨있는 리스트가 존재하는지 탐색
	auto iter = DisableList.find(key);

	// ** 존재한다면 리스트를 반환하고
	if (iter != DisableList.end())
		return iter->second;

	// ** 그렇지 않다면 nullptr을 반환한다.
	return nullptr;
}

void ObjectPool::AddObjectList(Object* pObj, ListType type)
{
	map<string, list<Object*>*>* mapList = nullptr;

	if (type == ListType::Enable)
		mapList = &EnableList;
	else
		mapList = &DisableList;

	
	// ** 오브젝트가 담겨야 할 공간이 이미 존재하느지 탐색
	auto iter = EnableList.find(pObj->GetKey());

	// ** 존재하지 않는다면 새로운 공간을 확보하고 추가한다.
	if (iter == EnableList.end())
	{
		list<Object*>* temp = new list<Object*>();
		temp->push_back(pObj);
		EnableList.insert(make_pair(pObj->GetKey(), temp));
	}
	else // ** 존대한다면 그 해당 위치에 객체를 넣는다.
		iter->second->push_back(pObj);
}

void ObjectPool::CreateObjectList()
{
	//list<Object*>* pList = GetDisableObjectList();
	for (int i = 0; i < 5; ++i)
	{
		Object* pObj = new Alatreon();
		pObj->Start();

		AddObjectList(pObj, ListType::Disable);
	}

	Object* pObj = new Alatreon();
	pObj->Start();
	AddObjectList(pObj);
}
void ObjectPool::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			int result = (*iter2)->Update();

			if (result == 1)
			{
				AddObjectList();
				iter2 = iter->second->erase(iter2);
			}
		}
	}
}

void ObjectPool::Render()
{
	// ** Enable
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		cout << "[Enable]" << endl;
		cout << " [" << iter->first << "] " << endl;

		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			cout << (*iter2)->GetKey() << endl;
	}

	// ** Disable
	for (auto iter = DisableList.begin(); iter != DisableList.end(); ++iter)
	{
		cout << "[Disable]" << endl;
		cout << " [" << iter->first << "] " << endl;

		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			cout << (*iter2)->GetKey() << endl;
	}
}