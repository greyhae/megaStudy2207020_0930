#pragma once
#include "Parent.h"

class Child : public Parent
{
public:
	// ** �������̵� : ��Ӱ��迡���� ��� ����
	// ** �Ȱ��� �̸��� �Լ��� ����� �� � �Լ��� ȣ���ؾ����� ��ȣ�� ���
	// ** �Լ��� ȣ���ϴ� ���
	virtual void Start()override 
	{
		// **�������̵� �Լ�
	}
	virtual void Start(int number)override
	{

	}

	// ** �����ε� : ��Ӱ������ ���� ����� ����
	// ** ���� Ŭ���� ���ο��� ���Ǹ�, �Ȱ��� �̸��� �Լ��� ȣ���ϴ� ���
	// ** �Ű������� ������ ���¿� ���� ȣ��Ǵ� �Լ��� �޶�����.
	virtual void Update(int)
	{
		// **�����ε� �Լ�
	}

	virtual void Update(float)
	{
		// **�����ε� �Լ�
	}
	virtual void Update()
	{

	}
};

