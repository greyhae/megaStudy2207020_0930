#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	string Key;
public:
	virtual Object* Initailize()PURE;
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;
public:
	string GetKey() { return Key; }
public:
	Object();
	Object(const Transform _Info) : Info(_Info) {};
	virtual ~Object();
};

