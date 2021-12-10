#include "CANIMAL.h"



CANIMAL::~CANIMAL()
{
}

void CANIMAL::Move(int lengthBoundary, int x) {
	mDelete();
}

void CANIMAL::saveGame(ofstream& fo) {
	fo << animalx << endl;
}

void CANIMAL::mDelete() {
	GotoXY(animalx, animaly - 1);
	if (animalx < colBoundary) cout << " ";
	if (animalx + 1 < colBoundary) cout << " ";
	if (animalx + 2 < colBoundary) cout << " ";

	GotoXY(animalx, animaly);
	if (animalx < colBoundary) cout << " ";
	if (animalx + 1 < colBoundary) cout << " ";
	if (animalx + 2 < colBoundary) cout << " ";

}

bool CANIMAL::checkPosition(int x, int boundary) {
	return x <= boundary && x >= 1;
}