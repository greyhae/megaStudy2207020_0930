#pragma once
#include "MainUpdate.h"



class Object;


class MainUpdate
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
