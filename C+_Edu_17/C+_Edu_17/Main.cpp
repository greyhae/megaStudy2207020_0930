#include <stdio.h>
#include <malloc.h>
#include <Windows.h>

struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0) {}

	Vector2(int _x, int _y) : x(_x), y(_y) {}
};
struct Object
{
	Vector2 Position;
	Vector2 Scale;
	char* Texture;
};
typedef struct Node
{
	Object* pObj;
	Node* Front;
	Node* Back;
};

Node* CreateNode();
Object* CreateObject(int _x, int _y, char* _Texture);
void output();

int main(void)
{
	Node* BulletList = (Node*)malloc(sizeof(Node));
	Object* Enemy = CreateObject(0, 0, (char*)"Enemy");


	ULONGLONG Time = GetTickCount64();

	while(true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			if (GetAsyncKeyState(VK_SPACE))
			{
				// 총알 생성 : 매개 변수로 넘겨주거나
				BulletList->pObj = CreateObject(0, 0, (char*)"Bullet");
			}
		}
	}


	return 0;
}

Node* CreateNode()
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->pObj = nullptr;
	pNode->Front = nullptr;
	pNode->Back = nullptr;

	return pNode;
}

Object* CreateObject(int _x, int _y, char* _Texture)
{
	Object* pObj = (Object*)malloc(sizeof(Object));

	//초기화
	pObj->Position = Vector2(_x, _y);
	//pObj->Scale = Vector2((int)strlen;
	pObj->Texture = _Texture;

	return pObj;
}

/*
Object* CreateEnemy()
{
	Object* pEnemy = (Object*)malloc(sizeof(Object));;
	pEnemy->Position = Vector2();
	pEnemy->Scale = Vector2();
	pEnemy->Texture = (char*)"";

	return pEnemy;
}
*/

void output()
{
	
}