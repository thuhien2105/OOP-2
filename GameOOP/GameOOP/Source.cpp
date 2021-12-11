#pragma once

#include "Console.h"
#include "CPEOPLE.h"
#include "CGAME.h"


enum MOVING {
	ILDE = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

MOVING moving;
bool RUNNING;
CGAME* GAME;


void KeyInput(char keyPress)
{
	if (keyPress == 'A') {
		moving = LEFT;
	}
	else if (keyPress == 'D') {
		moving = RIGHT;
	}
	else if (keyPress == 'W') {
		moving = UP;
	}
	else if (keyPress == 'S') {
		moving = DOWN;
	}
	else moving = ILDE;
}

void SubThread() {
	while (RUNNING) {
		if (!GAME->GetPeople()->IsDead()) {
			GAME->UpdatePosPeople(moving);
		}
		moving = ILDE;
		GAME->UpdatePosVehicle();
		GAME->UpdatePosAnimal();
		//draw animal, vehicla move and people
		GAME->DrawGame();

		if (GAME->GetPeople()->IsImpact()) {
			PlaySound(TEXT("dieSound.wav"), NULL, SND_ASYNC);
			GAME->GetPeople()->animationDie();
			// Xử lý khi đụng xe hay thú
			SetColor(14); GotoXY(XINFO - 10, YINFO); cout << "GAME OVERRRRRRRR!";
			SetColor(12); GotoXY(XINFO - 12, YINFO + 1); 
			cout << "Press ";SetColor(15); cout << "Y"; SetColor(12); cout << " To new game";
			GotoXY(XINFO - 12, YINFO + 2); cout << "Press "; SetColor(15); cout << "B"; SetColor(12); cout << " Back to Menu";
			GotoXY(XINFO - 12, YINFO + 3); cout << "Press any key to Exit.";

			RUNNING = false;
		}
		if (GAME->GetPeople()->IsFinish()) {
			// Xử lý khi về đích
			GAME->SetNextLevel();
			GAME->StartGame();
		}
		Sleep(250);
	}
}

void NewGame(bool &backToMenu) {
	animationLoading(XMENU, YMENU + 2, COUNTDOWN);
	bool Reset;
	do {
		Reset = false;
		bool Pause = false;

		if (!GAME) {
			GAME = new CGAME;
			GAME->StartGame();
		}
		RUNNING = true;
		thread threadgame(SubThread);
		while (true) {
			char KPress = toupper(_getch());

			if (!GAME->GetPeople()->IsDead()) {
				if (KPress == 27) {
					GAME->ExitGame(threadgame, RUNNING);
					delete GAME;  GAME = nullptr;
					return;
				}
				else if (KPress == 'B') {
					backToMenu = true;
					PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
					GAME->ExitGame(threadgame, RUNNING);
					animationLoading(XINFO - 10, YINFO - 2, COUNTDOWN);
					delete GAME;  GAME = nullptr;
					return;
				}
				else if (!Pause && KPress == 'P') {
					Pause = true;
					GAME->PauseGame((HANDLE)threadgame.native_handle());
					SetColor(15); GotoXY(XPAUSE, YPAUSE); cout << "Enter any keyboard to continue.....";
				}
				else if (!Pause && KPress == 'L') {
					GAME->PauseGame((HANDLE)threadgame.native_handle());
					Sleep(100);

					GotoXY(XPAUSE, YPAUSE); SetColor(11); cout << "Enter name file: ";
					string nameFile;
					SetColor(15); cin >> ws; getline(cin, nameFile);
					GAME->saveGame(nameFile);

					GotoXY(XPAUSE, YPAUSE); cout << "Enter any keyboard to continue game!";
					Pause = true;
				}
				else if (!Pause && KPress == 'T') {
					GAME->PauseGame((HANDLE)threadgame.native_handle()); 	
					Sleep(100);

					GotoXY(XPAUSE, YPAUSE); SetColor(11); cout << "Enter name file to load game: ";
					string FileName;
					SetColor(15); cin >> ws; getline(cin, FileName);
					bool check = false;
					GAME->loadGame(FileName, check);

					GotoXY(XPAUSE, YPAUSE); cout << "Enter any keyboard to continue.....!";
					Pause = true;
				}
				else {
					if (Pause) {
						Pause = false;
						GotoXY(XPAUSE, YPAUSE); cout << "                                    ";
						GAME->ResumeGame((HANDLE)threadgame.native_handle());
					}
					KeyInput(KPress);
				}
			}
			else {
				GAME->ExitGame(threadgame, RUNNING);
				if (KPress == 'Y') {
					Reset = true;
					PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
					animationLoading(XINFO-10 , YINFO- 2, COUNTDOWN - 10);
					break;
				}
				else if (KPress == 'B') {
					backToMenu = true;
					PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
					animationLoading(XINFO - 10, YINFO - 2, COUNTDOWN);
					delete GAME;  GAME = nullptr;
					return;
				}
				else {
					delete GAME;
					return;
				}
			}
		}
		delete GAME;  GAME = nullptr;
	} while (Reset);
}

void menuGame(bool &BacktoMenu)
{
	system("cls");
	string title[11] = { " ______    ______      ___      _____  ",
					     "| .--. )  | ,,,, |    /   \\    | ... \\ ",
		                 "| '--' /  | |  | |   / /'\\ \\   | | | |",
	                     "| | \\ \\   | |  | |  | |===| |  | | | | ",
		                 "| |  \\ \\  | '''' |  | .   . |  | |.' /  ",
		                 "---  ---  --------  ---   ---  -----'    ",
		};

	SetColor(10);
	for (int i = 0; i < 6; ++i) {
		GotoXY(40, i+5);
		cout << title[i];

	}
	// menu
	{
		SetColor(12);  GotoXY(XMENU , YMENU + 1); cout << "[1]"; SetColor(15); cout << " NEW GAME";
		SetColor(12); GotoXY(XMENU , YMENU + 2); cout << "[2]"; SetColor(15); cout << " LOAD GAME";
		SetColor(12); GotoXY(XMENU , YMENU + 3); cout << "[3]"; SetColor(15); cout << " SETTING";
		SetColor(12); GotoXY(XMENU , YMENU + 4); cout << "[4]"; SetColor(15); cout << " QUIT GAME";
		SetColor(14); GotoXY(XMENU , YMENU + 5); cout << "Enter | 1 | 2 | 3 | 4 | : ";
	}

	while (true) {
		SetColor(10);
		string choose;
		cin >> ws; getline(cin, choose);
		if (choose.size() == 1) {
			switch (choose[0]) {
			case '1':
			{
				NewGame(BacktoMenu);
				return;
			}
			case '2':
			{
				SetColor(14);  GotoXY(XMENU + 1, YMENU + 6);
				string fileName;
				cout << "Enter name file game:  ";
				SetColor(15);  cin >> ws; getline(cin, fileName);
				if (GAME) {
					delete GAME; GAME = nullptr;
				}
				GAME = new CGAME;
				bool LoadSuccess = false;
				GAME->loadGame(fileName, LoadSuccess);
				if (LoadSuccess) {
					NewGame(BacktoMenu);
				}
				else {
					BacktoMenu = true;
				}
				return;
			}
			case '3':
			{
				SetColor(11);  GotoXY(XMENU + 1, YMENU + 6);
				cout << "Enter level (1 ---> 7):  ";
				int lv;
				SetColor(15);
				do {
					cout << "\b";
					cin >> lv;
				} while (lv < 1 || lv > 7);
				if (GAME) {
					delete GAME; GAME = nullptr;
				}

				switch (lv) {
				case 1: { lv = LEVEL_1; break; }
				case 2: { lv = LEVEL_2; break; }
				case 3: { lv = LEVEL_3; break; }
				case 4: { lv = LEVEL_4; break; }
				case 5: { lv = LEVEL_5; break; }
				case 6: { lv = LEVEL_6; break; }
				case 7: { lv = LEVEL_7; break; }
				default:
					lv = LEVEL_1;
				}
				GAME = new CGAME(lv);
				GAME->StartGame();
				NewGame(BacktoMenu);

				return;
			}
			case '4':
			{
				return;
			}
			default:
			{
				GotoXY(XMENU , YMENU + 5);
				cout << "                                                                                                  ";
				SetColor(14);  GotoXY(XMENU + 1, YMENU + 5);
				cout << "Error! Enter again | 1 | 2 | 3 | 4 | : ";
			}
			}
		}
		else {
			GotoXY(XMENU, YMENU + 5);
			cout << "                                                                                                  ";
			SetColor(14);  GotoXY(XMENU + 1, YMENU + 5);
			cout << "Error! Enter again | 1 | 2 | 3 | 4 | : ";
		}
	}

}

int main()
{
	FixConsoleWindow();
	GetSizeOfConsole();
	HideCursor();
	PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
	bool BackToMenu;
	do {
		BackToMenu = false;
		menuGame(BackToMenu);
	} while (BackToMenu);

	return 0;
}