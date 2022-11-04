#include "Headers.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFactory.h"

int main(void)
{
	Vector2 position;
	position.x = 0;
	position.y = 0;

	Object* pObj = ObjectFactory::CreateObject<Player>("ȫ�浿", position);
	return 0;
}