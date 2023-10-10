#pragma once
#include "GSEObject.h"

#define MAX_NUM_OBJECT 1000

class GSEObjectMgr
{
public:
	GSEObjectMgr();
	~GSEObjectMgr();
	int AddObject(float x, float y, float z);
	bool DeleteObject(int id);
private:
	GSEObject* m_Objects[MAX_NUM_OBJECT];
};

