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

int GSEObjectMgr::AddObject(float posX, float posY, float posZ,
							float sizeX, float sizeY, float sizeZ,
							float mass,
							float velX, float velY, float velZ,
							float accX, float accY, float accZ,
							float forceX, float forceY, float forceZ,
							int type)
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
		m_Objects[index]->SetPos(posX, posY, posZ);
		m_Objects[index]->SetSize(sizeX, sizeY, sizeZ);
		m_Objects[index]->SetMass(mass);
		m_Objects[index]->SetVel(velX, velY, velZ);
		m_Objects[index]->SetAcc(accX, accY, accZ);
		m_Objects[index]->SetForce(forceX, forceY, forceZ);
		m_Objects[index]->SetType(type);
		return index;
	}

	std::cout << "No more empty object slot!" << std::endl;

	return index;
}

void GSEObjectMgr::SetObjectVel(int id, float vx, float vy, float vz)
{
	if (m_Objects[id] != NULL) 
	{
		m_Objects[id]->SetVel(vx, vy, vz);
	}
	else 
	{
			// log..
	}
}

void GSEObjectMgr::GetObjectVel(int id, float* vx, float* vy, float* vz)
{
	if (m_Objects[id] != NULL)
	{
		m_Objects[id]->GetVel(vx, vy, vz);
	}
	else {

	}

}

void GSEObjectMgr::GetObjectPos(int id, float* x, float* y, float* z)
{
	if (m_Objects[id] != NULL)
	{
		m_Objects[id]->GetPos(x, y, z);
	}
	else {

	}
}

void GSEObjectMgr::AddObjectForce(int id, float x, float y, float z, float elapsedTime)
{
	if (m_Objects[id] != NULL)
	{
		m_Objects[id]->AddForce(x, y, z, elapsedTime);
	}
	else
	{
		// log..
	}
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

void GSEObjectMgr::DrawAllObjects(Renderer* renderer, float elapsedTime)
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] != NULL) {
			m_Objects[i]->Draw(renderer);
		}
	}
}

void GSEObjectMgr::UpdateAllObjects(float elapsedTime)
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] != NULL) {
			m_Objects[i]->Update(elapsedTime);
		}
	}
}
