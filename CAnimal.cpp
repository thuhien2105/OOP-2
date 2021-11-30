#include "CAnimal.h"

bool CAnimal::checkPos(int x, int boundary)
{
	if (x <= boundary && x >= 1) return 1;
	return 0;
}

void CAnimal::deleteAnimal()
{
	GotoXY(animalx, animaly -1 );
	if (animalx < colBoundary) cout << " ";
	if (animalx + 1 < colBoundary) cout << " ";
	if (animalx + 2 < colBoundary)cout << " ";

	GotoXY(animalx, animaly);
	if (animalx < colBoundary) cout << " ";
	if (animalx + 1 < colBoundary) cout << " ";
	if (animalx + 2 < colBoundary)cout << " ";
}

CAnimal::~CAnimal()
{
}

void CAnimal::spawnAnimal(int lboundary, int x)
{
	deleteAnimal();
}
