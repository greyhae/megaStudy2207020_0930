#include "Object.h"

Object::Object() : key(0) {}
Object::Object(Info _info) : info(_info), key(0) {}

void Object::Initialize()
{

}

void Object::Render()
{
	cout << "�������� : " << info.Kor << endl
		<< "�������� : " << info.Eng << endl
		<< "�������� : " << info.Math << endl << endl;
}