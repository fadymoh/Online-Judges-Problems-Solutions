#include <iostream>
#include <cmath>
using namespace std;

#define EPS 1e-15
double d;
bool valid(double a)
{
	double b = d / a;
	return a * b < a + b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> d;
		double st = 0, sz = sqrt(d);
		for(;sz > EPS; sz /= 2)
		{
			double a = st + sz / 2;
			if (valid(a)) {
				st += sz / 2;
			}
		}
		double b = d / st;
		if (abs(st + b - d) < EPS)
			cout << "Y " << st << ' ' << b << endl;
		else
			cout << "N\n";
	}
	return 0;
}