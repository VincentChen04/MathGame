#include "stdafx.h"
#include "RandGen.h"
#include <time.h>
#include <stdlib.h>

RandGen::RandGen()
{
	srand((unsigned int)(time(NULL)));
}
void RandGen::genRandNum(int MODE)
{
	switch (MODE) {
	case 0:
		RandGen::randNum1 = rand() % 9;
		RandGen::randNum2 = rand() % 9;
		RandGen::total = getNum1() + getNum2();
		break;
	case 1:
		RandGen::randNum1 = 10 + rand() % 90;
		RandGen::randNum2 = 10 + rand() % 90;
		RandGen::total = getNum1() + getNum2();
		break;
	case 2:
		RandGen::randNum1 = 100 + rand() % 900;
		RandGen::randNum2 = 100 + rand() % 900;
		RandGen::total = getNum1() + getNum2();
		break;
	case 3:
		RandGen::randNum1 = 1000 + rand() % 9000;
		RandGen::randNum2 = 1000 + rand() % 9000;
		RandGen::total = getNum1() + getNum2();
		break;
	case 4:
		RandGen::randNum1 = 10000 + rand() % 90000;
		RandGen::randNum2 = 10000 + rand() % 90000;
		RandGen::total = getNum1() + getNum2();
		break;
	case 5:
		RandGen::randNum1 = 100000 + rand() % 900000;
		RandGen::randNum2 = 100000 + rand() % 900000;
		RandGen::total = getNum1() + getNum2();
		break;
	default:
		;
	}
}

int RandGen::getNum1()
{
	return this->randNum1;
}

int RandGen::getNum2()
{
	return this->randNum2;
}

int RandGen::getTotal()
{
	return this->total;
}

RandGen::~RandGen()
{
}
