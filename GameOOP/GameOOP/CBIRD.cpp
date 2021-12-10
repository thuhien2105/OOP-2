#include "CBIRD.h"


CBIRD::~CBIRD()
{
}

void CBIRD::DrawAnimal() {
	GotoXY(animalx, animaly);
	SetColor(12);
	if (checkPosition(animalx, colBoundary - 1)) { cout << mBird[0][0]; }
	if (checkPosition(animalx + 1, colBoundary - 1)) { cout << mBird[0][1]; }
	if (checkPosition(animalx + 2, colBoundary - 1)) { cout << mBird[0][2]; }

	GotoXY(animalx, animaly - 1);
	SetColor(15);
	if (checkPosition(animalx, colBoundary - 1)) { cout << mBird[1][0]; }
	if (checkPosition(animalx + 1, colBoundary - 1)) { cout << mBird[1][1]; }
	if (checkPosition(animalx + 2, colBoundary - 1)) { cout << mBird[1][2]; }

	SetColor(7);
}

void CBIRD::Move(int lengthBoundary, int x) {
	CANIMAL::Move(lengthBoundary, x);

	animalx -= x;
	if (animalx <= 0) animalx += lengthBoundary;
}
