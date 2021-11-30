#pragma once
#include <iostream>
#include "CAnimal.h"
class CBird : public CAnimal 
{
	string imageBird[2];

public:
	CBird(int a, int b) :CAnimal(a, b)
	{
		imageBird[0] = " " + string(1, 223) + " ";
		imageBird[1] = string(1, 220) + " " + string(1, 220); // draw a bird
	}
	~CBird();
	void drawAnimal() override;
	void spawnAnimal(int boundary,int x); 

};

