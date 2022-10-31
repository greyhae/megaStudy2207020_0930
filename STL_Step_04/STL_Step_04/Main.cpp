#include <iostream>
#include <Windows.h>
#include <map>
#include <vector>
#include <list>

using namespace std;

class Object
{
public:
	int Kor;
	int Eng;
	int Math;

	int Mean;
};

map<int, list<Object*>> Objects;

Object* CreateObject(int, int, int);
void AddObject(Object*, int);

// ** map ------------------------------------- //


int main(void)
{
	// ** map<int, Object> : 나중에 수업예정. 젤 어려움

	// ** 객체를 관리하는 방식   -------------- //
	// ** map<int, list<Object>>
	// ** map<int, vector<Object>>

	// ** vectorName.push_back(pObj);
	// ** mapName["Key"] = vectorName;

	/*
	int index = 0;
	map<int, list<Object*>> Objects;

	{
		// ** 오브젝트 생성
		Object* pObj = CreateObject(10, 20, 30);

		// ** 입력받을 값
		int value = 0;

		// ** 입력
		cout << "입력 : "; cin >> value;

		// ** 입력된 값을 탐색
		map<int, list<Object*>>::iterator iter = Objects.find(value);

		// **데이터가 없다면.....
		if (iter == Objects.end())
		{
			// ** 리스트를 새롭게 생성하고
			list<Object*> temp;

			// ** 생성된 리스트에 오브텍트를 추가
			temp.push_back(pObj);

			// ** 오브젝트가 추가된 리스트를 map에 넣는다.
			Objects.insert(make_pair(index++, temp));

		}
		else // ** 찾는 데이터가 있다면...
			// ** 그곳에 오브젝트를 추가한다.
			iter->second.push_back(pObj);

	}
	*/

	for (int i = 0; i < 5; ++i)
	{
		
		// ** 난수 값 초기화
		srand((unsigned int)GetTickCount64());

		// ** 오브젝트 생성
		Object* pObj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30);

		// ** 입력받을 값
		int value = 0;

		// ** 입력
		cout << "입력 : "; cin >> value;

		// ** 오브젝트 추가
		AddObject(pObj, value);

		
	}

	// ** 출력 : 위 for문 위에 이중 for문을 이용해서 출력하는 방법으로 해 볼 것!!!
	cout << "출력 : " << endl;

	// ** 데이터를 관리하는 방식 -------------- //
	// ** list<map<int, string>>

	return 0;
}


Object* CreateObject(int _kor, int _eng, int _math)
{
	Object* pObj = new Object;

	pObj->Kor = _kor;
	pObj->Eng = _eng;
	pObj->Math = _math;

	pObj->Mean = float((_kor + _eng + _math) / 3);

	return pObj;

}

void AddObject(Object* _pObj, int _value)
{
	// ** 입력된 값을 탐색
	map<int, list<Object*>>::iterator iter = Objects.find(_value);

	// **데이터가 없다면.....
	if (iter == Objects.end())
	{
		// ** 리스트를 새롭게 생성하고
		list<Object*> temp;

		// ** 생성된 리스트에 오브텍트를 추가
		temp.push_back(_pObj);

		// ** 오브젝트가 추가된 리스트를 map에 넣는다.
		Objects.insert(make_pair(_value, temp));

	}
	else // ** 찾는 데이터가 있다면...
		// ** 그곳에 오브젝트를 추가한다.
		iter->second.push_back(_pObj);
}