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
		printf("�������Ϸ��ԭ��Ϊ�ύ�𰸴���\n");
		break;
	case 2:
		printf("û������Ѷ�ֵ�������¼��롣.\n");
		break;
	default:
		printf("������δ֪����");
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
