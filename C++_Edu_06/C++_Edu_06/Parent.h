#pragma once
#include "Header.h"

class Parent
{
protected:
	string Name;

	// ** [�߻� Ŭ���� Ư¡]
	// ** �����ʹ� ������ �� ������ �Լ��� ���� ���� �Լ��θ� ������ �� �ִ�.

	// ** [���� �����Լ��� Ư¡]
	// ** ���� �����Լ��� 1���� ���������, �� Ŭ������ �߻� Ŭ�����θ� ��� �����ϴ�.
	
	// ** [����]
	// ** ���� �����Լ��� 1���� ����� �Ϲ��Լ� ���� �� ��� �Ұ�

public:
	//virtual void Start() = 0;
	//���� �����Լ�
	virtual void Start()PURE;
	virtual void Start(int number)PURE;
};


