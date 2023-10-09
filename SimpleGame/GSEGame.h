#pragma once
#include "Renderer.h"

class GSEGame
{
public:
	GSEGame(int windowSizeX, int windowSizeY);
	~GSEGame();
	void DrawAll();

private:
	Renderer *m_renderer;

};

