#include <iostream>
#include <string>
#include <map>

using namespace std;

class Object
{
public:
	int Kor;
	int Eng;
	int Math;

	int Mean;
};

int main(void)
{
	// ** vector<value> - 배열
	// ** list<value>
	
	// ** map<key, value> -  node 순서는 왼쪽부터 :너비 우선 탐색 (깊이 우선 탐색은 위쪽부터 정렬)

	// ** map<key, *value> - value는 *(포인터)로 사용하는게 좋음

	map<int, string> names;

	names.insert(make_pair(1, "홍길동"));
	names.insert(make_pair(2, "임꺽정"));
	names.insert(make_pair(3, "이몽령"));
	names.insert(make_pair(4, "성춘향"));

	for (map<int, string>::iterator iter = names.begin(); iter != names.end(); ++iter)
	{
		//(*iter).first; = key
		//(*iter).second; = value
		cout << (*iter).first  << " : " << (*iter).second << endl;
	}

	// ** 배열처럼 출력 가능
	cout << names[1] << endl;
	cout << names[2] << endl;
	cout << names[3] << endl;
	cout << names[4] << endl;

	// ** map<string, int> numbers;
	map<string, int> numbers;
	numbers["홍길동"] = 1;
	numbers["임꺽정"] = 2;
	numbers["이몽령"] = 3;
	numbers["성춘향"] = 4;

	
	// ** map<int, list<string>>
	// ** map<int, vector<string>>
}