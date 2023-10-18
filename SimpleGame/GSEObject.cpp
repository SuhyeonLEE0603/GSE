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

	m_mass = -10.f;

	m_velX = 0.f; 
	m_velY = 0.f; 
	m_velZ = 0.f;

	m_accX = 0.f;
	m_accY = 0.f;
	m_accZ = 0.f;

	m_forceX = 0.f;
	m_forceY = 0.f;
	m_forceZ = 0.f;

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

void GSEObject::SetMass(float mass)
{
	m_mass = mass;
}

void GSEObject::SetVel(float x, float y, float z)
{
	m_velX = x;
	m_velY = y;
	m_velZ = z;
}

void GSEObject::SetAcc(float x, float y, float z)
{
	m_accX = x;
	m_accY = y;
	m_accZ = z;
}

void GSEObject::SetForce(float x, float y, float z)
{
	m_forceX = x;
	m_forceY = y;
	m_forceZ = z;
}

void GSEObject::Draw(Renderer* renderer)
{
	renderer->DrawSolidRect(m_posX, m_posY, m_posZ, m_sizeX, 1, 1, 1, 1);
}

void GSEObject::Update(float elapsedTime)
{
	float t = elapsedTime;
	float tt = t * t;

	// accel
	//m_accX = m_forceX / m_mass;
	//m_accY = m_forceY / m_mass;
	//m_accZ = m_forceZ / m_mass;

	// vel
	m_velX = m_velX + m_accX * t;
	m_velY = m_velY + m_accY * t;
	m_velZ = m_velZ + m_accZ * t;

	// pos
	m_posX = m_posX + m_velX * t + 0.5f * m_accX * tt;
	m_posY = m_posY + m_velY * t + 0.5f * m_accY * tt;
	m_posZ = m_posZ + m_velZ * t + 0.5f * m_accZ * tt;
}
