#pragma once
#include <iostream>
using namespace std;
#include "CAnimal.h"
class CDinasaur:public CAnimal
{
	string imageDinasaur[2];
public:
	CDinasaur(int a, int b) :CAnimal(a, b)
	{
		imageDinasaur[0] = string(1, 220) + string(1, 219) + string(1, 223);
		imageDinasaur[1] = "  " + string(1, 220);//draw a dinasaur
	}
	~CDinasaur();
	void drawAnimal() override;
	void spawnAnimal(int boundary, int x);
};

