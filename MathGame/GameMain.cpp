#include "stdafx.h"
#include "GameMain.h"
#include "RandGen.h"
#include "GameCheck.h"
RandGen randgen;
GameCheck checkEngine;
int RandMode;
using namespace std;
GameMain::GameMain()
{
	printf("��Ҫѡ���ĸ��Ѷ��أ�\n1) ����ģʽ\t����򵥵�20���ڼӼ� \n2) ��ͨģʽ\t�����˿��Գ��ܵ��Ѷ�\n3) ѧ��ģʽ\t�������Դ�ѧ��������\n4) ���ģʽ\t��ѧ���˵�����\n5) ר��ģʽ\t�������˽����Ҷ��ѵ��⾳.\n6) Vincent������\t���Ƿ�������Ŀ�����룡\n ���������Ҫѡ���Ѷȵ���š�");
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
		printf("��ش�: %d + %d = \t", randgen.getNum1(), randgen.getNum2());
		scanf_s("%d", &inputNum);
		if (inputNum == randgen.getTotal()) {
			++GameMain::GamePoint;
			printf("������1�����������ڵķ���Ϊ%d\n",GameMain::GamePoint);
		} else { 
			checkEngine.setStopcode(1, 0);
			printf("�����ˣ��ܷ�Ϊ%d.",GameMain::GamePoint);
		}
	} 
}

