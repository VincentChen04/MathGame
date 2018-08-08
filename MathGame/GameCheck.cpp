#include "stdafx.h"
#include "GameCheck.h"
#include "GameMain.h"
#include <vector>
using namespace std;
GameCheck::GameCheck()
{
}

bool GameCheck::isStop()
{
	if (GameCheck::stopCode == 0) {
		return false;
	}
	switch (GameCheck::stopCode) {
	case 1:
		printf("输掉了游戏的原因为提交答案错误。\n");
		break;
	case 2:
		printf("没有这个难度值，请重新键入。.\n");
		break;
	default:
		printf("发生了未知错误");
		;
	}
	return true;

}

void GameCheck::setStopcode(int code, int setPass)
{
	if (encrypt(setPass) == code) {
		GameCheck::stopCode = code;
	}
}
int GameCheck::encrypt(int pass)
{
	int ipass = pass / 2 + 1;
	return ipass;
}


GameCheck::~GameCheck()
{
}
