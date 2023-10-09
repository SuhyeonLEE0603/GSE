#include "stdafx.h"
#include "GSEGame.h"

GSEGame::GSEGame(int windowSizeX, int windowSizeY)
{
	m_renderer = new Renderer(windowSizeX, windowSizeY);
}

GSEGame::~GSEGame()
{
}

void GSEGame::DrawAll()
{
	m_renderer->DrawSolidRect(0, 0, 0, 10, 1, 1, 1, 1);
}
