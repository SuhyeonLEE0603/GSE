#pragma once
#include "GSEObject.h"
#include "Renderer.h"

#define MAX_NUM_OBJECT 1000

class GSEObjectMgr
{
public:
	GSEObjectMgr();
	~GSEObjectMgr();
	int AddObject(float posX, float posY, float posZ,
				  float sizeX, float sizeY, float sizeZ,
				  float mass,
				  float velX, float velY, float velZ,
				  float accX, float accY, float accZ,
				  float forceX, float forceY, float forceZ);

	bool DeleteObject(int id);

	void DrawAllObjects(Renderer* renderer, float elapsedTime);
	void UpdateAllObjects(float elapsedTime);

private:
	GSEObject* m_Objects[MAX_NUM_OBJECT];
};

