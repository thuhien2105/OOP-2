#pragma once
#include "CVEHICLE.h"

class CTRUCK :public CVEHICLE {
	string mTruck[2];
public:

	void DrawVehicle() override;

	void Move(int lengthBoundary, int x = 1);


	CTRUCK(int x, int y);
	~CTRUCK();

};


