#include "DATE.h"
using namespace std;

void date::print()
{
	int year;
	year = nam % 100;
	cout << "Ngay hien tai: "
		<< (ngay < 10 ? "0" : "") << ngay << "/"
		<< (thang < 10 ? "0" : "") << thang << "/" 
		<< (year < 10 ? "0" : "") << year  << endl;
}