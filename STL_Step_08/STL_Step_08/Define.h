#pragma once

template <typename T>
// ** inline : Ŭ���� ���� �Լ��� ����
inline void Safe_Release(T* _Obj)
{
	if (_Obj)
	{
		delete _Obj;
	}
}