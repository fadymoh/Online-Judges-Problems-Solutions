#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define EPS 1e-6
struct point {
	double x, y;     // whenever possible, work with point_i
	point() { x = y = 0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}
};          // constructor	
bool eq(double a, double b) { return fabs(a - b) < EPS; }
int dblcmp(double a, double b) {
	if (eq(a, b)) return 0;
	if (a < b) return -1;
	return 1;
}
double dist_sq(point p, point c)
{
	return sqrt((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y));
}
int insideCircle(point p, point c, double r)
{
	// -1, 0, 1: inside, on, outside
	return dblcmp(dist_sq(p, c), r*r);
}
bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
}         // to get the other center, reverse p1 and p2
int main()
{
	int n;
	double r;
	point arr[101];
	while (cin >> n, n != 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> arr[i].x >> arr[i].y;
		cin >> r;
		int best = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n ; ++j)
			{
				point center_one, center_two;
				circle2PtsRad(arr[i], arr[j], r, center_one);
				circle2PtsRad(arr[j], arr[i], r, center_two);
				int c1 = 0;
				for (int x = 0; x < n; ++x)
				{
					if (insideCircle(arr[x], center_one, r) != 1)
					{
						++c1;
					}
				}
				int c2 = 0;
				for (int x = 0; x < n; ++x)
				{
					if (insideCircle(arr[x], center_two, r) != 1)
					{
						++c2;
					}
				}
				best = max(best, max(c1, c2));
			}
		}
		if (best ==n) cout << "The polygon can be packed in the circle.\n";
		else cout << "There is no way of packing that polygon.\n";
	}

	return 0;
}