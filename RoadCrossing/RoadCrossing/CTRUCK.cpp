#include "CTRUCK.h"


CTRUCK::~CTRUCK()
{
}



void CTRUCK::DrawVehicle() {
	GotoXY(vehiclex, vehicley);
	SetColor(12);
	if (checkPosition(vehiclex, colBoundary - 1)) { cout << mTruck[0][0]; }
	SetColor(3);
	if (checkPosition(vehiclex + 1, colBoundary - 1)) { cout << mTruck[0][1]; }
	if (checkPosition(vehiclex + 2, colBoundary - 1)) { cout << mTruck[0][2]; }

	GotoXY(vehiclex, vehicley - 1);
	SetColor(5);
	if (checkPosition(vehiclex, colBoundary - 1)) { cout << mTruck[1][0]; }
	if (checkPosition(vehiclex + 1, colBoundary - 1)) { cout << mTruck[1][1]; }
	if (checkPosition(vehiclex + 2, colBoundary - 1)) { cout << mTruck[1][2]; }
	SetColor(7);
}

void CTRUCK::Move(int lengthBoundary, int x) {
	CVEHICLE::Move(lengthBoundary, x);
	vehiclex -= x;
	if (vehiclex <= 0) vehiclex += lengthBoundary;
}


