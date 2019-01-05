#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define EPS 1e-9
struct line { double a, b, c; };
enum dir { RIGHT, LEFT, ON };
struct point {
	double x, y;
	point() { x = y = 0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && fabs(y < other.y) < EPS);
	}
	point operator - (point other) const {
		return point(x - other.x, y - other.y);
	}
};
#define cross(a, b) ((a).x * (b).y - (a).y * (b).x)
dir get_dir(const point & v, const point & u)
{
	int d = cross(v, u);
	if (!d)
	{
		return ON;
	}
	return d > 0 ? RIGHT : LEFT;
}

bool on_seg(const point & p, const point & q, const point & a)
{
	// is a inside pq
	return (a.x >= min(p.x, q.x) && a.x <= max(p.x, q.x))
		&& (a.y >= min(p.y, q.y) && a.y <= max(p.y, q.y));
}
bool segment_segment_intersect(const point & p, const point & q,
	const point & a, const point & b)
{
	dir x = get_dir(q - p, a - p);
	dir y = get_dir(q - p, b - p);
	dir w = get_dir(b - a, p - a);
	dir z = get_dir(b - a, q - a);
	if (x == ON && on_seg(p, q, a))
	{
		// a is on pq
		return true;
	}
	if (y == ON && on_seg(p, q, b))
	{
		// b is on pq
		return true;
	}
	if (w == ON && on_seg(a, b, p))
	{
		// p is on ab
		return true;
	}
	if (z == ON && on_seg(a, b, q))
	{
		// q is on ab
		return true;
	}
	return (x != y) && (w != z);
}
bool isInsideRectangle(point p1, point p2, point p3)
{
	if (p3.x <= max(p1.x, p2.x)
		&& p3.x >= min(p1.x, p2.x)
		&& p3.y <= max(p1.y, p2.y)
		&& p3.y >= min(p1.y, p2.y))
		return true;

	return false;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
		//if (xstart > xend) swap(xstart, xend), swap(ystart, yend);
		if (isInsideRectangle(point(xleft, ytop), point(xright, ybottom), point(xstart, ystart)) ||
			isInsideRectangle(point(xleft, ytop), point(xright, ybottom), point(xend, yend)))
			cout << "T" << endl;
		else if (segment_segment_intersect(point(xleft, ytop), point(xleft, ybottom), point(xstart, ystart), point(xend, yend))
			|| segment_segment_intersect(point(xleft, ytop), point(xright, ytop), point(xstart, ystart), point(xend, yend))
			|| segment_segment_intersect(point(xright, ybottom), point(xright, ytop), point(xstart, ystart), point(xend, yend))
			|| segment_segment_intersect(point(xright, ybottom), point(xleft, ybottom), point(xstart, ystart), point(xend, yend)))
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}
	return 0;
}