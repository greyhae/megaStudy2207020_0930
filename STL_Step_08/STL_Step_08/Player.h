#pragma once

class Player
{
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:
	Player();
	virtual ~Player();
};

