#pragma once
#include "CVEHICLE.h"
class CCAR :public CVEHICLE
{
	string mCar[2];
public:
	void DrawVehicle() override;

	void Move(int lengthBoundary, int x = 1);
	CCAR(int x, int y);
	~CCAR();
};

