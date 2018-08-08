#pragma once
class GameMain
{
public:
	GameMain();
	void runGame();
	~GameMain();
	int getGamePoint();
private:
	int GamePoint = 0;
	void gameWhile();
};

