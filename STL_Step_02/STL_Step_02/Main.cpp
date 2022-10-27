#include <iostream>
#include <vector>

using namespace std;

class Object
{
public:
	int Kor;
	int Eng;
	int Math;
};

Object* CreateObject(int _kor, int _eng, int _math)
{
	Object* pObj = new Object;

	pObj->Kor = _kor;
	pObj->Eng = _eng;
	pObj->Math = _math;

	return pObj;
}

int main(void)
{

	// 실습 예제

	
	vector<Object*> Objects;

	// 방법 1
	for (int i = 0; i < 3; ++i)
		Objects.push_back(
			CreateObject(
				i * 10 + 10,
				i * 10 + 10 + 1,
				i * 10 + 10 + 2));

	/*
	// 방법 2
	for (int i = 0; i < 3; ++i)
	{
		Object* pObj = new Object;

		pObj->Kor = i * 10 + 10;
		pObj->Eng = i * 10 + 10 + 1;
		pObj->Math = i * 10 + 10 + 2;

		Objects.push_back(pObj);
	}
	

	for (auto Element : Objects)
	{
		cout << "국어 점수 : " << Element->Kor << endl;
		cout << "영어 점수 : " << Element->Eng << endl;
		cout << "수학 점수 : " << Element->Math << endl;
	}
	*/


	vector<int> numbers;


	// 반복자 iterator ------------------------------------------------------------ //

	// iterator = 포인터
	vector<Object*>::iterator iter;

	{
		// ** (시작점) 첫번째 원소를 가르키는 반복자
		iter = Objects.begin();

	}

	{
		// ** 마지막을 가르키는 반복자
		iter = Objects.end();

		if (iter == Objects.end())
			cout << "list의 마지막입니다." << endl;
	}

	{
		for (vector<Object*>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
		{
			cout << "첫번째 원소의 국어 점수" << (*iter)->Kor << endl;
			cout << "첫번째 원소의 영어 점수" << (*iter)->Eng << endl;
			cout << "첫번째 원소의 수학 점수" << (*iter)->Math << endl << endl;
		}

	}


	{
		// ** 원하는 위치에 원하는 값을 추가한다.
		Objects.insert(Objects.begin(), CreateObject(0, 1, 2));

		cout << endl << "[at]" << endl;
		for (int i = 0; i < Objects.size(); ++i)
		{
			cout << "원하는 위치에 원하는 값 추가 : 원소의 국어 점수" << Objects.at(i)->Kor << endl;
			cout << "원하는 위치에 원하는 값 추가 : 원소의 영어 점수" << Objects.at(i)->Eng << endl;
			cout << "원하는 위치에 원하는 값 추가 : 원소의 수학 점수" << Objects.at(i)->Math << endl << endl;
		}
	}

	{
		// ** Cotainer의 모든 내용을 삭제한다.
		Objects.clear();

		for (vector<Object*>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
		{
			cout << "모든 내용을 삭제 : 국어 점수" << (*iter)->Kor << endl;
			cout << "모든 내용을 삭제 : 영어 점수" << (*iter)->Eng << endl;
			cout << "모든 내용을 삭제 : 수학 점수" << (*iter)->Math << endl << endl;
			
			delete (*iter);
		}
		
		
	}



	{
		// ** 원하는 위치의 값을 삭제한다.
		for (vector<Object*>::iterator iter = Objects.begin(); iter != Objects.end();)
		{
			float result = ((*iter)->Kor + (*iter)->Eng + (*iter)->Math) / 3.0f;

			if (result < 16)
				iter = Objects.erase(iter);
			else
			{
				cout << "원하는 위치의 값 삭제 : 원소의 국어 점수" << (*iter)->Kor << endl;
				cout << "원하는 위치의 값 삭제 : 원소의 영어 점수" << (*iter)->Eng << endl;
				cout << "원하는 위치의 값 삭제 : 원소의 수학 점수" << (*iter)->Math << endl << endl;
				++iter;
				
			}
		}
		
	}

	{
		// ** 값이 있는 없는지 확인한다.
		if (Objects.empty())
			cout << "Data가 없습니다." << endl;
	}

	return 0;
}