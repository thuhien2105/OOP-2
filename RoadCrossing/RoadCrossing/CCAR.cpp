#include "CCAR.h"

CCAR::~CCAR()
{
}


void CCAR::DrawVehicle() {
	GotoXY(vehiclex, vehicley);
	SetColor(14);
	if (checkPosition(vehiclex, colBoundary - 1)) { cout << mCar[0][0]; }
	SetColor(8);
	if (checkPosition(vehiclex + 1, colBoundary - 1)) { cout << mCar[0][1]; }
	SetColor(14);
	if (checkPosition(vehiclex + 2, colBoundary - 1)) { cout << mCar[0][2]; }

	GotoXY(vehiclex, vehicley - 1);
	SetColor(12);
	if (checkPosition(vehiclex, colBoundary - 1)) { cout << mCar[1][0]; }
	if (checkPosition(vehiclex + 1, colBoundary - 1)) { cout << mCar[1][1]; }
	if (checkPosition(vehiclex + 2, colBoundary - 1)) { cout << mCar[1][2]; }
	
	SetColor(7);
}

void CCAR::Move(int lengthBoundary, int x) {
	CVEHICLE::Move(lengthBoundary, x);
	vehiclex = (vehiclex + x) % lengthBoundary;
	if (vehiclex == 0) vehiclex = lengthBoundary;
}



