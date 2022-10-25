#pragma once
#include "Scene.h"

class Object;//원형이 없는 빈 클래스 - Object.h 의 Object 클래스와 다름
class Stage : public Scene
{
private:
	//Object* Testcase;
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Stage();
	virtual ~Stage();
};

