#pragma once

class Object
{
private:
	// ** ���� ����
public:
	// ** �ʱ�ȭ
	virtual void Initialize();

	// ** ����
	virtual void Progress();

	// ** ����
	virtual void Render();

	// ** ����
	virtual 
		void Release();
};

