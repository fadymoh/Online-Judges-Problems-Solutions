#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <functional>
#include <iomanip>
using namespace std;
int p, q, r, s, t, u;
#define EPS 1e-7
double f(double x)
{
	return p*exp(-x) + q*sin(x) + r* cos(x) + s * tan(x) + t*x*x + u;
}
double bisection()
{
	double low = 0, high = 1;
	while (low + EPS < high){
		double x = (low + high) / 2;
		if (f(low)*f(x) <= 0) high = x;
		else low = x;
	}
	return (low + high) / 2;
}
int main()
{
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		if (f(0) * f(1) > 0) cout << "No solution" << endl;
		else cout << fixed << setprecision(4) << bisection() << endl;
	}
	system("pause");
	return 0;
}