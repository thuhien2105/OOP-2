#pragma once
#include "Console.h"
#include <iostream>
using namespace std;
#include <string>
class CAnimal
{
protected:
	int animalx, animaly;
	bool checkPos(int x,int boundary);
public:
	void deleteAnimal();
	virtual void drawAnimal() = 0;
	virtual ~CAnimal();
	CAnimal(int a, int b) 
	{
		animalx = a;
		animaly = b;
	}
	void spawnAnimal(int lboundary, int x = 1);
};

