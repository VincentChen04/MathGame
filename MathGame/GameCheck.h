#pragma once
class GameCheck
{
public:
	GameCheck();
	bool isStop();
	void setStopcode(int code,int setPass);
	~GameCheck();
private:
	int stopCode=0;
};

