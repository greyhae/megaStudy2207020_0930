#include <iostream>
#include <Windows.h>
#include <map>
#include <vector>
#include <list>

using namespace std;

struct Info
{
	int Kor;
	int Eng;
	int Math;

	Info() : Kor(0), Eng(0), Math(0) {}
	Info(int _Kor, int _Eng, int _Math) : Kor(_Kor), Eng(_Eng), Math(_Math) {}
};
class Object
{
protected:
	Info info;
	int key;
public:
	virtual void Initialize()PURE;
public:
	int GetKey() { return key; }
	void Render()
	{
		cout << "국어점수 : " << info.Kor
			<< "영어점수 : " << info.Eng
			<< "수학점수 : " << info.Math << endl << endl;
	}
public:
	Object() : key(0){}
	Object(Info _info) : info(_info), key(0) {}

};

// ** Teacher
class Teacher : public Object
{
	void Initialize()
	{
		key = 1;
	}
public:
	Teacher() {}
	Teacher(Info _info) : Object(_info) {}
};

// ** Student
class Student : public Object
{
public:
	void Initialize()
	{
		key = 2;
	}
public:
	Student() {}
	Student(Info _info) : Object(_info) {}
};



class ObjcetManager
{
private:
	static ObjcetManager* Instance;
public:
	static ObjcetManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjcetManager;
		return Instance;
	}
private:
	map<int, list<Object*>> Objects;
public:
	
private:
	ObjcetManager();
	
public:
	~ObjcetManager();
};

void AddObject(Object*);

int main(void)
{

	for (int i = 0; i < 5; ++i)
	{

		// ** 난수 값 초기화
		srand((unsigned int)GetTickCount64());

		// ** 오브젝트 생성
		
		// ** 함수 사용보다 생성자 사용해서 호출하는게 더 효율적
		//Object* pObj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30)

		Object* pObj = new Student(Info(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30));

		pObj->Initialize();


		// ** 오브젝트 추가
		ObjcetManager::GetInstance()->AddObject(pObj);


	}

	// ** 출력
	ObjcetManager::GetInstance()->Render();

	for (auto iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != Objects.end(); ++iter2)
		{

		}
	}

	return 0;
}

void AddObject(Object* _pObj)
{
	map<int, list<Object*>>::iterator iter = Objects.find(_pObj->GetKey());

	if (iter == Objedts.end())
	{
		list<Object*> temp;
		temp.push_back(_pObj);

		Objects.insert(make_pair(_pObj->GetKey())
	}
}