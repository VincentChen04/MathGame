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
		printf("��ش�: %d + %d = \t", randgen.getNum1(), randgen.getNum2());
		scanf_s("%d", &inputNum);
		if (inputNum == randgen.getTotal()) {
			++GameMain::GamePoint;
			printf("������1�����������ڵķ���Ϊ%d\n",GameMain::GamePoint);
		} else { 
			checkEngine.setStopcode(1, 2);
			printf("����ܷ�Ϊ%d, ���ͣ�",GameMain::GamePoint);
		}
	} while (!checkEngine.isStop());
}

