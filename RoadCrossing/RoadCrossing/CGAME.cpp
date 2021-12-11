#include "CGAME.h"
#include <ctime>
#include "CTRUCK.h"
#include "CCAR.h"
#include "CBIRD.h"
#include "CDINAUSOR.h"



void CGAME::SpawnObject() {

	m_block = ceil(((float)colBoundary - 2) / (float)m_level);
	mVehicles.clear();
	mAnimals.clear();

	for (int i = 0; i < m_level; ++i) {
		mAnimals.push_back(new CDINAUSOR(m_block * i + 1, LANE_1));
		mAnimals.push_back(new CBIRD(m_block * i + 1, LANE_2));
		mVehicles.push_back(new CCAR(m_block * i + 1, LANE_3));
		mVehicles.push_back(new CTRUCK(m_block * i + 1, LANE_4));
	}
}

void CGAME::printLevel() {
	GotoXY(XINFO-5, YINFO);
	SetColor(10);
	switch (m_level) {
	case LEVEL_1: {
		cout << "-LEVEL 1-";
		break;
	}
	case LEVEL_2: {
		cout << "-LEVEL 2-";
		break;
	}
	case LEVEL_3: {
		cout << "-LEVEL 3-";
		break;
	}
	case LEVEL_4: {
		cout << "-LEVEL 4-";
		break;
	}
	case LEVEL_5: {
		cout << "-LEVEL 5-";
		break;
	}
	case LEVEL_6: {
		cout << "-LEVEL 6-";
		break;
	}
	case LEVEL_7: {
		cout << "-MAX LEVEL-";
		SetColor(11); GotoXY(100, 9); cout << "||_ YOU WIN _||";
		break;
	}
	default: break;
	}
}

void CGAME::printHelp() {
	GotoXY(XINFO-7 , YINFO - 7);
	SetColor(12); cout << "|[___HELP___]|";

	GotoXY(XINFO - 12, YINFO - 6);
	SetColor(11); cout << "W";
	SetColor(8);  cout << "/";
	SetColor(11); cout << "S";
	SetColor(8);  cout << "/";
	SetColor(11); cout << "A";
	SetColor(8);  cout << "/";
	SetColor(11); cout << "D";
	SetColor(8);  cout << ":Up|Down|Left|Right";

	GotoXY(XINFO - 12, YINFO - 5);
	SetColor(8); cout << "Press ";
	SetColor(11); cout << "P";
	SetColor(8);  cout << " to PAUSE game";

	GotoXY(XINFO - 12, YINFO - 4);
	SetColor(8); cout << "Press ";
	SetColor(11); cout << "T";
	SetColor(8);  cout << " to LOAD game";

	GotoXY(XINFO - 12, YINFO - 3);
	SetColor(8); cout << "Press ";
	SetColor(11); cout << "L";
	SetColor(8);  cout << " to SAVE game";

	GotoXY(XINFO - 12, YINFO - 2);
	SetColor(8); cout << "Press ";
	SetColor(11); cout << "B";
	SetColor(8);  cout << " to BACK game";

	GotoXY(XINFO - 12, YINFO - 1);
	SetColor(8); cout << "Press ";
	SetColor(11); cout << "ESC";
	SetColor(8);  cout << " to EXIT game";
}


CGAME::CGAME(int level)
{
	this->m_level = level;
	mTFlightCar = new CTRAFFICLIGHT(COUNTDOWNCHANGELIGHT, GREEN);
	mTFlightTruck = new CTRAFFICLIGHT(COUNTDOWNCHANGELIGHT, GREEN);
}

void DrawBoundary() {
	SetColor(7);
	for (int i = 0; i <= colBoundary; i++) {
		GotoXY(i, 0); cout << char(220);
		GotoXY(i, rowBoundary); cout << char(220);
	}
	for (int i = 1; i <= rowBoundary; i++) {
		GotoXY(0, i); cout << char(219);
		GotoXY(colBoundary, i); cout << char(219);
	}
	for (int i = 1; i < colBoundary; ++i) {
		SetColor(7);
		GotoXY(i, 3); cout << char(220);
		GotoXY(i, 7); cout << char(220);
		GotoXY(i, 11); cout << char(220);
		GotoXY(i, 15); cout << char(220);
		GotoXY(i, 19); cout << char(220);
	}
	SetColor(7);
}

void CGAME::DrawGame()
{
	mPeople->DrawPeople();
	mTFlightCar->printTrafficLight(colBoundary, LANE_3);
	mTFlightTruck->printTrafficLight(0, LANE_4);
	for (CVEHICLE* cvehicle : mVehicles) {
		cvehicle->DrawVehicle();
	}
	for (CANIMAL* canimal : mAnimals) {
		canimal->DrawAnimal();
	}
}

CGAME::~CGAME()
{
	delete mPeople;
	delete mTFlightCar;
	delete mTFlightTruck;
}

CPEOPLE* CGAME::GetPeople()
{
	return mPeople;
}

void CGAME::ResetGame() {
	m_level = LEVEL_1;
	this->StartGame();
}

void CGAME::ExitGame(thread& t, bool& IS_RUNNING) {
	IS_RUNNING = false;
	if (t.joinable())
		t.join();
}


void CGAME::StartGame()
{
	system("cls");
	DrawBoundary();
	SpawnObject();
	if (mPeople)
		delete mPeople;
	this->mPeople = new CPEOPLE();
	printLevel();
	printHelp();
}

