#pragma once
#include "Object.h"

class Teacher : public Object
{
public:
	void Initialize() {}
public:
	Teacher() {}
	Teacher(Info _info) : Object(_info) {}
};