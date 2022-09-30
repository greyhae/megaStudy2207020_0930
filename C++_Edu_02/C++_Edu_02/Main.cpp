#include <iostream>

using namespace std;

// ** inline = Ű����
/*
	// ��� ��)
	//inline (������Ÿ��)(�Լ��̸�)()

	inline int FunctionName()
	{
		�Լ��� inline Ű���尡 �پ��ִٸ� �� �Լ��� �켱ó�� ���.
		��Ȳ�� ���� �켱ó�� ��󿡼� ���ܵ� ���� �ִ�.
		���ܶ�°� ���� ���ܰ� �ƴ϶� ���� ������ �и� �� �ִٴ� ��
	}
*/



// ** ������
// ** ���� ������
// ** �Ҹ���

struct Vector2
{
	float x, y;

	// ** ������
	Vector2() : x(0), y(0) {};

	// ** ���� ������
	Vector2(float _x, float _y) : x(_x), y(_y) {};
};

class Transform
{
private:// ** �����
	Vector2 Position;
protected:// ** ��Ӱ��� ����

// ** public �� ��ü �ѹ��� ����ص� ���ڸ� ������ ������ ���� ������ ����� ��! - public ������ ����� ����ص� ũ�� ������ �� ����
public:// ** ����
	float x, y;// ** ��� ���� (class �ȿ� �ִ� �����. class �Լ����� �ִ� ������ �ش� �ȵ�)

public:
	void Output()
	{
		//cout << "Output" << endl;
		cout << "x : " << Position.x << endl;
		cout << "y : " << Position.x << endl;
	}
public:
	// ** ������ ���� �ڵ����� ȣ���� �Ǵ� �Լ�
	// ** ����ڰ� ���� �������� �ʴ��� �⺻ �����ڰ� ȣ���.
	Transform() :x(0), y(0), Position(Vector2(0.0f, 0.0f))
	{
		cout << "������" << endl;
	}

	// ** ���� �����ڴ� ���� ȣ���ؾ߸� ȣ���
	// ** ���� �����ڴ� �Ű�����(�Ķ����)�� �ش��ϴ� �������� �Ű������� ������ �ڷ����� Ÿ������ ���еǾ�,
	// ** �������� ���� �����ڸ� ������ �� �ִ�.
	Transform(float _x, float _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "���� ������ : float _x, float _y" << endl;
	}

	Transform(int _x, int _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "���� ������ : int _x, int _y" << endl;
	}

	Transform(float _x, int _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "���� ������ : float _x, int _y" << endl;
	}

	// ** �Ҹ�Ǳ� ������ �ڵ����� ȣ���� �Ǵ� �Լ�
	// ** ����ڰ� ���� �������� �ʴ��� �⺻ �Ҹ��ڰ� ȣ���.
	~Transform()
	{
		cout << "�Ҹ���" << endl;
	}
};

class MyEmpty
{
private:
	int number;
public:
	//�ζ��� �Լ�
	void Output()
	{

	}
};

/*
void MyEmpty::Output()
{
	cout << number << endl;
}
*/

	int main(void)
{
		// ** ���� ������ ȣ��
		Transform t = Transform(0.0f, 0.0f);
		//Transform t = Transform();
		t.Output();

		cout << "���α׷��� ����˴ϴ�." << endl;

		return 0;

}