void CGAME::loadGame(const string& fileName, bool& succeeded) {
	ifstream fi;
	fi.open(fileName);
	if (!fi.is_open()) {
		succeeded = false;
		GotoXY(15, 25);
		SetColor(15); cout << "Cant't load game! Error";
		Sleep(2000);
		GotoXY(15, 25); cout << "                                       ";
		return;
	}

	int mX, mY, mState, mType, length;
	//read people
	fi >> mX >> mY >> mState;
	if (mPeople)
		delete mPeople;
	mPeople = new CPEOPLE(mX, mY, mState);
	//read vehicles
	fi >> length;
	mVehicles.clear();
	for (int i = 0; i < length; ++i) {
		fi >> mType >> mX;
		if (mType == 0)
			mVehicles.push_back(new CTRUCK(mX, LANE_4));
		else
			mVehicles.push_back(new CCAR(mX, LANE_3));
	}
	//read animals
	fi >> length;
	mAnimals.clear();
	for (int i = 0; i < length; ++i) {
		fi >> mType >> mX;
		if (mType == 0)
			mAnimals.push_back(new CBIRD(mX, LANE_2));
		else
			mAnimals.push_back(new CDINAUSOR(mX, LANE_1));
	}
	//read traffic light
	int mCount;
	fi >> mState >> mCount;
	delete mTFlightTruck;
	mTFlightTruck = new CTRAFFICLIGHT(mCount, mState);
	fi >> mState >> mCount;
	delete mTFlightCar;
	mTFlightCar = new CTRAFFICLIGHT(mCount, mState);
	//read block read level
	fi >> m_block >> m_level;
	GotoXY(XPAUSE + 5, YPAUSE + 1);
	SetColor(10); cout << "Load game successfull!";
	Sleep(300);
	GotoXY(XPAUSE + 5, YPAUSE + 1); cout << "                          ";
	fi.close();
	//print all 
	{
		system("cls");
		DrawBoundary();
		DrawGame();
		printHelp();
		printLevel();
	}
	succeeded = true;
}

void CGAME::saveGame(const string& fileName) {
	ofstream fo;
	fo.open(fileName, ofstream::trunc);
	if (!fo.is_open()) {
		GotoXY(25, 15);
		SetColor(15); cout << "Cant't save game! Error";
		Sleep(2000);
		GotoXY(25, 15); cout << "                                       ";
		return;
	}
	mPeople->saveGame(fo);
	//number of vehicle
	fo << mVehicles.size() << endl;
	for (CVEHICLE* vehicle : mVehicles) {
		if (dynamic_cast<CTRUCK*>(vehicle))
			fo << 0 << " ";
		else
			fo << 1 << " ";
		vehicle->saveGame(fo);
	}
	//number of animal
	fo << mAnimals.size() << endl;
	for (CANIMAL* animal : mAnimals) {
		if (dynamic_cast<CBIRD*>(animal))
			fo << 0 << " ";
		else
			fo << 1 << " ";
		animal->saveGame(fo);
	}
	//state of traffic light
	mTFlightTruck->saveGame(fo);
	mTFlightCar->saveGame(fo);

	//block and level of game
	fo << m_block << " " << m_level;
	//check 
	if (fo) {
		GotoXY(XPAUSE + 5, YPAUSE + 1);
		SetColor(15); cout << "Save successfull!";
	}
	else {
		GotoXY(XPAUSE + 5, YPAUSE + 1);
		SetColor(15); cout << "Save ";
		SetColor(12); cout << "not";
		SetColor(15); cout << " successfull!";
	}
	Sleep(500);
	GotoXY(XPAUSE + 5, YPAUSE + 1); cout << "                                       ";
	fo.close();
}

void CGAME::PauseGame(HANDLE handle) {
	SuspendThread(handle);
}

void CGAME::ResumeGame(HANDLE handle) {
	ResumeThread(handle);
}

void CGAME::UpdatePosPeople(MOVING moving)
{
	switch (moving) {
	case 1:
	{
		mPeople->Up();
		break;
	}
	case 2:
	{
		mPeople->Down();
		break;
	}
	case 3:
	{
		mPeople->Left();
		break;
	}
	case 4:
	{
		mPeople->Right();
		break;
	}
	}
}

void CGAME::UpdatePosVehicle()
{
	mTFlightTruck->switchState(0, LANE_4);
	mTFlightCar->switchState(colBoundary, LANE_3);
	for (CVEHICLE* vehicle : mVehicles) {
		if (dynamic_cast<CTRUCK*>(vehicle))
			vehicle->Move(m_block * m_level, mTFlightTruck->getState());
		else
			vehicle->Move(m_block * m_level, mTFlightCar->getState());
	}
}

void CGAME::UpdatePosAnimal() {
	for (CANIMAL* animal : mAnimals) {
		animal->Move(m_block * m_level);
	}
}

void CGAME::SetNextLevel() {
	switch (m_level) {
	case LEVEL_1: {
		m_level = LEVEL_2;
		break;
	}
	case LEVEL_2: {
		m_level = LEVEL_3;
		break;
	}
	case LEVEL_3: {
		m_level = LEVEL_4;
		break;
	}
	case LEVEL_4: {
		m_level = LEVEL_5;
		break;
	}
	case LEVEL_5: {
		m_level = LEVEL_6;
		break;
	}
	case LEVEL_6: {
		m_level = LEVEL_7;
		break;
	}
	default: break;
	}

}



