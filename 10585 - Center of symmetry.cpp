#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define EPS 1e-9
#define INF 1e9
struct line { double a, b, c; };          // a way to represent a line

struct point {
	double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};
struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double angle(point a, point o, point b) {  // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}
double dist(point p1, point p2) {                // Euclidean distance
												 // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
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
bool areParallel(line l1, line l2) {       // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
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
	int tc, n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	point arr[10001];
	while (tc--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i].x >> arr[i].y;
		sort(arr, arr + n);
		point ans((arr[0].x + arr[n - 1].x) / 2, (arr[0].y + arr[n - 1].y) / 2);
		bool flag = false;
		for (int i = 1; i < n / 2 && !flag; ++i) {
			if (!(((arr[i].x + arr[n - 1 - i].x) / 2) == ans.x) || !(((arr[i].y + arr[n - 1 - i].y) / 2) == ans.y))
				flag = true;
		}
		if (n & 1)
			if (!(arr[n / 2].x == ans.x) || !(arr[n / 2].y == ans.y)) flag = true;
		if (n == 1) cout << "yes\n";
		else if (flag) cout << "no\n";
			else cout << "yes\n";
	}
	return 0;
}