#include "TIME.h"
#include <Windows.h>
using namespace std;

void time::set(int h, int m, int s) 
{
	gioi = (h >= 0 && h < 24) ? h : 0;
	phut = (m >= 0 && m < 60) ? m : 0;
	giay = (s >= 0 && s < 60) ? s : 0;
}

void time::setHour(int h)
{
	gioi = h;
}

void time::setMinute(int m)
{
	phut = m;
}

void time::setSecond(int s)
{
	giay = s;
}

int time::getHour() 
{
	return gioi;
}

int time::getMinute()
{
	return phut;
}

int time::getSecond()
{
	return giay;
}

void time::display() 
{
	cout << "Gioi hien tai la: " 
		<< (gioi < 10 ? "0" : "") << gioi << ":" 
		<< (phut < 10 ? "0" : "") << phut << ":" 
		<< (giay < 10 ? "0" : "") << giay << endl;
}

void time::displayStandard()
{
	int h = gioi % 12;
	h = (h == 0) ? 12 : h;
	cout << "Gioi theo chuan: "
		<< (h < 10 ? "0" : "") << h << ":"
		<< (phut < 10 ? "0" : "") << phut << ":"
		<< (giay < 10 ? "0" : "") << giay << " " << (gioi < 12 ? "AM" : "PM" )<< endl;

}

void time::tick()
{
	giay++;
	if (giay == 60)
	{
		giay = 0;
		phut++;
		if (phut == 60)
		{
			phut = 0;
			gioi++;
			if (gioi == 24)
			{
				gioi = 0;
			}
		}
	}
}