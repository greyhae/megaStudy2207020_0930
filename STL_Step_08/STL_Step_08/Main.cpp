#include "Headers.h"

int main(void)
{
	Vector3 v1 = Vector3();
	Vector3 v2 = Vector3(1, 2);
	Vector3 v3 = Vector3(10, 20, 30);

	Vector3 v4 = v3 - v2;

	cout << v4.x << ", " << v4.y << ". " << v4.z << endl;

	return 0;
}