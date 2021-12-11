#include "CDINAUSOR.h"


CDINAUSOR::~CDINAUSOR()
{
}

void CDINAUSOR::DrawAnimal() {
	GotoXY(animalx, animaly);
	SetColor(3);
	if (checkPosition(animalx, colBoundary - 1)) cout << mDinausor[0][0];
	SetColor(10);
	if (checkPosition(animalx + 1, colBoundary - 1)) cout << mDinausor[0][1];
	if (checkPosition(animalx + 2, colBoundary - 1)) cout << mDinausor[0][2];

	GotoXY(animalx, animaly - 1);
	SetColor(12); 
	if (checkPosition(animalx, colBoundary - 1)) cout << mDinausor[1][0];
	if (checkPosition(animalx + 1, colBoundary - 1)) cout << mDinausor[1][1];
	if (checkPosition(animalx + 2, colBoundary - 1)) cout << mDinausor[1][2];

	SetColor(7);
}

void CDINAUSOR::Move(int lengthBoundary, int x) {
	CANIMAL::Move(lengthBoundary, x);
	animalx = (animalx + x) % lengthBoundary;
	if (animalx == 0) animalx = lengthBoundary;
}
