#pragma once
#include "Renderer.h"
#include "GSEObjectMgr.h"

class GSEGame
{
public:
	GSEGame(int windowSizeX, int windowSizeY);
	~GSEGame();
	void DrawAll(float elapsedTime);

private:
	Renderer *m_Renderer;
	GSEObjectMgr* m_ObjectMgr;
};

