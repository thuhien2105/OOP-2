#include "CVEHICLE.h"
#include "Console.h"


void CVEHICLE::mDelete() {
	GotoXY(vehiclex, vehicley - 1);
	if (vehiclex < colBoundary ) cout << " ";
	if (vehiclex + 1 < colBoundary ) cout << " ";
	if (vehiclex + 2 < colBoundary ) cout << " ";

	GotoXY(vehiclex, vehicley);
	if (vehiclex < colBoundary ) cout << " ";
	if (vehiclex + 1 < colBoundary ) cout << " ";
	if (vehiclex + 2 < colBoundary ) cout << " ";
}

bool CVEHICLE::checkPosition(int x, int boundary) {
	return x <= boundary && x >= 1;
}

CVEHICLE::CVEHICLE(int x, int y)
{
	vehiclex = x;
	vehicley = y;
}


CVEHICLE::~CVEHICLE()
{
}

void CVEHICLE::Move(int lengthBoundary, int x) {
	mDelete();
}

void CVEHICLE::saveGame(ofstream& fo) {
	fo << vehiclex << endl;
}


