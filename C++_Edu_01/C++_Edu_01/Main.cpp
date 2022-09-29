//#include <stdio.h>

// ** c++ 에서 사용하는 input과 optput의 표준
#include <iostream>
#include <string>

/* 
	[ 객체지향의 특징 5가지 ]

	1. 정보은닉
	2. 캡슐화
	3. 추상화
	4. 상속
	5. 다양성
*/

const float PI = 3.141592f;
// ** 심볼릭 상수 = PI;
// ** 리터럴 상수 = 3.141592ㄹ;

// ** pointer const의 사용 예시
const char* const FileName = "../Data/image.png";
// ** 문자열은 string으로 사용 가능
const std::string FileName = "../Data/image.png";

class AAA
{
public:
	//static 상수는 기본적으로 초기화 되어 있음
	static const int MAX;
};

// ** namespace = ::
// ->  :: 앞에는 namespace 명  :: 뒤에는 데이터 값

// ** namespace 명을 다르게 사용해서 함수명이나 변수 등 중복 사용 가능
namespace AAA
{

	void Output()
	{
		//cout : 콘솔(c)로 내보내기
		//endl : 줄바꿈 -> "AAA\n" = "AAA" << std::endl;
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
	// ** std 시작되지만 언급되어 있는 목록만 생략 가능

	using std::cout;
	using std::endl;
	usint std::cin;
*/

// ** std 시작되는 namespace 는 모두 생략 가능
using namespace std;




int main(void)
{
	int Number = 0;

	// ** 입력
	cin >> Number;

	// ** 출력
	//std::cout << "Hello World!!" << std::endl;
	cout << "Hello World!!" << endl;

	return 0;
}