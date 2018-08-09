#include "stdafx.h"
#include "PlaySaver.h"


PlaySaver::PlaySaver()
{
}

void PlaySaver::init(){

	Saves.open("MathGameSave.save",ios::in|ios::out|ios::app);
	if (!Saves.fail()) {
		string s;
		while (getline(Saves, s)) {
			SaveData.push_back(s);
		}
	}
	
}



PlaySaver::~PlaySaver()
{
	Saves.close();
}
