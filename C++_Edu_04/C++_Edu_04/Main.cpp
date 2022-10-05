#include <iostream>

using namespace std;

// ** namespace

// ** 상속 : 계층구조 (다이몬드형, W형 상속 구조는 하지말것!)
// ** 추상성
//    - 최상위 클래스 객체가 추상성
// ** 다양성

// ** 가상함수 & 순수가상함수 : 최상위 클래스인 추상성 클래스에 기능이 없는 가상함수
// ** 오버로딩 & 오버라이딩
// ** 연산자 오버로딩

class Parent
{

};

class Child : public Parent
{

};

// ** 최상위 클래스
class A
{
	// ** 완전한 정보 은닉 상태
private:

	// ** 상속관계에서만 정보 공개 상태, 상속이 아닌 경우에는 비공개
	// ** 상속 : public
	// ** 비 상속 : private
protected:
	string Name;
	int Age;

	// ** 완전한 정보 공개 상태
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

// ** is-a . has-a 관계

// 상속형태 class 자식 함수명 : public 상속받을 부모 함수명(복수형은 ,로 해서 추가)
class B : public A
{
protected:
	int Age;
public:
	void Initialize()
	{
		Name = "홍길동";
		Age = 32;
	}
};

class C : public A
{
public:
	void Initialize()
	{
		Name = "임꺽정";
	}

};

int main(void)
{
	B b;
	b.Initialize();
	b.Render();


	return 0;

}