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
	// ** vector<value> - �迭
	// ** list<value>
	
	// ** map<key, value> -  node ������ ���ʺ��� :�ʺ� �켱 Ž�� (���� �켱 Ž���� ���ʺ��� ����)

	// ** map<key, *value> - value�� *(������)�� ����ϴ°� ����

	map<int, string> names;

	names.insert(make_pair(1, "ȫ�浿"));
	names.insert(make_pair(2, "�Ӳ���"));
	names.insert(make_pair(3, "�̸���"));
	names.insert(make_pair(4, "������"));

	for (map<int, string>::iterator iter = names.begin(); iter != names.end(); ++iter)
	{
		//(*iter).first; = key
		//(*iter).second; = value
		cout << (*iter).first  << " : " << (*iter).second << endl;
	}

	// ** �迭ó�� ��� ����
	cout << names[1] << endl;
	cout << names[2] << endl;
	cout << names[3] << endl;
	cout << names[4] << endl;

	// ** map<string, int> numbers;
	map<string, int> numbers;
	numbers["ȫ�浿"] = 1;
	numbers["�Ӳ���"] = 2;
	numbers["�̸���"] = 3;
	numbers["������"] = 4;

	
	// ** map<int, list<string>>
	// ** map<int, vector<string>>
}