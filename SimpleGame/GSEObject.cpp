#include "stdafx.h"
#include "GSEObject.h"

GSEObject::GSEObject()
{
	m_sizeX = 0.f;
	m_sizeY = 0.f;
	m_sizeZ = 0.f;

	m_posX = 0.f;
	m_posY = 0.f;
	m_posZ = 0.f;

}

GSEObject::~GSEObject()
{
}

void GSEObject::SetSize(float x, float y, float z)
{
	m_sizeX = x;
	m_sizeY = y;
	m_sizeZ = z;
}

void GSEObject::SetPos(float x, float y, float z)
{
	m_posX = x;
	m_posY = y;
	m_posZ = z;
}

void GSEObject::Draw(Renderer* renderer)
{
	renderer->DrawSolidRect(m_posX, m_posY, m_posZ, m_sizeX, 1, 1, 1, 1);
}
