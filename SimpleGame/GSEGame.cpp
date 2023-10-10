#include "stdafx.h"
#include "GSEGame.h"

GSEGame::GSEGame(int windowSizeX, int windowSizeY)
{
	m_Renderer = new Renderer(windowSizeX, windowSizeY);

	m_ObjectMgr = new GSEObjectMgr();

	int id = m_ObjectMgr->AddObject(0, 0, 0);

	m_ObjectMgr->DeleteObject(id);
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
	m_Renderer->DrawSolidRect(0, 0, 0, 10, 1, 1, 1, 1);
}
