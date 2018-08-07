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
	RandGen::randNum1 = 10 + rand() % 90;
	RandGen::randNum2 = 10 + rand() % 90;
	RandGen::total = getNum1() + getNum2();
}

int RandGen::getNum1()
{
	return RandGen::randNum1;
}

int RandGen::getNum2()
{
	return RandGen::randNum2;
}

int RandGen::getTotal()
{
	return RandGen::total;
}

RandGen::~RandGen()
{
}
