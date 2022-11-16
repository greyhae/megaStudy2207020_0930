#pragma once
#include "Headers.h"

class Scene
{
public:
	// ** 최상위 클래스는 소멸자가 
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};
