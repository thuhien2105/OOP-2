#include "CDinasaur.h"

CDinasaur::~CDinasaur()
{
}

void CDinasaur::drawAnimal()
{
	GotoXY(animalx, animaly);
	SetColor(6);
	if (checkPos(animalx, colBoundary - 1)) cout << imageDinasaur[0][0];
	SetColor(3);
	if (checkPos(animalx + 1, colBoundary - 1)) cout << imageDinasaur[0][1];
	if (checkPos(animalx + 2, colBoundary - 1)) cout << imageDinasaur[0][2];

	GotoXY(animalx, animaly - 1);
	SetColor(13);
	if (checkPos(animalx, colBoundary - 1)) cout << imageDinasaur[1][0];
	if (checkPos(animalx + 1, colBoundary - 1)) cout << imageDinasaur[1][1];
	if (checkPos(animalx + 2, colBoundary - 1)) cout << imageDinasaur[1][2];

	SetColor(8);
}
void CDinasaur::spawnAnimal(int boundary, int x)
{
	CAnimal::spawnAnimal(boundary, x);
	animalx = (animalx + x) % boundary;
	if (animalx == 0) animalx = boundary;
}

