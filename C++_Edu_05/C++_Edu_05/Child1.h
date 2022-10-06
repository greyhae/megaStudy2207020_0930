#pragma once
#include "Parent.h"

class Child1 : public Parent
{
public:
	virtual void Initialize()override;
	virtual void Render()override;
};

