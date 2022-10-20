#pragma once
#include "Object.h"

class Child : public Object
{
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Child();
	// ** 부모한테 virtual 사용. 자식에서는 꼭 사용안해도 됨
	// ** 부모한테 virtual 사용 안하고 자식에서 virtual 사용하면 안됨
	virtual ~Child();
};


