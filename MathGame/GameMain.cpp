#include "stdafx.h"
#include "GameMain.h"

using namespace std;

GameMain::GameMain()
{
	saves.init();
	printf("��Ҫѡ���ĸ��Ѷ��أ�\n");
	printf("1) ����ģʽ\t����򵥵�20���ڼӼ� \n");
	printf("2) ��ͨģʽ\t�����˿��Գ��ܵ��Ѷ�\n");
	printf("3) ѧ��ģʽ\t�������Դ�ѧ��������\n");
	printf("4) ���ģʽ\t��ѧ���˵�����\n");
	printf("5) ר��ģʽ\t�������˽����Ҷ��ѵ��⾳.\n");
	printf("6) Vincent������\t���Ƿ�������Ŀ�����룡\n ");
	printf("���������Ҫѡ���Ѷȵ���š�\t");
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
	saves.~PlaySaver(); 
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

