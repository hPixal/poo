#pragma once

struct hsStruct{
	public:
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
	char _name[20];
	int _points;
};

