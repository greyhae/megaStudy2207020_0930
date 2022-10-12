#pragma once
#include "Headers.h"

class Object;
class MainUpdate
{
private:
	// ** ���� ����
	Object* ObjectList[2];
public:
	// ** �ʱ�ȭ
	void Initialize();

	// ** ����
	void Progress();

	// ** ����
	void Render();

	// ** ����
	void Release();

public:
	MainUpdate();
	~MainUpdate();
};
