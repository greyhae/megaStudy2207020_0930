#include "Object.h"

Object::Object() : key(0) {}
Object::Object(Info _info) : info(_info), key(0) {}

void Object::Initialize()
{

}

void Object::Render()
{
	cout << "국어점수 : " << info.Kor << endl
		<< "영어점수 : " << info.Eng << endl
		<< "수학점수 : " << info.Math << endl << endl;
}