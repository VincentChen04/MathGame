#pragma once
#include "RandGen.h"
#include "GameCheck.h"
#include "PlaySaver.h"
class GameMain
{
public:
	GameMain();
	void runGame();
	~GameMain();
	int getGamePoint();
private:
	int GamePoint = 0;
	void gameWhile();
	RandGen randgen;
	GameCheck checkEngine;
	PlaySaver saves;
	int RandMode;
};

