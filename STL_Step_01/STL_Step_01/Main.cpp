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

int main(void)
{
	vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);
	numbers.push_back(50);

	cout << endl << "[Array]" << endl;
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers[i] << endl;

	cout << endl << "[At]" << endl;
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers.at(i) << endl;

	// ** ù��° ���Ҹ� ����Ų��.
	cout << endl << numbers.front() << endl;

	// ** ������ ���Ҹ� ����Ų��.
	cout << endl << numbers.back() << endl;

	// ** �����̳ʰ� ��� �ִ� ������ ����
	cout << endl << "size : " << numbers.size() << endl;

	// ** �����̳ʰ� ������ �� �ִ� �ִ� ����
	cout << endl << "capacity : " << numbers.capacity() << endl;

	// ** �����̳��� ������ ���Ҹ� ����
	numbers.pop_back();

	/*

	// ** �ݺ��� iterator
	numbers.begin();
	numbers.end();

	numbers.front();
	numbers.back();

	numbers.size();
	numbers.capacity();

	numbers.insert();
	numbers.empty();

	numbers.clear();
	numbers.erase();
	numbers.pop_back();
	*/

	// �ǽ� ����

	vector<Object*> Objects;

	cout << Objects[0] << endl;
	//Object.push_back();
	//Object.push_back();
	//Object.push_back();

	for (int i = 0; i < Objects.size(); ++i)
	{
		cout << Objects[i] << endl;
	}

	return 0;
}