#include "CTRUCK.h"




CTRUCK::CTRUCK(int x, int y) :CVEHICLE(x, y) {
	mTruck[1] = " " + string(1, 220) + string(1, 220);
	mTruck[0] = string(1, 220) + string(1, 219) + string(1, 219);
}

CTRUCK::~CTRUCK()
{
}



void CTRUCK::DrawVehicle() {
	GotoXY(mX, mY);
	SetColor(12);
	if (checkPosition(mX, colBoundary - 1)) { cout << mTruck[0][0]; }
	SetColor(3);
	if (checkPosition(mX + 1, colBoundary - 1)) { cout << mTruck[0][1]; }
	if (checkPosition(mX + 2, colBoundary - 1)) { cout << mTruck[0][2]; }

	GotoXY(mX, mY - 1);
	SetColor(5);
	if (checkPosition(mX, colBoundary - 1)) { cout << mTruck[1][0]; }
	if (checkPosition(mX + 1, colBoundary - 1)) { cout << mTruck[1][1]; }
	if (checkPosition(mX + 2, colBoundary - 1)) { cout << mTruck[1][2]; }
	SetColor(7);
}

void CTRUCK::Move(int lengthBoundary, int x) {
	CVEHICLE::Move(lengthBoundary, x);
	mX -= x;
	if (mX <= 0) mX += lengthBoundary;
}


