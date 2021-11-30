#include "CBird.h"

CBird::~CBird()
{
}
void CBird::spawnAnimal(int boundary, int x) 
{
	CAnimal::spawnAnimal(boundary, x);
	animalx -= x;
	if (animalx <= 0) animalx += boundary;
}
void CBird::drawAnimal()
{
	GotoXY(animalx, animaly);
	SetColor(15);
	if (checkPos(animalx, colBoundary - 1))
	{
		cout << imageBird[0][0];
	}
	if (checkPos(animalx + 1, colBoundary - 1))
	{
		cout << imageBird[0][1];
	}
	if (checkPos(animalx + 2, colBoundary - 1))
	{
		cout << imageBird[0][2];
	}



	GotoXY(animalx, animaly - 1);
	SetColor(16);
	if (checkPos(animalx, colBoundary - 1))
	{
		cout << imageBird[1][0];
	}
	if (checkPos(animalx + 1, colBoundary - 1))
	{
		cout << imageBird[1][1];
	}
	if (checkPos(animalx + 2, colBoundary - 1))
	{
		cout << imageBird[1][2];
	}

	SetColor(7);
}
