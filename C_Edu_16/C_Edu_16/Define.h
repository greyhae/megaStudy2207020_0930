#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ** ���
// �ڿ� f�� �ٿ��� �Ѵ�. ������ double��
#define PI 3.141529f

// ** �޼��� ���
// �ڿ� ;(�����ݷ�)�� ���̸� ;���� ������
#define Output(str) printf("%s\n", str)
#define ERRMSG(FineName) printf("%d���ο��� Err�� �߻��߽��ϴ�.%s ���� File�� ã�� �� �����ϴ�.\n", __LINE__)

// ** ����
#define SUM(a, b) (a + b)
#define MUL(a, b) (a * b)

// global ����
extern int Count = 0;