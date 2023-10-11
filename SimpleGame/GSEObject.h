#pragma once
#include "Renderer.h"

class GSEObject
{
public:
	GSEObject();
	~GSEObject();

	void SetSize(float x, float y, float z);
	void SetPos(float x, float y, float z);
	void Draw(Renderer* renderer);
private:
	float m_sizeX, m_sizeY, m_sizeZ = 0.f;
	float m_posX, m_posY, m_posZ = 0.f;
};

