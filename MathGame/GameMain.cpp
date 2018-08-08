#include "stdafx.h"
#include "GameMain.h"
#include "RandGen.h"
#include "GameCheck.h"
RandGen randgen;
GameCheck checkEngine;

using namespace std;
GameMain::GameMain()
{
}

void GameMain::runGame()
{
	gameWhile();
}


GameMain::~GameMain()
{
}

int GameMain::getGamePoint()
{
	return this->GamePoint;
}

void GameMain::gameWhile()
{
	do {
		int inputNum;
		randgen.genRandNum(randgen.EASY_MODE);
		printf("请回答: %d + %d = \t", randgen.getNum1(), randgen.getNum2());
		scanf_s("%d", &inputNum);
		if (inputNum == randgen.getTotal()) {
			++GameMain::GamePoint;
			printf("你获得了1分数！你现在的分数为%d\n",GameMain::GamePoint);
		} else { 
			checkEngine.setStopcode(1, 2);
			printf("你的总分为%d, 加油！",GameMain::GamePoint);
		}
	} while (!checkEngine.isStop());
}

