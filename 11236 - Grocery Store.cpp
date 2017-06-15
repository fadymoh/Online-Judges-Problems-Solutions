#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	 int a, b, c, p, d, s;
	
	for (a = 1; 4*a <= 2000; a++)
		for (b = a; a + 3*b <= 2000; b++)
		for (c = b; a + b + 2 * c <= 2000; c++)
		{
			p = (long long)a*b*c;
			if (p <= 1000000) continue;
			s = (a + b + c);
			if (s * 1000000 % (p - 1000000)) continue;
			d = s * 1000000 / (p - 1000000);
			if (a + b + c + d > 2000 || d < c) continue;
			printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, d / 100, d % 100);
		}				
	system("pause");
	return 0;
}