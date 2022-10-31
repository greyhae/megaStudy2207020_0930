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
	// ** map<int, Object> : ���߿� ��������. �� �����

	// ** ��ü�� �����ϴ� ���   -------------- //
	// ** map<int, list<Object>>
	// ** map<int, vector<Object>>

	// ** vectorName.push_back(pObj);
	// ** mapName["Key"] = vectorName;

	/*
	int index = 0;
	map<int, list<Object*>> Objects;

	{
		// ** ������Ʈ ����
		Object* pObj = CreateObject(10, 20, 30);

		// ** �Է¹��� ��
		int value = 0;

		// ** �Է�
		cout << "�Է� : "; cin >> value;

		// ** �Էµ� ���� Ž��
		map<int, list<Object*>>::iterator iter = Objects.find(value);

		// **�����Ͱ� ���ٸ�.....
		if (iter == Objects.end())
		{
			// ** ����Ʈ�� ���Ӱ� �����ϰ�
			list<Object*> temp;

			// ** ������ ����Ʈ�� ������Ʈ�� �߰�
			temp.push_back(pObj);

			// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �ִ´�.
			Objects.insert(make_pair(index++, temp));

		}
		else // ** ã�� �����Ͱ� �ִٸ�...
			// ** �װ��� ������Ʈ�� �߰��Ѵ�.
			iter->second.push_back(pObj);

	}
	*/

	for (int i = 0; i < 5; ++i)
	{
		
		// ** ���� �� �ʱ�ȭ
		srand((unsigned int)GetTickCount64());

		// ** ������Ʈ ����
		Object* pObj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30);

		// ** �Է¹��� ��
		int value = 0;

		// ** �Է�
		cout << "�Է� : "; cin >> value;

		// ** ������Ʈ �߰�
		AddObject(pObj, value);

		
	}

	// ** ��� : �� for�� ���� ���� for���� �̿��ؼ� ����ϴ� ������� �� �� ��!!!
	cout << "��� : " << endl;

	// ** �����͸� �����ϴ� ��� -------------- //
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
	// ** �Էµ� ���� Ž��
	map<int, list<Object*>>::iterator iter = Objects.find(_value);

	// **�����Ͱ� ���ٸ�.....
	if (iter == Objects.end())
	{
		// ** ����Ʈ�� ���Ӱ� �����ϰ�
		list<Object*> temp;

		// ** ������ ����Ʈ�� ������Ʈ�� �߰�
		temp.push_back(_pObj);

		// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �ִ´�.
		Objects.insert(make_pair(_value, temp));

	}
	else // ** ã�� �����Ͱ� �ִٸ�...
		// ** �װ��� ������Ʈ�� �߰��Ѵ�.
		iter->second.push_back(_pObj);
}