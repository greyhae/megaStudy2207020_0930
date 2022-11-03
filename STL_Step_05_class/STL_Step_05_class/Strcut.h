#pragma once
struct Info
{
	int Kor;
	int Eng;
	int Math;

	Info() : Kor(0), Eng(0), Math(0) {}
	Info(int _Kor, int _Eng, int _Math) : Kor(_Kor), Eng(_Eng), Math(_Math) {}
};