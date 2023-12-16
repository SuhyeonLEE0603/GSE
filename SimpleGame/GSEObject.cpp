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

	m_type = TYPE_DEFAULT;
	
	m_coolTime = 0.01f;
	m_remainCoolTime = m_coolTime;
	m_isCoolTimeExpired = false;

	m_r = m_g = m_b = m_a = 1.f;
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

void GSEObject::GetPos(float* x, float* y, float* z)
{
	*x = m_posX;
	*y = m_posY;
	*z = m_posZ;
}

void GSEObject::SetMass(float mass)
{
	m_mass = mass;
}

float GSEObject::GetMass()
{
	return m_mass;
}

void GSEObject::SetVel(float x, float y, float z)
{
	m_velX = x;
	m_velY = y;
	m_velZ = z;
}

void GSEObject::GetVel(float* x, float* y, float* z)
{
	*x = m_velX;
	*y = m_velY;
	*z = m_velZ;
}

float GSEObject::GetVelMag()
{
	float mag = sqrtf(m_velX * m_velX + m_velY * m_velY + m_velZ * m_velZ);
	return mag;
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

void GSEObject::SetType(int type)
{
	m_type = type;
}

int GSEObject::GetType()
{
	return m_type;
}

void GSEObject::SetColor(float r, float g, float b, float a)
{
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

void GSEObject::GetBBMin(float* x, float* y, float* z)
{
	*x = m_posX - m_sizeX / 2.f;
	*y = m_posY - m_sizeY / 2.f;
	*z = m_posZ - m_sizeZ / 2.f;
}

void GSEObject::GetBBMax(float* x, float* y, float* z)
{
	*x = m_posX + m_sizeX / 2.f;
	*y = m_posY + m_sizeY / 2.f;
	*z = m_posZ + m_sizeZ / 2.f;
}

void GSEObject::SetID(int id)
{
	m_ID = id;
}

int GSEObject::GetID()
{
	return m_ID;
}

void GSEObject::SetParent(int id)
{
	m_parentID = id;
}

bool GSEObject::isAncestor(int id)
{
	if (m_parentID == id) {
		return true;
	}
	return false;
}

void GSEObject::SetHP(float hp)
{
	m_HP = hp;
}

float GSEObject::GetHP()
{
	return m_HP;
}

void GSEObject::SetCoolTime(float coolTime)
{
	m_coolTime = coolTime;
}

float GSEObject::GetCoolTime()
{
	return m_coolTime;
}

bool GSEObject::IsCoolTimeExpired()
{
	return m_isCoolTimeExpired;
}

void GSEObject::ResetCoolTimeExpired()
{
	m_remainCoolTime = m_coolTime;
}

void GSEObject::Draw(Renderer* renderer)
{
	renderer->DrawSolidRect(m_posX, m_posY, m_posZ, m_sizeX,
		m_r, m_g, m_b, m_a);
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
	//m_velX = m_velX + m_accX * t;
	//m_velY = m_velY + m_accY * t;
	//m_velZ = m_velZ + m_accZ * t;

	// pos
	//m_posX = m_posX + m_velX * t + 0.5f * m_accX * tt;
	//m_posY = m_posY + m_velY * t + 0.5f * m_accY * tt;
	//m_posZ = m_posZ + m_velZ * t + 0.5f * m_accZ * tt;

	// m_velX ... apply friction
	// clac normal force
	float normalForce = m_mass * GRAVITY;

	float frictionCoef = 1000.f;

	float friction = frictionCoef + normalForce;

	float frictionDirX = -m_velX;
	float frictionDirY = -m_velY;

	float mag = sqrtf(frictionDirX * frictionDirX + frictionDirY * frictionDirY);

	if (mag > FLT_EPSILON) {
		frictionDirX = frictionDirX / mag;
		frictionDirY = frictionDirY / mag;

		float frictionForceX = frictionDirX * friction;
		float frictionForceY = frictionDirY * friction;

		float frictionAccX = frictionForceX / m_mass;
		float frictionAccY = frictionForceY / m_mass;

		float resultVelX = m_velX + frictionAccX * elapsedTime;
		float resultVelY = m_velY + frictionAccY * elapsedTime;
		float resultVelZ = m_velZ;

		if (resultVelX * m_velX < 0.f) {
			m_velX = 0.f;
		}
		else {
			m_velX = resultVelX;
		}

		if (resultVelY * m_velY < 0.f) {
			m_velY = 0.f;
		}
		else {
			m_velY = resultVelY;
		}

		if (resultVelZ * m_velZ < 0.f) {
			m_velZ = 0.f;
		}
		else {
			m_velZ = resultVelZ;
		}
	}
	
	m_posX = m_posX + m_velX * t;
	m_posY = m_posY + m_velY * t;
	m_posZ = m_posZ + m_velZ * t;

	m_remainCoolTime -= elapsedTime;
	if (m_remainCoolTime < FLT_EPSILON) {
		m_isCoolTimeExpired = true;
	}
	else {
		m_isCoolTimeExpired = false;

	}

}

void GSEObject::AddForce(float x, float y, float z, float elapsedTime)
{
	// calc acc
	float accX = x / m_mass;
	float accY = y / m_mass;
	float accZ = z / m_mass;

	m_velX = m_velX + accX * elapsedTime;
	m_velY = m_velY + accY * elapsedTime;
	m_velZ = m_velZ + accZ * elapsedTime;
}
