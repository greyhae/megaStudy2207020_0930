#pragma once
#include "Headers.h"
#include <sstream>
#include <istream>

class DataManager
{
private:
	static list<string> filePath;

	//string filePath;
	//string fineName;
public:
	static void saveData(string fileName)
	{
		// ** ���� ������Ʈ ������ ��ġ�� �޾ƿ´�.
		istringstream iss(__FILE__);

		// ** ��ε��� �߶󳻱� ���� �ӽ÷� ���� ���ڿ� ����
		string buffer = "";

		// ** �߶� ���ڿ��� ��� �����ϱ� ���� ����
		vector<string> temp;

		// ** ���ڿ��� �߶�
		while (getline(iss, buffer, '\\'))
			temp.push_back(buffer);

		// ** ���ڿ��� �߶�´ٸ� ������ 2���� ����
		temp.pop_back(); // ** ���� ���� [DataManager.h]�� ����
		temp.pop_back(); // ** [DataManager.h]�� ���ԵǾ��ִ� ���� �̸��� �����ȴ�.

		// ** ������ �Ϸ� �Ǿ��ٸ� �ٽ� �����ϱ� ���� �ӽ��� ������ ����
		string path = "";

		// ** ��θ� �ٽ� ����� ��Ų��.
		for (vector<string>::iterator iter = temp.begin(); iter != temp.end(); ++iter)
			path += (*iter) + "\\";

		// ** ���ҽ��� �ִ� ��ġ�� Path�� �����
		filePath.push_back(path + "Resources\\" + fileName);
	}

	static void loadData()
	{
		for (list<string>::iterator iter = filePath.begin(); iter != filePath.end(); ++iter)
			cout << (*iter) << endl;
	}
};

list<string> DataManager::filePath;