#pragma once

#include "Object.h"

class Enemy : public Object
{
private:
	// ** ���� ����
public:
	// ** �ʱ�ȭ
	void Initialize();

	// ** ����
	void Progress();

	// ** ����
	void Render();

	// ** ����
	void Release();
};

