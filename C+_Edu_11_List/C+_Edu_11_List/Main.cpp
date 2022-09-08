#include <stdio.h>
#include <malloc.h>

struct Node
{
	int Value;
	Node* Next;
};

Node* Begin;
Node* End;
int size = 0;

void Testcase2(Node* _List, const int _Value);
void Testcase1(Node* _List, const int _Value);
void AddData(int _Value);
int Pop();
void Output();

int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	Begin = List;
	End = List;
	List->Value = 10;
	size = 1;

	AddData(20);
	AddData(30);
	AddData(40);
	AddData(50);
	Testcase1(List, 60);
	Testcase2(List, 70);

	Output();

	printf("\n<������ �����͸� �����մϴ�.\n");
	printf("%d\n", Pop());

	//Output(Begin, List->Value);
	//printf("%d\n", List->Value);
	//printf("%d\n", List->Next->Value);
	//printf("%d\n", List->Next->Next->Value);
	//printf("%d\n", List->Next->Next->Next->Value);
	//printf("%d\n", List->Next->Next->Next->Next->Value);

	return 0;
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

void AddData(int _Value)
{
	End->Next = (Node*)malloc(sizeof(Node));
	End = End->Next;

	End->Next = nullptr;
	End->Value = _Value;
	++size;
}

int Pop()
{
	// ** ù��° ��ġ�� ��带 �޾ƿ´�.
	int Value = End->Value;

	// ** ó�� ��带 ����
	Node* pList = Begin;

	// ** ����Ʈ�� ��ü �����ŭ �ݺ�
	for(int i = 0; i < size; ++i)
	{
		// ** ���� ����� ���� ���� ���� ���� ��带 ã�´�.
		if (pList->Next->Value == Value)
		{
			// ** ���� ���� ������ ����� ���� ����̹Ƿ�
			End = pList;

			// ** ���� ��带 ������ ���� ����
			pList = pList->Next;

			// ** �ݺ����� Ż��
			break;
		}
		// ** if ������ ������ ��带 ã�� ���ߴٸ� ���� ���� �̵�
		pList = pList->Next;
	}

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

	Node* NodeList = Begin;

	printf("<��ü �����͸� ����մϴ�.>\n");

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
	printf("\n");
}