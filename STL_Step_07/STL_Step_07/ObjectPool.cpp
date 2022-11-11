#include "ObjectPool.h"
#include "Alatreon.h"
#include "Prototype.h"

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

list<Object*>* ObjectPool::GetDisableObjectList(string key)
{
	// ** ������Ʈ�� ����ִ� ����Ʈ�� �����ϴ��� Ž��
	auto iter = DisableList.find(key);

	// ** �����Ѵٸ� ����Ʈ�� ��ȯ�ϰ�
	if (iter != DisableList.end())
		return &iter->second;

	// ** �׷��� �ʴٸ� nullptr�� ��ȯ�Ѵ�.
	return nullptr;
}

void ObjectPool::AddObjectList(Object* pObj, ListType type)
{
	map<string, list<Object*>> mapList;

	if (type == ListType::Enable)
		mapList = EnableList;
	else
		mapList = DisableList;

	
	// ** ������Ʈ�� ��ܾ� �� ������ �̹� �����ϴ��� Ž��
	auto iter = mapList.find(pObj->GetKey());

	// ** �������� �ʴ´ٸ� ���ο� ������ Ȯ���ϰ� �߰��Ѵ�.
	if (iter == mapList.end())
	{
		list<Object*> temp;
		temp.push_back(pObj);
		mapList.insert(make_pair(pObj->GetKey(), temp));
	}
	else // ** �����Ѵٸ� �� �ش� ��ġ�� ��ü�� �ִ´�.
		iter->second.push_back(pObj);
}

void ObjectPool::CreateObjectList()
{
	/*
	list<Object*>* plist = GetDesableObjectList("Alatreon");
	if (plist == nullptr)
	{
	}
	else
	{
	}
	*/
	Object* pObj = Prototype::GetInstance()->findObject("Alatreon");

	for (int i = 0; i < 4; ++i)
	{
		/*
		Object* pObj = new Alatreon();
		pObj->Start();
		AddObjectList(pObj, ListType::Disable);
		*/

		if (pObj != nullptr)
			AddObjectList(pObj->Clone(), ListType::Disable);
		else
			throw "���� ����";
	}
	AddObjectList(pObj->Clone());

	/*
	Object* pObj = new Alatreon();
	pObj->Start();

	AddObjectList(pObj);
	*/
}
void ObjectPool::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int result = (*iter2)->Update();

			if (result == 1)
			{
				AddObjectList((*iter2), ListType::Disable);
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
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