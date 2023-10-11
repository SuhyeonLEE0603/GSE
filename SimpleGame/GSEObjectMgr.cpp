#include "stdafx.h"
#include "GSEObjectMgr.h"

GSEObjectMgr::GSEObjectMgr()
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		m_Objects[i] = NULL;
	}
	
}

GSEObjectMgr::~GSEObjectMgr()
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if(m_Objects[i] != NULL){
			delete m_Objects[i];
			m_Objects[i] = NULL;
		}

	}
}

int GSEObjectMgr::AddObject(float x, float y, float z, float sx, float sy, float sz)
{
	// Find empty slot
	int index = -1;
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] == NULL) {
			index = i;
			break;
		}
	}
	if (index >= 0) {
		m_Objects[index] = new GSEObject();
		m_Objects[index]->SetPos(x, y, z);
		m_Objects[index]->SetSize(sx, sy, sz);
		return index;
	}

	std::cout << "No more empty object slot!" << std::endl;

	return index;
}

bool GSEObjectMgr::DeleteObject(int id)
{
	if (m_Objects[id] != NULL) {
		delete m_Objects[id];
		m_Objects[id] = NULL;
		return true;
	}

	std::cout << "Index " << id << " already deleted." << std::endl;
	return false;
}

void GSEObjectMgr::DrawAllObjects(Renderer* renderer)
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] != NULL) {
			m_Objects[i]->Draw(renderer);
		}
	}
}
