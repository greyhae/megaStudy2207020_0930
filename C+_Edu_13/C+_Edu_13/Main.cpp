#include <stdio.h>
#include <malloc.h>

struct Node
{
	int Value;
	Node* Next;
	Node* Front;
};

Node* Begin;
Node* End;
int size = 0;

void erase(int _where);
void Testcase2(Node* _List, const int _Value);
void Testcase1(Node* _List, const int _Value);
void push_back(int _Value);
int Pop_back();
void Output();
void Clear();

int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	Begin = List;
	End = List;
	List->Front = nullptr;
	List->Next = nullptr;
	List->Value = 1;
	size = 1;

	for (int i = 0; i < 51; ++i)
		push_back(i + 1);

	//AddData(20);
	///AddData(30);
	//AddData(40);
	//AddData(50);
	//Testcase1(List, 60);
	//Testcase2(List, 70);

	//erase(50);
	//erase(1);
	//erase(24);

	//Clear();
	Output();

	//printf("\n<������ �����͸� �����մϴ�.\n");
	//printf("%d\n", Pop());

	//Output(Begin, List->Value);
	//printf("%d\n", List->Value);
	//printf("%d\n", List->Next->Value);
	//printf("%d\n", List->Next->Next->Value);
	//printf("%d\n", List->Next->Next->Next->Value);
	//printf("%d\n", List->Next->Next->Next->Next->Value);

	return 0;
}


void erase(int _where)
{
	// ** ��尡 1�����϶����� ����Ʈ�� ��ü ����
	if (size == 1)
		// ** ����� �׽�Ʈ�� ���ؼ� ������
		return;
	// ** ù��° ���� ���� ��尡 ���� ������ ���� ���� ������ �� ����.(������ ��尡 ����.)
	// ** ù��° ���� begin�� �ȴ�.

	if (_where == 1)
	{
		Node* left = Begin;
		Begin = Begin->Next;

		free(left);
	}

	// ** ������ ���� ���� ��尡 ���� ������ ���� ���� ������ �� ����.(������ ��尡 ����.)
	// ** ������ ���� end�� �ȴ�.
	else if (_where == size)
	{
		Pop_back();
	}
	// ** �߰��� �ִ� ������ _where�� ī������ �ؼ�
	else
	{
		Node* left = Begin;
		Node* current = nullptr;
		Node* right = nullptr;

		// ** ����Ʈ�� ��ü �����ŭ �ݺ�
		for (int i = 0; i < _where - 1; ++i)
			left = left->Next;

		current = left->Next;
		right = current->Next;

		left->Next = right;
		free(current);

		//printf("%d\n", left->Value);
		//printf("%d\n", current->Value);
		//printf("%d\n", right->Value);
		//printf("%d\n", size);
	}

}

// ** �ݺ����� ����� ������ �߰�
void Testcase2(Node* _List, const int _Value)
{
	// ** ù��° ��ġ�� ��带 �޾ƿ´�.
	Node* pList = _List;

	// ** ������ ��带 ã�´�.
	while (pList->Next != nullptr)
		pList = pList->Next;

	// ** ������ ��带 ã�Ҵٸ� ������ ����� ���� ��忡 ���ο� ��带 �߰� ����.
	pList->Next = (Node*)malloc(sizeof(Node));

	// ** ���� ���� �̵�
	pList = pList->Next;

	// ** ������ �ʱ�ȭ
	pList->Value = _Value;
	pList->Next = nullptr;

	// ** ������ ��� ����
	End = pList;

	// ** ������ ����
	++size;
}

// ** ����Լ��� ȣ���ϴ� ���
void Testcase1(Node* _List, const int _Value)
{
	// ** ����Ʈ�� ������ �����͸� ã�´�.
	if (_List->Next == nullptr)
	{
		// ** ������ �����Ͷ�� ���� ��忡 �߰��� ���ο� ��带 ����
		Node* pList = (Node*)malloc(sizeof(Node));

		// ** �����͸� �ʱ�ȭ �Ѵ�.
		pList->Value = _Value;
		pList->Next = nullptr;

		// ** ���Ӱ� ������ ��带 ������ ��ġ�� �߰�
		_List->Next = pList;

		// ** ������ ��� ����
		End = _List->Next;

		// ** ������ ����
		++size;

	}
	else
		// ** ������ ��尡 �ƴ϶�� ���� ��带 ã�� ���� ���ȣ���Ѵ�.
		// ** ����Լ��� ȣ���� ������ ���� ��带 �����ش�.
		Testcase1(_List->Next, _Value);
}

void push_back(int _Value)
{
	End->Next = (Node*)malloc(sizeof(Node));
	End->Next->Front = End;
	End = End->Next;
	

	End->Next = nullptr;
	End->Value = _Value;
	++size;
}

int Pop_back()
{
	// ** ù��° ��ġ�� ��带 �޾ƿ´�.
	int Value = End->Value;

	// ** ������ ��带 �ְ�
	Node* pList = End;

	// ** End ����� ���� ��带 End ���� ����
	End = End->Front;


	// ** �ݺ����� ����Ǿ��ٸ� ���� ���� ������ ����̹Ƿ� �������ش�.
	free(pList);

	// ** �׸��� ������ ����� ��ġ�� nullptr�� �ʱ�ȭ �Ѵ�.
	End->Next = nullptr;

	// ** ���Ұ� �����Ǿ����Ƿ�, ����� �ٿ��ش�.
	--size;

	// ** ������ ������ ��� ���� ��ȯ�ϰ� �Լ��� �����Ѵ�.
	return Value;
}

void Output() {

	Node* NodeList = End;

	printf("<��ü �����͸� ����մϴ�.>\n");

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Front;
	}
	printf("\n");

	/*
	Node* NodeList = Begin;

	printf("<��ü �����͸� ����մϴ�.>\n");

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
	printf("\n");
	*/
}

void Clear()
{
	// ** ���Ӱ� �����ϰ� Begin�� �ش�.
	Node* NodeList = Begin;

	// ** NodeList�� nullptr�� �ƴ϶�� �ݺ���
	while (NodeList != nullptr)
	{
		// ** ���� ������ �̹� NodeList�� �Ѱ� �־��� ������ begin�� ���� ��带 ����Ű���� ���ش�.
		Begin = Begin->Next;

		// ** ���� ����� ������ �����.
		free(NodeList);
		NodeList == nullptr;

		// ** �ٽ� NodeList�� Begin�� �Ѱ��ش�.
		NodeList = Begin;
	}
;
}