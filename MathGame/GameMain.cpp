#include "stdafx.h"
#include "GameMain.h"

using namespace std;

GameMain::GameMain()
{
	saves.init();
	printf("您要选择哪个难度呢？\n");
	printf("1) 菜鸟模式\t极其简单的20以内加减 \n");
	printf("2) 普通模式\t正常人可以承受的难度\n");
	printf("3) 学霸模式\t计算量稍大，学霸请无视\n");
	printf("4) 疯狂模式\t数学狂人的试炼\n");
	printf("5) 专家模式\t颇有众人皆醉我独醒的意境.\n");
	printf("6) Vincent的试炼\t这是非人类题目，慎入！\n ");
	printf("请键入您所要选择难度的序号。\t");
	scanf_s("%d", &RandMode);
	--RandMode;
	if (RandMode < 0 || RandMode > 5) checkEngine.setStopcode(2, 2);
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
	while (!checkEngine.isStop()) {
		int inputNum;
		randgen.genRandNum(RandMode);
		printf("请回答: %d + %d = \t", randgen.getNum1(), randgen.getNum2());
		scanf_s("%d", &inputNum);
		if (inputNum == randgen.getTotal()) {
			++GameMain::GamePoint;
			printf("你获得了1分数！你现在的分数为%d\n",GameMain::GamePoint);
		} else { 
			checkEngine.setStopcode(1, 0);
			printf("你输了，总分为%d.",GameMain::GamePoint);
		}
	} 
}

