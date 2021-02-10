#pragma once

struct hsStruct{
	char _name[20];
	int _points;
	/*bool operator>(player aux){
		if (player.score>this->score)
		{
			return true;
		}
		return false;
	}*///La comente porque me parece que sort usa solo <, no >
	hsStruct(){

	}
	hsStruct(char name[20], int points){
		for (int i = 0; i < 20; i++)
		{
			_name[i]=name[i];
		}
		
		this->_points = points;
	}
	bool operator<(hsStruct aux){
		if (this->_points<aux._points)
		{
			return true;
		}
		return false;
	}
	bool operator>(hsStruct aux){
		if (this->_points>aux._points)
		{
			return true;
		}
		return false;
	}
};

