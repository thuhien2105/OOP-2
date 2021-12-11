#pragma once
#include "Console.h"
#include <iostream>
#include <string>

using namespace std;

class CANIMAL
{
private:
	void mDelete();
protected:
	int animalx, animaly;
	bool checkPosition(int x, int boundary);
public:
	CANIMAL(int x, int y) :animalx(x), animaly(y) {}
	virtual ~CANIMAL();

	virtual void Move(int lengthBoundary, int x = 1);
	virtual void DrawAnimal() = 0;
	void saveGame(ofstream& fo);
};

