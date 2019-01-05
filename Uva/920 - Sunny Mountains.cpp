#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define EPS 1e-9
struct line { double a, b, c; };          // a way to represent a line
struct point {
	double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
	bool operator < (point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x > other.x;          // first criteria , by x-coordinate
		return y < other.y;
	}          // second criteria, by y-coordinate
			   // use EPS (1e-9) when testing equality of two floating points
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
		l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
	}
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}
bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {           // also check coefficient c
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;            // no intersection
													  // solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else                  p.y = -(l2.a * p.x + l2.c);
	return true;
}

double dist(point p1, point p2) {                // Euclidean distance
												 // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double
point arr[101];
int main()
{
	int tc, n;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i].x >> arr[i].y;
		sort(arr, arr + n);
		int max_height = 0;
		double sum = 0;
		double x_cord;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i].y > max_height)
			{
				if (i == 1)
				{
					sum += sqrt((arr[i - 1].x - arr[i].x)*(arr[i - 1].x - arr[i].x) + (arr[i].y * arr[i].y));
					max_height = arr[i].y;
					x_cord = arr[i].x;
				}
				else
				{
					line l1, l2;
					point temp;
					pointsToLine(arr[i], arr[i - 1], l1);
					pointsToLine(point(arr[i].x, max_height), point(x_cord, max_height), l2);
					areIntersect(l1, l2, temp);
					sum += dist(temp, arr[i]);
					max_height = arr[i].y;
					x_cord = arr[i].x;
				}
			}
		}
		cout << fixed << setprecision(2) <<sum << endl;
	}
	return 0;
}