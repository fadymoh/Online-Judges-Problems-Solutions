#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <functional>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define rep(i, a, b) 	for (int i = int(a); i <= int(b); i++)
void change(long &DD, long &days, long &MM, int val)
{
	if (DD + days > val) { MM++; days = days - (val + 1 - DD); DD = 1; }
	else { DD += days; days = 0; }
}
bool IsLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
int main()
{
	long days, DD, MM, YY;
	while (cin >> days >> DD >> MM >> YY, YY){
		int year;
		(IsLeapYear(YY)) ? year = 366 : year = 365;
		while (days > year) {
			YY++;
			days -= year;
			(IsLeapYear(YY)) ? year = 366 : year = 365;
		}
		while (days > 0){
			switch (MM){
			case 1:
				change(DD, days, MM, 31);
				break;
			case 2:
				(IsLeapYear(YY)) ? change(DD, days, MM, 29) : change(DD, days, MM, 28);
				break;
			case 3:
				change(DD, days, MM, 31);
				break;
			case 4:
				change(DD, days, MM, 30);
				break;
			case 5:
				change(DD, days, MM, 31);
				break;
			case 6:
				change(DD, days, MM, 30);
				break;
			case 7:
				change(DD, days, MM, 31);
				break;
			case 8:
				change(DD, days, MM, 31);
				break;
			case 9:
				change(DD, days, MM, 30);
				break;
			case 10:
				change(DD, days, MM, 31);
				break;
			case 11:
				change(DD, days, MM, 30);
				break;
			default:
				change(DD, days, MM, 31);
			}
			if (MM == 13) { MM = 1; YY++; }
		}
		cout << DD << " " << MM << " " << YY << endl;
	}
	system("pause");
	return 0;
}

