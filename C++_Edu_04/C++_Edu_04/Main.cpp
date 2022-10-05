#include <iostream>

using namespace std;

// ** namespace

// ** ��� : �������� (���̸����, W�� ��� ������ ��������!)
// ** �߻�
//    - �ֻ��� Ŭ���� ��ü�� �߻�
// ** �پ缺

// ** �����Լ� & ���������Լ� : �ֻ��� Ŭ������ �߻� Ŭ������ ����� ���� �����Լ�
// ** �����ε� & �������̵�
// ** ������ �����ε�

class Parent
{

};

class Child : public Parent
{

};

// ** �ֻ��� Ŭ����
class A
{
	// ** ������ ���� ���� ����
private:

	// ** ��Ӱ��迡���� ���� ���� ����, ����� �ƴ� ��쿡�� �����
	// ** ��� : public
	// ** �� ��� : private
protected:
	string Name;
	int Age;

	// ** ������ ���� ���� ����
public:
	void Initialize()
	{
		Name = "";
		Age = 0;
	}

	void Render()
	{
		cout << Name << endl;
		cout << Age << endl;
	}
};

// ** is-a . has-a ����

// ������� class �ڽ� �Լ��� : public ��ӹ��� �θ� �Լ���(�������� ,�� �ؼ� �߰�)
class B : public A
{
protected:
	int Age;
public:
	void Initialize()
	{
		Name = "ȫ�浿";
		Age = 32;
	}
};

class C : public A
{
public:
	void Initialize()
	{
		Name = "�Ӳ���";
	}

};

int main(void)
{
	B b;
	b.Initialize();
	b.Render();


	return 0;

}