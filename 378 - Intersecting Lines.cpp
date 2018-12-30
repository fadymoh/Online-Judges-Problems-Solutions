#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define EPS 1e-9
struct point {
	double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
	bool operator < (point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		return y < other.y;
	}          // second criteria, by y-coordinate
			   // use EPS (1e-9) when testing equality of two floating points
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};
struct line { double a, b, c; };          // a way to represent a line
bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
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
int main()
{
	int tc;
	cin >> tc;
	cout << "INTERSECTING LINES OUTPUT\n";
	while (tc--)
	{
		point one, two, three, four;
		line first, second;
		cin >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y >> four.x >> four.y;
		pointsToLine(one, two, first);
		pointsToLine(three, four, second);
		if (areSame(first, second)) cout << "LINE\n";
		else if (areParallel(first, second)) cout << "NONE\n";
		else if (areIntersect(first, second, one)) cout << fixed << setprecision(2)<<"POINT " << one.x << ' ' << one.y << endl;
	}
	cout << "END OF OUTPUT\n";

	return 0;
}