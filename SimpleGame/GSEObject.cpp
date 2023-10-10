#include "stdafx.h"
#include "GSEObject.h"

GSEObject::GSEObject()
{
	sizeX = 0.f;
	sizeY = 0.f;
	sizeZ = 0.f;

}

GSEObject::~GSEObject()
{
}

void GSEObject::SetSize(float x, float y, float z)
{
	sizeX = x;
	sizeY = y;
	sizeZ = z;
}
