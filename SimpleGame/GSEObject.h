#pragma once
#include "GSEGlobal.h"
#include "Renderer.h"

class GSEObject
{
public:
	GSEObject();
	~GSEObject();

	void SetSize(float x, float y, float z);
	void SetPos(float x, float y, float z);
	void GetPos(float* x, float* y, float* z);
	void SetMass(float mass);
	void SetVel(float x, float y, float z);
	void GetVel(float* x, float* y, float* z);
	float GetVelMag();
	void SetAcc(float x, float y, float z);
	void SetForce(float x, float y, float z);
	void SetType(int type);
	int GetType();
	void SetColor(float r, float g, float b, float a);
	
	void GetBBMin(float* x, float* y, float* z);
	void GetBBMax(float* x, float* y, float* z);

	void SetCoolTime(float coolTime);
	float GetCoolTime();
	bool IsCoolTimeExpired();
	void ResetCoolTimeExpired();

	void Draw(Renderer* renderer);


	void Update(float elapsedTime);

	void AddForce(float x, float y, float z, float elapsedTime);
private:

	float m_sizeX, m_sizeY, m_sizeZ = 0.f;
	float m_posX, m_posY, m_posZ = 0.f;
	float m_mass = 0.f;
	float m_velX, m_velY, m_velZ = 0.f;
	float m_accX, m_accY, m_accZ = 0.f;
	float m_forceX, m_forceY, m_forceZ = 0.f;
	float m_r, m_g, m_b, m_a;

	int m_type = TYPE_DEFAULT;

	float m_coolTime = 1.f;
	float m_remainCoolTime = 1.f;
	bool m_isCoolTimeExpired = false;
};

