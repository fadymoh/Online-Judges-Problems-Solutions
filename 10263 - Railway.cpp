#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define EPS 1e-9

struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};
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
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s);
}               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}
double dist(point p1, point p2) {                // Euclidean distance
												 // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}           // return double

double distToLine(point p, point a, point b, point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));                  // translate a to c
	return dist(p, c);
}           // Euclidean distance between p and c

			// returns the distance from p to the line segment ab defined by
			// two points a and b (still OK if a == b)
			// the closest point is stored in the 4th parameter (byref)

double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);                   // closer to a
		return dist(p, a);
	}         // Euclidean distance between p and a
	if (u > 1.0) {
		c = point(b.x, b.y);                   // closer to b
		return dist(p, b);
	}         // Euclidean distance between p and b
	return distToLine(p, a, b, c);
}          // run distToLine as above

int main()
{
	point m;
	int n;
	while (cin >> m.x >> m.y, !cin.eof())
	{
		cin >> n;
		++n;
		vector <point> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i].x >> arr[i].y;
		double sum = 10000000;
		point out;
		for (int i = 0; i < n-1; ++i)
		{
			point temp;
			double value = distToLineSegment(m, arr[i], arr[i + 1], temp);
			if (value < sum)
			{
				out = temp;
				sum = value;
			}
		}
		cout << fixed << setprecision(4) << out.x << endl << out.y << endl;
	}
	return 0;
}