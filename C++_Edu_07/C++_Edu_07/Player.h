#pragma once

#include "Object.h"

class Player : public Object
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

