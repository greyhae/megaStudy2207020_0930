#pragma once
#include "Headers.h"

class Object
{
private:
	// ** ���� ����
public:
	// ** �ʱ�ȭ
	virtual void Initialize()PURE;

	// ** ����
	virtual void Progress()PURE;

	// ** ����
	virtual void Render()PURE;

	// ** ����
	virtual void Release()PURE;
};

