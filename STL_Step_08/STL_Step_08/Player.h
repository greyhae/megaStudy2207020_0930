#pragma once
#include "Object.h"

class Player : public Object
{
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	virtual Object* Clone()override { return new Player(*this); }
public:
	Player();
	Player(const Transform _Info) : Info(_Info) {};
	virtual ~Player();
};

