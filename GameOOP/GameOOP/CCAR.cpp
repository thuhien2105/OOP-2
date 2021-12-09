#include "CCAR.h"




CCAR::CCAR(int x, int y) :CVEHICLE(x, y) {
	mCar[0] = string(1, 219) + string(1, 219) + string(1, 219);
	mCar[1] = " " + string(1, 220) + " ";
}


CCAR::~CCAR()
{
}


void CCAR::DrawVehicle() {
	GotoXY(mX, mY);
	SetColor(14);
	if (checkPosition(mX, colBoundary - 1)) { cout << mCar[0][0]; }
	SetColor(8);
	if (checkPosition(mX + 1, colBoundary - 1)) { cout << mCar[0][1]; }
	SetColor(14);
	if (checkPosition(mX + 2, colBoundary - 1)) { cout << mCar[0][2]; }

	GotoXY(mX, mY - 1);
	SetColor(12);
	if (checkPosition(mX, colBoundary - 1)) { cout << mCar[1][0]; }
	if (checkPosition(mX + 1, colBoundary - 1)) { cout << mCar[1][1]; }
	if (checkPosition(mX + 2, colBoundary - 1)) { cout << mCar[1][2]; }

	SetColor(7);
}

void CCAR::Move(int lengthBoundary, int x) {
	CVEHICLE::Move(lengthBoundary, x);
	mX = (mX + x) % lengthBoundary;
	if (mX == 0) mX = lengthBoundary;
}



