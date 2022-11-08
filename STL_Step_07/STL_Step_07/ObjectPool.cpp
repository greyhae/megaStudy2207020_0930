#include "ObjectPool.h"
#include "Alatreon.h"

ObjectPool* ObjectPool::Instance = nullptr;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

ObjectPool::list<Object*>* findMaplist(string key, map<string, list<Object*>*>* mapList)
{
	// ** ������Ʈ�� ����ִ� ����Ʈ�� �����ϴ��� Ž��
	auto iter = mapList->find(key);

	// ** �����Ѵٸ� ����Ʈ�� ��ȯ�ϰ�
	if (iter != mapList->end())
		return iter->second;

	// ** �׷��� �ʴٸ� nullptr�� ��ȯ�Ѵ�.
	return nullptr;
}

void ObjectPool::addMapObject(Object* pObj, map<string, list<Object*>*>* mapList)
{
	// ** ������Ʈ�� ��ܾ� �� ������ �̹� �����ϴ��� Ž��
	auto iter = mapList->find(pObj->GetKey());

	// ** �������� �ʴ´ٸ� ���ο� ������ Ȯ���ϰ� �߰��Ѵ�.
	if (iter == mapList->end())
	{
		list<Object*>* temp = new list<Object*>();
		temp->push_back(pObj);
		mapList->insert(make_pair(pObj->GetKey(), temp);
	}
}

void ObjectPool::Update()
{

}

void ObjectPool::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		cout << "[Enable]" << endl;
		cout << " [" << iter->first << "] " << endl;

		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			cout << (*iter2)->GetKey() << endl;
		}
	}
}