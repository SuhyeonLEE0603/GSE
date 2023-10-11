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
		int id = m_ObjectMgr->AddObject(x, y, z, sX, sY, sZ);
		
	}

}


GSEGame::~GSEGame()
{
	delete m_Renderer;
	m_Renderer = NULL;

	delete m_ObjectMgr;
	m_ObjectMgr = NULL;

}

void GSEGame::DrawAll()
{
	// objmgr
	if (m_Renderer != NULL) {
		m_ObjectMgr->DrawAllObjects(m_Renderer);
	}
}
