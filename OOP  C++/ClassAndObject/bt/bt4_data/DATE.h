#pragma once
#ifndef DATA_H
#define DATA_H
#include <iostream>
class date 
{
	int ngay, thang, nam;
public:
	date(int d = 1, int m = 1, int y = 1)
	{
		ngay = d;
		thang = m;
		nam = y;
	}
	void print();
};
#endif // !DATA_H
