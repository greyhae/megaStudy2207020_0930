#include "Player.h"
#include "InputManager.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	DWORD key = InputManager::GetInstance()->GetKey();

	if (key & KEYID_UP)
		cout << "KEYID_UP" << endl;
}

void Player::Update()
{

}

void Player::Render()
{

}

void Player::Release()
{

}


