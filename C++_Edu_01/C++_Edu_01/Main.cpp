//#include <stdio.h>

// ** c++ ���� ����ϴ� input�� optput�� ǥ��
#include <iostream>
#include <string>

/* 
	[ ��ü������ Ư¡ 5���� ]

	1. ��������
	2. ĸ��ȭ
	3. �߻�ȭ
	4. ���
	5. �پ缺
*/

const float PI = 3.141592f;
// ** �ɺ��� ��� = PI;
// ** ���ͷ� ��� = 3.141592��;

// ** pointer const�� ��� ����
const char* const FileName = "../Data/image.png";
// ** ���ڿ��� string���� ��� ����
const std::string FileName = "../Data/image.png";

class AAA
{
public:
	//static ����� �⺻������ �ʱ�ȭ �Ǿ� ����
	static const int MAX;
};

// ** namespace = ::
// ->  :: �տ��� namespace ��  :: �ڿ��� ������ ��

// ** namespace ���� �ٸ��� ����ؼ� �Լ����̳� ���� �� �ߺ� ��� ����
namespace AAA
{

	void Output()
	{
		//cout : �ܼ�(c)�� ��������
		//endl : �ٹٲ� -> "AAA\n" = "AAA" << std::endl;
		//std::cout << "AAA\n"
		std::cout << "AAA" << std::endl;
	}
}

namespace BBB
{
	void Output()
	{
		std::cout << "BBB" << std::endl;
	}
}

using BBB::Output;

/*
	// ** std ���۵����� ��޵Ǿ� �ִ� ��ϸ� ���� ����

	using std::cout;
	using std::endl;
	usint std::cin;
*/

// ** std ���۵Ǵ� namespace �� ��� ���� ����
using namespace std;




int main(void)
{
	int Number = 0;

	// ** �Է�
	cin >> Number;

	// ** ���
	//std::cout << "Hello World!!" << std::endl;
	cout << "Hello World!!" << endl;

	return 0;
}