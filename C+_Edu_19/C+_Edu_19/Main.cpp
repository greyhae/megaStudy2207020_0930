#include <stdio.h>
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
	int Index;
	Node* Front;
	Node* Back;

	// ** �浹 �̺�Ʈ�� ó���ϱ� ���� �ӽú���
	// ** Count�� ��� �����ϰ� Limit ������ ���� �������� �浹�̶�� ����
	int Count;
	int Limit;
};

// ** ù��° ���Ҹ� ����Ű�� ���
Node* Begin;

// ** ������ ���Ҹ� ����Ű�� ���
Node* End;

void SetCursorPosition(int _x, int _y);
Node* CreateNode();
Object* CreateObject(int _x, int _y, char* _Texture);
void BullseProgress(int _x, int _y, int _Index, char* _Texture);
void output();

int main(void)
{
	// ** Begin�� BulletList�� ���� �������� ����Ų��.
	Node* BulletList = Begin = CreateNode();

	// ** �ʱ�ȭ ������ ��尡 �������� �����Ƿ� ����ų ��尡 ����
	BulletList->Front = nullptr;
	BulletList->Back = nullptr;

	// ** Begin Object�� ����
	BulletList->pObj = CreateObject(0, 0, (char*)"Begin");

	// ** �ε��� �ʱ�ȭ
	int Index = 0;

	// ** ���� ���� ���۳��� ������ �����̱� ������ ���� 0���� ����.
	BulletList->Index = Index;

	BulletList->Count = 0;
	BulletList->Limit = 0;

	// ** ��尡 �������� �ʱ� ������ �������� ����Ű�� ���ҵ� �������� ����
	End = Begin;

	Object* Enemy = CreateObject(0, 0, (char*)"Enemy");

	ULONGLONG Time = GetTickCount64();


	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			if (GetAsyncKeyState(VK_SPACE))
			{
				// �Ѿ� ���� : �Ű� ������ �Ѱ��ְų�
				//BulletList->pObj = CreateObject(index++, 0, (char*)"Bullet");

				BullseProgress((Index / 39) * 20, Index % 39 - 1, ++Index, (char*)"Bullet");
			}

			output();

		}
	}


	return 0;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** ������ ��ǥ�� �̵���Ű�� �Լ�
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ�â�� �ڵ�
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����
}

//void SecCursorPosition()
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

	//�ʱ�ȭ
	pObj->Position = Vector2(_x, _y);

	pObj->Texture = _Texture;
	pObj->Scale = Vector2(strlen(_Texture), 1);

	return pObj;
}


void BullseProgress(int _x, int _y, int _Index, char* _Texture)
{
	// ** �ӽ��� node�� End�� ����Ű�� ���Ҹ� �Ѱ��ش�.
	Node* node = End;

	// ** ������ ��尡 ����Ű�� ���� ��ġ�� ���ο� ��带 ����
	node->Back = CreateNode();

	// ** �׸��� ���� ���� ���Ӱ� ������ ����� ��ġ�� �̵���Ŵ
	node = node->Back;

	// ** ���Ӱ� ������ ����� Index�� �ʱ�ȭ
	node->Index = _Index;

	node->Count = 0;

	srand(GetTickCount());
	node->Limit = rand() % 100;


	// ** ���Ӱ� ������ ����� Obj��Object�� ����
	node->pObj = CreateObject(_x, _y, _Texture);

	// ** ���Ӱ� ������ ����� ���� ��带 �����ϰ�
	node->Front = End;

	// ** ���� ��尡 ����Ű�� ������ nullptr�� ����
	node->Back = nullptr;

	// ** ��� �ʱⰪ�� ������ �Ϸ� �Ǿ��ٸ� ���Ӱ� ������ ��带 ������ ���� ����
	End = node;

}

void output()
{
	// ** ù��° ��带 �ӽ� ��忡 ����
	Node* node = Begin;

	// ** ù��° ���� ���Ұ� �ƴϱ� ������ ���� ���� �̵���Ų��.
	node = node->Back;

	// ** ���� ��尡 �������� �ʰų�,
	// ** ���� ��尡 ����Ű�� Obj�� �������� ����������... (�ݺ�)
	while (node && node->pObj)
	{

		if (node->Count >= node->Limit)
		{
			// ** ����
			Node* Temp = node;

			node->Front->Back = node->Back;

			End = (node->Back) ? node->Back : node->Front;

			node = node->Back;

			free(Temp);
			
		}
		else
		{ 
			++node->Count;

			SetCursorPosition(
				node->pObj->Position.x,
				node->pObj->Position.y);

			printf("%d.%s : %d (%d)\n", node->Index, node->pObj->Texture, node->Count, node->Limit);
			//printf("%d\n", node->pObj->Position.x);
			// 
			// ** ���� ��带 ����Ų��.
			node = node->Back;
		}
	}
}