#pragma once
#include "Renderer.h"

class GSEObject
{
public:
	GSEObject();
	~GSEObject();

	void SetSize(float x, float y, float z);
	void SetPos(float x, float y, float z);
	void SetMass(float mass);
	void SetVel(float x, float y, float z);
	void SetAcc(float x, float y, float z);
	void SetForce(float x, float y, float z);

	void Draw(Renderer* renderer);
	void Update(float elapsedTime);

private:

	float m_sizeX, m_sizeY, m_sizeZ = 0.f;
	float m_posX, m_posY, m_posZ = 0.f;
	float m_mass = 0.f;
	float m_velX, m_velY, m_velZ = 0.f;
	float m_accX, m_accY, m_accZ = 0.f;
	float m_forceX, m_forceY, m_forceZ = 0.f;
};

