#include "stdafx.h"
#include "GameCheck.h"
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
		printf("你所提交的答案错误,你失败了！\n");
		break;
	case 2:
		printf("内部程序出错.\n");
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
	int ipass = pass % 2 + 1;
	return ipass;
}


GameCheck::~GameCheck()
{
}
