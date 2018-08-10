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
	
	printf("�����������˻����Է����˻�,\n�������ʱû���˻�,ϵͳ��Ϊ��������");
	cin >> username;
	if ( AccountExist(username) ) {
		printf("��������˻��������Ի�ȡ����Ȩ��\n");
		cin >> password;
		
	}
	else {
		Register(username);
	}

}

void PlaySaver::Register(string username)
{
	cout << "���ڴ�������Ϊ" << username << "���˻���";
	printf("������������Ҫ�趨�����롣\n");
	cin >> password;
	printf("����Ϊ�������˻������Ժ�.....\n");
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
		cout << "���ܴ����ļ���";
		system("pause");
		exit(0);
	}

}

bool PlaySaver::AccountExist(string username)
{
	string str = "Saves/" + username + ".gamesaves";
	ifstream fin(str.c_str());
	if (!fin) {
		printf("û�и��˻�������Ϊ�������˻���\n");
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
