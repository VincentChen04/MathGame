#include "stdafx.h"
#include "GameCheck.h"


GameCheck::GameCheck()
{
}

bool GameCheck::isStop()
{
	if (GameCheck::stopCode == 0) {
		return false;
	} else return true;

}

void GameCheck::setStopcode(int code, int setPass)
{
}


GameCheck::~GameCheck()
{
}
