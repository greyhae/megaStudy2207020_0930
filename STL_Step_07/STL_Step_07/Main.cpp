#include "Headers.h"
#include "ObjectPool.h"
#include "Prototype.h"
#include "Alatreon.h"

// ** DesignPattern
// ** ObjectPool Pattern

int main(void)
{
	Prototype::GetInstance()->Initialize();
	{
		Object* pObj = new Alatreon;
		pObj->Start();
		pObj->SetKey("Enemy");

		if (Prototype::GetInstance()->AddProtoTypeObject(pObj))
		{
			//continue;
			//break;

			//return;
		}
	}
	list<Object*>* objectList = ObjectPool::GetInstance()->GetDisableObjectList("Alatreon");

	if (objectList == nullptr)
	{
		// ** 리스트 추가
		cout << "objectList == nullptr" << endl;

		Object* pObj = new Alatreon();
		pObj->Start();

		ObjectPool::GetInstance()->AddObjectList(pObj);
	}
	else
	{
		// ** DisableList에서 EnableList로 switching
		if (!objectList->empty())
		{
			// ** disable list -> enable list 
			// =>>> 만들어볼 것!!!!
		}
		else
		{
			// ** create
			ObjectPool::GetInstance()->CreateObjectList();
		}
	}

	/*
	while(true)
	{
		system("cls");

		// ** 버튼 입력을 받아서
		if (GetAsyncKeyState(VK_RETURN))
		{
			// ** 현재 사용중인 키를 임시로 지정
			string key = "Alatreon";

			// ** 제일 먼저 DisableList에 데이터가 있는지 없는 지 확인
			if(!DisableList.empty())
			{ 
				// ** 데이터가 있다면 키를 확인
				auto iter = DisableList.find(key);

				// ** DisableList 에 찾는 값이 있는 확인
				if (iter == DisableList.end())
				{
					// ** 찾는 값이 없다면 새롭게 생성해준다.
					Object* pObj = new Alatreon;

					// ** 초기화
					pObj->Start();

					// ** 생성 및 초기화된 객체를 List를 생성하여 추가한다.
					list<Object*> temp;
					temp.push_back(pObj);

					// ** 모든 작업이 완료 되었다면 맵에 추가한다.
					EnableList.insert(make_pair(pObj->GetKey(), temp));
				}


				Object* pObj = iter->second.front();
				pObj->Start();
				

				if (DisableList.find(pObj->GetKey())->second.empty())
				{
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
			}
			else
			{
				Object* pObj = new Alatreon;
				pObj->Start();

				auto iter = EnableList.find(pObj->GetKey());

				if (iter == EnableList.end())
				{
					list<Object*> temp;
					temp.push_back(pObj);
					EnableList.insert(make_pair(pObj->GetKey(), temp));
				}
				else
					iter->second.push_back(pObj);
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
					auto ObjIter = DisableList.find((*iter2)->GetKey());

					if (ObjIter == DisableList.end())
					{
						list<Object*> temp;
						temp.push_back((*iter2));
						EnableList.insert(make_pair((*iter2))->GetKey(), temp));
						DisableList.find((*iter2)->GetKey())->second.push_back((*iter2));
						
					}
					else
						iter2 = EnableList.find((*iter2)->GetKey())->second.erase(iter2);
				}
				else
					++iter;
			}
		}
	
	}
	*/
	return 0;
}