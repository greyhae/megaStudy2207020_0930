/*
	Vector
	- ����Ʈ���� �޸� ���Ϳ����� ��ü�� �������ϴ� ���� 
*/

#include <stdio.h>
#include <malloc.h>

int* Front;
int* Back;

int size = 0;
//���뷮
int capacity = 0;

int* Vector = nullptr;

void push_back(int _value);
void erase(int _Where);
void Output();

int main(void)
{

	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);
	push_back(60);
	push_back(70);

	printf("%d\n", *Front);
	printf("%d\n", *Back);
	printf("%d\n", size);

	erase(3);
	erase(3);
	erase(3);

	Output();
	return 0;
}

void push_back(int _value)
{
	// �ӵ� : capacity / 2 -> capacity * 0.5 -> capacity >> 1
	if(capacity == size)
	{ 
		int result = (capacity >> 1);
		capacity += (result < 1) ? 1 :result;

		printf("capacity : %d\n", capacity);
		//printf("size : %d\n", size);
	}
	else
	{
		// else �� ��� �۾��� ����!!!
		// else�� ��� : �Ʒ� ������ ������ �ʿ䰡 �ִ����� ����
		/*int* Temp = (int*)malloc(sizeof(int) * size);

		for (int i = 0; i < size; ++i)
			Temp[i] = Vector[i];

		free(Vector);
		*/
		return;
	}

	int* Temp = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		Temp[i] = Vector[i];

	free(Vector);

	++size;

	Vector = (int*)malloc(sizeof(int) * capacity);

	for (int i = 0; i < size; ++i)
		Vector[i] = Temp[i];

	// ** �����Ҵ��� ���� ������ ����
	free(Temp);

	Vector[size - 1] = _value;

	Front = &Vector[0];
	Back = &Vector[size - 1];
}

void erase(int _Where)
{
	--size;
	for (int i = _Where - 1; i < size - 1; ++i)
		Front[i] = Front[i + i];
}
void Output()
{
	printf("��ü ��� \n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", Front[i]);
		//printf("�ּ� : %p\n", Front[i]);
	}
}