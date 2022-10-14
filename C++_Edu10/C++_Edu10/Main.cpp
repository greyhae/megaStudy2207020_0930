#include "Headers.h"
#include "Operator.h"

class Copy
{
public:
	char* name;
public:
	Copy operator=(Copy& ref)
	{
		//char* name = new char[strlen(ref.name) + 1];
		//strcpy(name, ref.name);

		//return Copy(name);
	}
public:
	Copy() : name(nullptr) {}
	Copy(Copy* pCopy)
	{
		this->name = new char[strlen(pCopy->name)];
		strcpy(this->name, pCopy->name);
	}
};

int main(void)
{
	// ** �Ǽ� ����

	// ��ȣ		������			������ : n��
	// 0		000000000		00000000000000000000000

	// 128. 625 =>
	// ** ���� �Ҽ��� : �� �̻� ���� �ʴ� ���
	//		������					�Ǽ���
	// 000000000 100000000 . 101000000 000000000

	// 1.0000000101 �� 7��
	// 7 + 127

	// �ε� �Ҽ���
	// 0		10000110		00000001010000000000000

	// ======================================================== //

	// ** ������ �����ε�
	/*
	Operator o;
	o.setAge(32);
	o.setName((char*)"ȫ�浿");

	o.rendor();
	*/

	// ======================================================== //

	// ** ���� ���� & ���� ����

	// ** c1�� ����
	Copy* c1 = new Copy;

	// ** c1 �� name �� �̸��� �ʱ�ȭ
	c1->name = (char*)"ȫ�浿";

	// ** c2 �� c1 �� ����
	//Copy* c2 (c1); // �ȵ�
	Copy* c2 = new Copy(c1); // ��

	// ** c1 �� �����Ǳ� ���� c2 �� name �� ���� ��µȴ�.
	//cout << c2 << endl;

	// ** c1�� ����
	delete c1;

	// ** c2�� name�� ���
	cout << c2->name << endl; // ���� ���;
	


	return 0;
}