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
		// ** ����Ʈ �߰�
		cout << "objectList == nullptr" << endl;

		Object* pObj = new Alatreon();
		pObj->Start();

		ObjectPool::GetInstance()->AddObjectList(pObj);
	}
	else
	{
		// ** DisableList���� EnableList�� switching
		if (!objectList->empty())
		{
			// ** disable list -> enable list 
			// =>>> ���� ��!!!!
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

		// ** ��ư �Է��� �޾Ƽ�
		if (GetAsyncKeyState(VK_RETURN))
		{
			// ** ���� ������� Ű�� �ӽ÷� ����
			string key = "Alatreon";

			// ** ���� ���� DisableList�� �����Ͱ� �ִ��� ���� �� Ȯ��
			if(!DisableList.empty())
			{ 
				// ** �����Ͱ� �ִٸ� Ű�� Ȯ��
				auto iter = DisableList.find(key);

				// ** DisableList �� ã�� ���� �ִ� Ȯ��
				if (iter == DisableList.end())
				{
					// ** ã�� ���� ���ٸ� ���Ӱ� �������ش�.
					Object* pObj = new Alatreon;

					// ** �ʱ�ȭ
					pObj->Start();

					// ** ���� �� �ʱ�ȭ�� ��ü�� List�� �����Ͽ� �߰��Ѵ�.
					list<Object*> temp;
					temp.push_back(pObj);

					// ** ��� �۾��� �Ϸ� �Ǿ��ٸ� �ʿ� �߰��Ѵ�.
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