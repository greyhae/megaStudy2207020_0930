#pragma once

class Object
{
private:
	// ** 변수 생성
public:
	// ** 초기화
	virtual void Initialize();

	// ** 변경
	virtual void Progress();

	// ** 갱신
	virtual void Render();

	// ** 삭제
	virtual 
		void Release();
};

