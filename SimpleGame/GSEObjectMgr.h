#pragma once
#include "GSEObject.h"
#include "Renderer.h"

#define MAX_NUM_OBJECT 1000

class GSEObjectMgr
{
public:
	GSEObjectMgr();
	~GSEObjectMgr();
	int AddObject(float x, float y, float z, float sx, float sy, float sz);
	bool DeleteObject(int id);

	void DrawAllObjects(Renderer* renderer);

private:
	GSEObject* m_Objects[MAX_NUM_OBJECT];
};

