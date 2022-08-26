// ** �⺻ �����
#include <stdio.h>
// ** system �Լ�
#include <stdlib.h>
// ** input �� ������â�� ������ �� ���� ���̺귯��
#include <Windows.h>

struct Vector2
{
	int x, y;
};

struct Object
{
	Vector2 Position;
	Vector2 Scale;
	char* Texture;
};

bool Horzontal = false;
bool Vertical = false;

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);


int main(void)
{
	// ** Ŀ���� �� ���̰� ����
	ShowCursor(false);

	// ** �ð� ����
	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object Player;
	Player.Position.x = 0;
	Player.Position.y = 0;

	Player.Scale.x = 2;
	Player.Scale.y = 1;

	Player.Texture = (char*)"��";

	// ** ������ �Ѿ��� �غ��صд�
	Object Bullet[128];// 2�� ����

	// ** �Ѿ��� �߻� �Ǿ����� Ȯ���ϴ� �뵵
	bool ShowBullet[128];

	// ** �Ѿ��� �������� ������ �ֱ� ����
	ULONGLONG BulletDelay = GetTickCount64();

	for (int i = 0; i < 128; i++)
	{
		// ** srand = �����ϼ� �ʱ�ȭ
		srand(
			// ** ���� �ð��� �����Ͽ� �˼����� ������ �ʱ�ȭ
			GetTickCount64() * GetTickCount64());

		// ** rand() = ���� �Լ�
		// ** rdad() % 40 = 0 ~ 39 ������ ������
		Bullet[i].Position.x = 118;
		Bullet[i].Position.y = rand() % 40;
		Bullet[i].Texture = (char*)"*";

		ShowBullet[i] = false;
	}

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			// ** ȭ�� Ŭ����
			system("cls");

			InputKey(&Player);

			SetCursorPosition(
				Player.Position.x,
				Player.Position.y);

			printf("%s", Player.Texture);

			/*
			* �Ѿ� ����
			* 2.5�� �������� �Ѿ��� �����ϰ�, �����ϴ� �������� ���� ��Ȱ��ȭ �Ǿ��ִ� �Ѿ��� ã�� �·Ḧ �����ϰ�,
			* Ȱ��ȭ ���·� �����Ѵ�. �Ѿ��� 1�߸� ������ ���̹Ƿ� Ȱ��ȭ�� ������ �Ϸ�Ǹ� ��� �ݺ����� Ż���Ѵ�.
			*/
			for (int i = 0; i < 128; i++)
			{
				// ** �Ѿ��� 2.5�� ������ ������
				if (BulletDelay + 2500 < GetTickCount64())
				{
					// if(ShowBullet[i] == false)
					// ** �Ѿ��� ��Ȱ��ȭ ���¶��
					if (!ShowBullet[i])
					{
						// ** ����� �Ǿ��ٸ� ��ǥ�� �ٽ� �ʱ�ȭ ���ش�.
						Bullet[i].Position.x = 118;
						Bullet[i].Position.y = rand() % 40;

						// ** ���� ���¸� Ȱ��ȭ ���·� �����Ѵ�.
						ShowBullet[i] = true;

						// ** �ð����� �� �ʱ�ȭ �Ѵ�.
						BulletDelay = GetTickCount64();

						// ** �Ѿ��� 1���� Ȱ��ȭ �� ���̱� ������
						// ** �ݺ����� ����������.
						break;
					}
				}
			}

			for (int i = 0; i < 128; i++)
			{

				// if(ShowBullet[i] == true)
				// ** �Ѿ��� Ȱ��ȭ ���¶��
				if (ShowBullet[i])
				{
					// ** �Ѿ��� �̵�
					// ** �̵����� : ����
					Bullet[i].Position.x--;

					// ** �浹���� : �Ѿ� ��ǥ�� 0�� �Ǹ� �Ѿ� ��ǥ �ʱ�ȭ ���ش�.
					if (Bullet[i].Position.x <= 0)
					{
						ShowBullet[i] = false;
						continue;
					}

					// ** ũ����� �Բ� �����ؼ� ���� �浹 ������ �� : ������ Scale�� �̿��ؼ� �� ����
					if (Bullet[i].Position.x == Player.Position.x &&
						Bullet[i].Position.y == Player.Position.y)
					{
						ShowBullet[i] = false;
						continue;
					}

					// ** �Ѿ��� �� ��ġ�� �׷��� �� �ֵ��� Ŀ���� �̵���Ų��.
					SetCursorPosition(
						Bullet[i].Position.x,
						Bullet[i].Position.y);

					// ** �Ѿ��� �׸���.
					printf("%s", Bullet[i].Texture);
				}
			}
		}
	}

	return 0;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** ������ �·��� �̵���Ű�� �Լ�
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ��� �ڵ�
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����
}

// ** Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�
// ** true ���̰�, false �Ⱥ��̰�
void ShowCursor(bool _b)
{
	// ** Ŀ���� �⺻������ �����Ѵ�.
	CONSOLE_CURSOR_INFO Info;

	// ** Ŀ���� �⺻������ �����Ѵ�.
	// ** Ŀ���� ���ΰ�/�Ⱥ��̰� �Ѵ�.
	Info.bVisible = _b;

	// ** Ŀ���� ũ�⸦ �����Ѵ�.
	Info.dwSize = 1;

	// ** Ŀ���� ������ �����Ű�� �Լ�
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void InputKey(Object* _Object)
{
	// ** Ű �Է�
	// GetAsyncKeyState() = Ű�Է� �Լ�
	// ��Ȳ�� ���� ������ ��ȯ��
	// 0x0000,  0x0001,  0x8000,  0x8001

	// ** ���� 0�� 1�� ����
	// ** 0 : ������ ������ ����
	// ** 1 : ������ ������ ����

	// ** ���� 8�� 0�� ����
	// 0 : ���� ���� ����
	// 8 : ���� ����

	// ** �Ű� ������ Virtual Key�� �Է� �޴´�.

	//printf("%x\n", GetAsyncKeyState(VK_UP));
	//if(GetAsyncKeyState(VK_UP) & 0x01)\
					printf("zzz\n");

	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		// ** y ��ǥ�� 0���� Ŭ ���� �Է��� ������.
		if (_Object->Position.y > 0)
			_Object->Position.y--;
		/*
		if (y <= 0)
			y = 0;
		*/

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		// ** y ��ǥ�� 39���� ���� ���� �Է��� ������.
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;
}