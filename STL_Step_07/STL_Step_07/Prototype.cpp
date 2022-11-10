#include "Prototype.h"
#include "ObjectPool.h"



Prototype::Prototype()
{

}

Prototype::~Prototype()
{

}

void Prototype::Initialize()
{
	INFO Info = INFO(0, 0, 0);

	{
		Object* Obj = (new Alatreon)->Initialize(Info);
		ProtoTypeObject[Obj->GetKey()] = Obj;
	}
}

bool Prototype::AddProtoTypeObject(Object* object)
{
	map<string, Object*>::iterator iter = ProtoTypeObject.find(object->GetKey());

	if (iter == ProtoTypeObject.end())
	{
		cout << "Message" << endl;
		return false;
	}

	ProtoTypeObject.insert(make_pair(object->GetKey(), object));
	return true;
}

Object* Prototype::findObject(string key)
{
	map<string, Object*>::iterator iter = ProtoTypeObject.find(key);

	if (iter == ProtoTypeObject.end())
		return nullptr;

	return iter->second;
}