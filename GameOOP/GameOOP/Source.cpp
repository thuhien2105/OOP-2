#pragma once
#include "Console.h"

enum MOVING {
	ILDE = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

MOVING moving;

int main()
{
	FixConsoleWindow();
	GetSizeOfConsole();
	HideCursor();

	return 0;
}