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
	void Login();
	void Register(string username);
	bool AccountExist(string username);
	int genUserID(string username);
	string genENCCode(string username,int uid, string password);
	~PlaySaver();
private:
	fstream Saves;
	vector<string> SaveData;
	string username;
	string password;
	string enccode;
	int uid;
};

