#include "Headers.h"
#include "Alatreon.h"

// ** DesignPattern
// ** ObjectPool Pattern

int main(void)
{
	//list<Object*> EnableList;
	//list<Object*> DisableList;
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;

	while(true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_RETURN))
		{
			string key = "Alatreon";

			if(!DisableList.empty())
			{ 
				auto iter = DisableList.find(key);

				Object* pObj = iter->second.front();
				pObj->Start();
				

				auto iter2 = EnableList.find(pObj->GetKey());
				if (iter2 == EnableList.end())
				{
					list<Object*> temp;
					temp.push_back(pObj);
					EnableList.insert(make_pair(pObj->GetKey(), temp));
				}
				else
					iter2->second.push_back(pObj);

				DisableList.find(pObj->GetKey())->second.pop_front();

			}
			else
			{
				Object* pObj = new Alatreon;
				pObj->Start();
				EnableList.find(pObj->GetKey())->second.push_back(pObj);
			}
		}
	

		// for(auto objcet :EnableList)
		for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
		{
			for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			{
				int result = (*iter2)->Update();
				(*iter2)->Render();

				if (result == 1)
				{
					//DisableList.find(*iter2)->GetKey())->second.pop_front();
					iter = EnableList.erase(iter);
				}
				else
					++iter;
			}
		}

		cout << "[disableList]" << endl;
		for (auto list : DisableList)		for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
		{
			for (auto iter2 = iter->.second.begin(); iter2 != iter->second.end(); ++iter2)			for(auto object : list)
			cout << object->GetKey() << endl;
	
	}

	return 0;
}