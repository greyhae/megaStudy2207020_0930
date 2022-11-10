#pragma once
#include "Object.h"

class Alatreon : public Object
{

public:
	virtual Object* Initialize(const INFO& _Info)override);
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void OnDestroy(Object* pObj)override;
public:
	virtual Object* Clone()override
	{
		return new Alatreon(*this);
	}
public:
	Alatreon();
	Alatreon(INFO _Info) : Info(_Info);
	virtual ~Alatreon();
};

