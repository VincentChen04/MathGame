#pragma once
class GameCheck
{
public:
	GameCheck();
	bool isStop();
	void setStopcode(int code,int setPass);
	~GameCheck();
private:
	int encrypt(int pass);
	int stopCode=0;
};

