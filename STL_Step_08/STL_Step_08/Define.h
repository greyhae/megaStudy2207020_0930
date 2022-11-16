#pragma once

template <typename T>
// ** inline : 클래스 내의 함수와 같은
inline void Safe_Release(T* _Obj)
{
	if (_Obj)
	{
		delete _Obj;
	}
}