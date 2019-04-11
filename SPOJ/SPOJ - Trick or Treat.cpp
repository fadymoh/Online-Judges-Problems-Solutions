#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
pair<double, double> house[50001];
#define EPS 1e-10
double finalX;
double f(double X) {
	double timeNeeded = 0;
	for (int i = 0; i < n; ++i)
		timeNeeded = max(timeNeeded,sqrt((X - house[i].first)*(X - house[i].first) + (house[i].second) * (house[i].second)));
	return timeNeeded;
}
double ternary(double s, double e) {
	while (e - s > EPS) {
		double g = s + (e - s) / 3;
		double h = s + 2 * (e - s) / 3;
		if (f(g) < f(h)) // change < to > if inc then dec
			e = h;
		else
			s = g;
	}
	finalX = e;
	return f(e);
}
int main()
{
	while (scanf("%d", &n), n != 0)
	{
		for (int i = 0; i < n; ++i)
			scanf("%lf %lf", &house[i].first, &house[i].second);
		printf("%.9f %.9f\n",finalX, ternary(-1e9, 1e9));
	}
	printf("%d", ternary(0, 1e9));
	return 0;
}