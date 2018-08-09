#pragma once
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class PlaySaver
{
public:
	PlaySaver();
	void init();
	~PlaySaver();
private:
	fstream Saves;
	vector<string> SaveData;
};

