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

#define ErrorMessage(Str) (\
cout << "Error : where (" << __FILE__ << ") line (" << __LINE__ << ")" << endl\
	system("pause");

const int KEYID_UP		= 0X00000001;// 1
const int KEYID_DOWN	= 0X00000002;// 2
const int KEYID_LEFT	= 0X00000004;// 4
const int KEYID_RIGHT	= 0X00000008;// 8
const int KEYID_SPACE	= 0X00000010;// 16
const int KEYID_ENTER	= 0X00000020;// 32
const int KEYID_ESC		= 0X00000040;// 64
const int KEYID_CTRL	= 0X00000080;// 128
const int KEYID_ALT		= 0X00000100;// 256