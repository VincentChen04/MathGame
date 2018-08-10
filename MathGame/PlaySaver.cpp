#include "stdafx.h"
#include "PlaySaver.h"


PlaySaver::PlaySaver()
{
}

void PlaySaver::init(){
	Login();
	//Saves.open("Saves/*.gamesave",ios::in|ios::out|ios::app);

	/*if (!Saves.fail()) {
		string s;
		while (getline(Saves, s)) {
			SaveData.push_back(s);
		}
	}*/
	
}

void PlaySaver::Login()
{
	
	printf("请输入您的账户名以访问账户,\n如果您暂时没有账户,系统将为您创建。");
	cin >> username;
	if ( AccountExist(username) ) {
		printf("请输入该账户的密码以获取访问权限\n");
		cin >> password;
		
	}
	else {
		Register(username);
	}

}

void PlaySaver::Register(string username)
{
	cout << "正在创建名字为" << username << "的账户。";
	printf("请输入您所想要设定的密码。\n");
	cin >> password;
	printf("正在为您创建账户，请稍候.....\n");
	Saves.open("Saves/" + username + ".gamesaves", ios::in | ios::out | ios::app);
	if (!Saves.fail()) {
		uid = genUserID(username);
		enccode = genENCCode(username,uid,password);
		Saves << "ENCCode="<<enccode<<"\n";
		Saves << "PlayerName=" << username << "\n";
		Saves << "PlayerUID="<<uid<<"\n";
		Saves << "Highscore=0 Mode=ASNOOB\n";
		Saves << "Highscore=0 Mode=NORMAL\n";
		Saves << "Highscore=0 Mode=SOHARD\n";
		Saves << "Highscore=0 Mode=INSAME\n";
		Saves << "Highscore=0 Mode=EXPERT\n";
		Saves << "Highscore=0 Mode=VTRIAL\n";
	}
	else {
		cout << "不能创建文件。";
		system("pause");
		exit(0);
	}

}

bool PlaySaver::AccountExist(string username)
{
	string str = "Saves/" + username + ".gamesaves";
	ifstream fin(str.c_str());
	if (!fin) {
		printf("没有该账户，即将为您创建账户。\n");
		fin.close();
		return false;
	}
	else {
		fin.close();
		return true;
	} 
}

int PlaySaver::genUserID(string username)
{	
	return (int)username[1]+(int)username[username.length()-1]+(int)username[(username.length()/2+1)]+1;
}

string PlaySaver::genENCCode(string username, int uid, string password)
{	
	string genenccode=username+password;
	return "[ENCRYPTv1.0.0]"+genenccode;
}



PlaySaver::~PlaySaver()
{
}
