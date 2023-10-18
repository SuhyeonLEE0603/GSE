#include "stdafx.h"
#include "GSEGame.h"
#include <math.h>

GSEGame::GSEGame(int windowSizeX, int windowSizeY)
{
	m_Renderer = new Renderer(windowSizeX, windowSizeY);

	m_ObjectMgr = new GSEObjectMgr();

	// create test objects
	for (int i = 0; i < 1000; ++i) {
		float x = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float y = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float z = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;

		float sX = 5.f * (float)rand() / (float)RAND_MAX;
		float sY = 5.f * (float)rand() / (float)RAND_MAX;
		float sZ = 5.f * (float)rand() / (float)RAND_MAX;

		float mass = 1.f;

		float velX = (10.f * (float)rand() / (float)RAND_MAX) - 5.0f;
		float velY = (10.f * (float)rand() / (float)RAND_MAX) - 5.0f;
		float velZ = (10.f * (float)rand() / (float)RAND_MAX) - 5.0f;

		float accX = 0.f;
		float accY = -20.f;
		float accZ = 0.f;

		float forceX = 0.f;
		float forceY = 0.f;
		float forceZ = 0.f;

		int id = m_ObjectMgr->AddObject(x, y, z, 
			sX, sY, sZ,
			mass,
			velX, velY, velZ,
			accX, accY, accZ,
			forceX, forceY, forceZ);
	}

}


GSEGame::~GSEGame()
{
	delete m_Renderer;
	m_Renderer = NULL;

	delete m_ObjectMgr;
	m_ObjectMgr = NULL;

}

void GSEGame::DrawAll(float elapsedTime)
{
	// objmgr
	if (m_Renderer != NULL) {
		m_ObjectMgr->UpdateAllObjects(elapsedTime);
		m_ObjectMgr->DrawAllObjects(m_Renderer, elapsedTime);
	}
}
