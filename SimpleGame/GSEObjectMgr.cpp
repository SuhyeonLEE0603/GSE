#include "stdafx.h"
#include "GSEObjectMgr.h"

GSEObjectMgr::GSEObjectMgr()
{
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		m_Objects[i] = NULL;
		m_ObjectOverlap[i] = false;
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

void GSEObjectMgr::SetCoolTime(int id, float coolTime)
{
	if (m_Objects[id] != NULL)
	{
		m_Objects[id]->SetCoolTime(coolTime);
	}
	else {

	}
}

float GSEObjectMgr::GetCoolTime(int id)
{
	if (m_Objects[id] != NULL)
	{
		return m_Objects[id]->GetCoolTime();
	}
	else {
		return 0.f;
	}
}

bool GSEObjectMgr::IsCoolTimeExpired(int id)
{
	if (m_Objects[id] != NULL)
	{
		return m_Objects[id]->IsCoolTimeExpired();
	}
	else {
		return false;
	}
}

void GSEObjectMgr::ResetCoolTimeExpired(int id)
{
	if (m_Objects[id] != NULL)
	{
		return m_Objects[id]->ResetCoolTimeExpired();
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

void GSEObjectMgr::DoGarbageCollect()
{
	// find garbage & delete it
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] != NULL) {
			// Bullet garbage
			int type = m_Objects[i]->GetType();
			if (type == TYPE_BULLET) {
				float mag = m_Objects[i]->GetVelMag();
				if (mag < FLT_EPSILON) {
					DeleteObject(i);
				}
			}
		}
	}
}

void GSEObjectMgr::DoAllObjectsOverlapTest()
{
	memset(m_ObjectOverlap, 0, sizeof(bool) * MAX_NUM_OBJECT);

	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		for (int j = i + 1; j < MAX_NUM_OBJECT; j++) {
			bool isOverlap = BBOverlap(i, j);
			if (isOverlap) {
				m_ObjectOverlap[i] = true;
				m_ObjectOverlap[j] = true;
			}
		}
	}

	// overlaps
	for (int i = 0; i < MAX_NUM_OBJECT; ++i) {
		if (m_Objects[i] != NULL) {
			if (m_ObjectOverlap[i]) {
				m_Objects[i]->SetColor(1, 0, 0, 1);
			}
			else {
				m_Objects[i]->SetColor(1, 1, 1, 1);
			}
		}
	}
}

bool GSEObjectMgr::BBOverlap(int srcID, int dstID)
{
	if (m_Objects[srcID] != NULL && m_Objects[dstID] != NULL) {
		GSEObject* src = m_Objects[srcID];
		GSEObject* dst = m_Objects[dstID];

		float srcMinX, srcMinY, srcMinZ;
		float srcMaxX, srcMaxY, srcMaxZ;
		float dstMinX, dstMinY, dstMinZ;
		float dstMaxX, dstMaxY, dstMaxZ;

		src->GetBBMin(&srcMinX, &srcMinY, &srcMinZ);
		src->GetBBMax(&srcMaxX, &srcMaxY, &srcMaxZ);
		dst->GetBBMin(&dstMinX, &dstMinY, &dstMinZ);
		dst->GetBBMax(&dstMaxX, &dstMaxY, &dstMaxZ);

		if (srcMinX > dstMaxX) {
			return false;
		}
		if (srcMaxX < dstMinX) {
			return false;
		}
		if (srcMinY > dstMaxY) {
			return false;
		}
		if (srcMaxY < dstMinY) {
			return false;
		}
		if (srcMinZ > dstMaxZ) {
			return false;
		}
		if (srcMaxZ < dstMaxZ) {
			return false;
		}

		return true;
	}

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

