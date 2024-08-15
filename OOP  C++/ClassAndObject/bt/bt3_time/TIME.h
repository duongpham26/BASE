#pragma once
#ifndef time_h
#define time_h
#include <iostream>

class time 
{
	int gioi, phut, giay;
public:
	time(int h = 0, int m = 0, int s = 0)
	{
		gioi = h;
		phut = m;
		giay = s;
	}
	void set(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	int getHour();
	int getMinute();
	int getSecond();
	void display();
	void displayStandard();
	void tick();
};
#endif 
