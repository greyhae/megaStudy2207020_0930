#include <iostream>

using namespace std;

// ** inline = 키워드
/*
	// 사용 예)
	//inline (데이터타입)(함수이름)()

	inline int FunctionName()
	{
		함수에 inline 키워드가 붙어있다면 그 함수는 우선처리 대상.
		상황에 따라서 우선처리 대상에서 예외될 수도 있다.
		예외라는건 완전 예외가 아니라 실행 순서가 밀릴 수 있다는 뜻
	}
*/



// ** 생성자
// ** 복사 생성자
// ** 소멸자

struct Vector2
{
	float x, y;

	// ** 생성자
	Vector2() : x(0), y(0) {};

	// ** 복사 생성자
	Vector2(float _x, float _y) : x(_x), y(_y) {};
};

class Transform
{
private:// ** 비공개
	Vector2 Position;
protected:// ** 상속간의 공개

// ** public 은 전체 한번만 사용해도 되자만 구역별 구분을 위해 여러개 사용한 것! - public 여러개 만들어 사용해도 크게 문제될 거 없음
public:// ** 공개
	float x, y;// ** 멤버 변수 (class 안에 있는 경우임. class 함수내에 있는 변수는 해당 안됨)

public:
	void Output()
	{
		//cout << "Output" << endl;
		cout << "x : " << Position.x << endl;
		cout << "y : " << Position.x << endl;
	}
public:
	// ** 생성된 직후 자동으로 호출이 되는 함수
	// ** 사용자가 직접 정의하지 않더라도 기본 생성자가 호출됨.
	Transform() :x(0), y(0), Position(Vector2(0.0f, 0.0f))
	{
		cout << "생성자" << endl;
	}

	// ** 복사 생성자는 직접 호출해야만 호출됨
	// ** 복사 생성자는 매개변수(파라미터)에 해당하는 변수들은 매개변수의 갯수와 자료형의 타입으로 구분되어,
	// ** 여러개의 복사 생성자를 정이할 수 있다.
	Transform(float _x, float _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "복사 생성자 : float _x, float _y" << endl;
	}

	Transform(int _x, int _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "복사 생성자 : int _x, int _y" << endl;
	}

	Transform(float _x, int _y) : x(_x), y(_y)
	{
		x = _x;
		y = _y;

		cout << "복사 생성자 : float _x, int _y" << endl;
	}

	// ** 소멸되기 직전에 자동으로 호출이 되는 함수
	// ** 사용자가 직접 정의하지 않더라도 기본 소멸자가 호출됨.
	~Transform()
	{
		cout << "소멸자" << endl;
	}
};

class MyEmpty
{
private:
	int number;
public:
	//인라인 함수
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
		// ** 복사 생성자 호출
		Transform t = Transform(0.0f, 0.0f);
		//Transform t = Transform();
		t.Output();

		cout << "프로그램이 종료됩니다." << endl;

		return 0;

}