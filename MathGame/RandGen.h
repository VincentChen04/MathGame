#pragma once
class RandGen
{
public:
	RandGen();
	void genRandNum(int MODE);
	int getNum1();
	int getNum2();
	int getTotal();
	~RandGen();
private:
	int randNum1;
	int randNum2;
	int total;
};

