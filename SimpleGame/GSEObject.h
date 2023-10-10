#pragma once
class GSEObject
{
public:
	GSEObject();
	~GSEObject();

	void SetSize(float x, float y, float z);

private:
	float sizeX, sizeY, sizeZ = 0.f;
};

