#pragma once
#include "Headers.h"

class Scene
{
public:
	// ** �ֻ��� Ŭ������ �����Լ��� PURE
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};
