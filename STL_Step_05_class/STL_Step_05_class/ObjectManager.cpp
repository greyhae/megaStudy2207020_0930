#include "ObjectManager.h"

void ObjectManager::AddObject(Object* _pObj)
{
	map<int, list<Object*>>::iterator iter = Objects.find(_pObj->GetKey());

	if (iter == Objects.end())
	{
		list<Object*> temp;
		temp.push_back(_pObj);

		Objects.insert(make_pair(_pObj->GetKey(), temp));
	}
	else
		iter->second.push_back(_pObj);
}

void ObjectManager::Render()
{
	for (auto iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		cout << iter->first << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
	}
}

ObjectManager::ObjectManager() 
{

};

ObjectManager::~ObjectManager() 
{

};

