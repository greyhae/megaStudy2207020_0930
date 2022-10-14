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
	// ** 실수 연산

	// 부호		지수부			가수부 : n승
	// 0		000000000		00000000000000000000000

	// 128. 625 =>
	// ** 고정 소수점 : 더 이상 쓰지 않는 방법
	//		정수부					실수부
	// 000000000 100000000 . 101000000 000000000

	// 1.0000000101 의 7승
	// 7 + 127

	// 부동 소수점
	// 0		10000110		00000001010000000000000

	// ======================================================== //

	// ** 연산자 오버로딩
	/*
	Operator o;
	o.setAge(32);
	o.setName((char*)"홍길동");

	o.rendor();
	*/

	// ======================================================== //

	// ** 깊은 복사 & 얕은 복사

	// ** c1을 생성
	Copy* c1 = new Copy;

	// ** c1 의 name 에 이름을 초기화
	c1->name = (char*)"홍길동";

	// ** c2 에 c1 을 복사
	//Copy* c2 (c1); // 안됨
	Copy* c2 = new Copy(c1); // 됨

	// ** c1 이 삭제되기 전에 c2 의 name 은 정상 출력된다.
	//cout << c2 << endl;

	// ** c1을 삭제
	delete c1;

	// ** c2의 name을 출력
	cout << c2->name << endl; // 정상 출력;
	


	return 0;
}