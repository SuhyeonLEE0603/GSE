#include "stdafx.h"
#include "GSEGame.h"
#include <math.h>

GSEGame::GSEGame(int windowSizeX, int windowSizeY)
{
	m_Renderer = new Renderer(windowSizeX, windowSizeY);

	m_ObjectMgr = new GSEObjectMgr();

	// create hero object
	m_Heroid = m_ObjectMgr->AddObject(0, 0, 0,
		30, 30, 30,
		1,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		TYPE_HERO);

	// create test objects
	for (int i = 0; i < 1000; ++i) {
		float x = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float y = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;
		float z = (500.f * (float)rand() / (float)RAND_MAX) - 250.f;

		float sX = 5.f * (float)rand() / (float)RAND_MAX;
		float sY = 5.f * (float)rand() / (float)RAND_MAX;
		float sZ = 5.f * (float)rand() / (float)RAND_MAX;

		float mass = 1.f;

		float velX = (10.f * (float)rand() / (float)RAND_MAX) - 5.f;
		float velY = (10.f * (float)rand() / (float)RAND_MAX) - 5.f;
		float velZ = (10.f * (float)rand() / (float)RAND_MAX) - 5.f;

		float accX = 0.f;
		float accY = 0.f;
		float accZ = 0.f;

		float forceX = 0.f;
		float forceY = 0.f;
		float forceZ = 0.f;

		int id = m_ObjectMgr->AddObject(x, y, z, 
			sX, sY, sZ,
			mass,
			velX, velY, velZ,
			accX, accY, accZ,
			forceX, forceY, forceZ,
			TYPE_DEFAULT);
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

void GSEGame::KeyInput(GSEUserInterface* ui)
{
	float vx, vy, vz;
	vx = vy = vz = 0.f;
	float velAmount = 100.f;
	if (ui->Is_SP_Arrow_Up_Down())
	{
		vy += velAmount;
	}
	if (ui->Is_SP_Arrow_Down_Down())
	{
		vy -= velAmount;
	}
	if (ui->Is_SP_Arrow_Right_Down())
	{
		vx += velAmount;
	}
	if (ui->Is_SP_Arrow_Left_Down())
	{
		vx -= velAmount;
	}
	m_ObjectMgr->SetObjectVel(m_Heroid, vx, vy, vz);
}
