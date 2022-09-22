/*
	Vector
	- 리스트에서 달리 벡터에서는 전체를 지워야하는 단점
*/

#include <stdio.h>
#include <malloc.h>

int* Front;
int* Back;

int size = 0;
int capacity = 0;

// ** 중간 삽입
void insert(int _Where, int _value);
void push_back(int _value);
void erase(int _Where);
void Output();

int main(void)
{
	Front = (int*)malloc(sizeof(int));

	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);
	push_back(60);
	push_back(70);

	insert(3, 25);
	insert(3, 23);
	push_back(100);

	printf("%d\n", *Front);
	printf("%d\n", *Back);
	printf("%d\n", size);

	//erase(3);
	//erase(3);
	//erase(3);

	Output();
	return 0;
}

void insert(int _Where, int _value)
{
	if (capacity == size)
	{
		int result = (capacity >> 1);
		capacity += (result < 1) ? 1 : result;

		// ** 늘어난 수용량의 임시의 공간을 새롭게 생성
		int* Temp = (int*)malloc(sizeof(int) * capacity);

		// ** 임시의 공간에 기존 데이터를 복사한다.
		// ** 이때! 주소의 복사가 아니라 값의 복사가 이루어져야 한다.
		for (int i = 0; i < size; ++i)
			Temp[i] = Front[i];

		// ** 기존 할당된 메모리 공간을 해제한다.
		//free(Front); //=> 이 부분에서 문제가 발생

		// ** 임시 공간의 주소를 Front가 받아온다.
		// ** Temp는 생성된 해당 영역열 빠져 나가면 소멸된다.
		// ** 하지만 할당된 메모리 주소는 Front에 남아 있으므로 사용 가능
		Front = Temp;

	}

	--_Where;
	// ** 위 분기의 실행 유무와 상관없이 현재 위치에서는 항상 수용량이 남는다.
	// ** 항상 (capacity > size) 와 같은 상태이므로 원소 추가가 가능하다.

	for (int i = 0; i < size; ++i)
		Temp[i] = Front[i];
	Front[size] = _value;

	// ** 끝나는 지점의 주소가 바뀌었으므로 새롭게 셋팅해준다.
	Back = &Front[size];

	// ** 원소가 추가되었으므로 size를 증가해준다.
	++size;
}

void push_back(int _value)
{

	// ** capacity(수용량) 가 size(현재 원소의 개수)와 값이 서로 같다면
	// ** 원소를 더 이상 추가할 수 없는 상태이므로...
	if (capacity == size)
	{
		// 속도 : capacity / 2 -> capacity * 0.5 -> capacity >> 1

		// ** 수용량을 늘려준다.
		int result = (capacity >> 1);
		capacity += (result < 1) ? 1 : result;

		// ** 수용량이 늘어나게 되면 실제 메모리상의 데이터 수용량도 늘려야 하기 때문에
		// ** 늘리는 과정에서 데이터를 보존할 수 없으므로 옮겨두어야 한다.
		// ** 그러기 위해 필요한 임시의 공간을 생성

		/////////////////////////////////////////////////////////////////////
		// ===== 코드 1
		/*
		int* Temp = (int*)malloc(sizeof(int) * size + 1);

		// ** 임시의 공간에 기존 데이터를 복사한다.
		// ** 이때! 주소의 복사가 아니라 값의 복사가 이루어져야 한다.
		for (int i = 0; i < size; ++i)
			Temp[i] = Front[i];

		// ** 기존 할당된 메모리 공간을 해제한다.
		free(Front);

		// ** 늘어난 수용량 만큼의 크기로 새롭게 공간을 할당 한다.
		Front = (int*)malloc(sizeof(int) * capacity);

		// ** 새롭게 할당된 공간에 복사해둔 데이터를 다시 들고온다.
		for (int i = 0; i < size; ++i)
			Front[i] = Temp[i];

		// ** 임시의 공간을 할당 해제한다.
		free(Temp);

		// ** 시작지점의 주소가 바뀌었으므로 새롭게 셋팅해준다.
		Back = &Front[size];
		*/

		/////////////////////////////////////////////////////////////////////
		// ===== 코드 2

		// ** 늘어난 수용량의 임시의 공간을 새롭게 생성
		int* Temp = (int*)malloc(sizeof(int) * capacity);

		// ** 임시의 공간에 기존 데이터를 복사한다.
		// ** 이때! 주소의 복사가 아니라 값의 복사가 이루어져야 한다.
		for (int i = 0; i < size; ++i)
			Temp[i] = Front[i];

		// ** 기존 할당된 메모리 공간을 해제한다.
		free(Front);

		// ** 임시 공간의 주소를 Front가 받아온다.
		// ** Temp는 생성된 해당 영역열 빠져 나가면 소멸된다.
		// ** 하지만 할당된 메모리 주소는 Front에 남아 있으므로 사용 가능
		Front = Temp;

	}
	
	// ** 위 분기의 실행 유무와 상관없이 현재 위치에서는 항상 수용량이 남는다.
	// ** 항상 (capacity > size) 와 같은 상태이므로 원소 추가가 가능하다.
	Front[size] = _value;

	// ** 끝나는 지점의 주소가 바뀌었으므로 새롭게 셋팅해준다.
	Back = &Front[size];

	// ** 원소가 추가되었으므로 size를 증가해준다.
	++size;

}

void erase(int _Where)
{
	--size;
	for (int i = _Where - 1; i < size - 1; ++i)
		Front[i] = Front[i + i];
}
void Output()
{
	printf("전체 출력 \n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", Front[i]);
		//printf("주소 : %p\n", Front[i]);
	}
}