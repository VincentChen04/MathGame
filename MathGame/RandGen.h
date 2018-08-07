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
	const int HELL_MODE=5,EXPERT_MODE = 4,HARD_MODE = 3, MEDIUM_MODE = 2, EASY_MODE = 1, NOOB_MODE = 0;
};

