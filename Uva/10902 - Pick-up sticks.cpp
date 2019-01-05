#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <list>
using namespace std;
#define EPS 1e-9
#define cross(a, b) ((a).x * (b).y - (a).y * (b).x)
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
	point operator - (point other) const {
		return point(x - other.x, y - other.y);
	}
};
struct line { double a, b, c; };          // a way to represent a line
enum dir { RIGHT, LEFT, ON };
struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

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

int main()
{
	pair<point, point> arr[100001];
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n, n != 0)
	{
		list<int> top_items;

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].first.x >> arr[i].first.y >> arr[i].second.x >> arr[i].second.y;
			for (auto it = top_items.begin(); it != top_items.end(); ++it)
			{
				if (segment_segment_intersect(arr[*it].first, arr[*it].second, arr[i].first, arr[i].second))
				{
					it = top_items.erase(it), --it;
				}
			}
			top_items.push_back(i);
		}
		cout << "Top sticks: ";
		int i = 0;
		for (auto it = top_items.begin(); it != top_items.end(); ++it, ++i)
			cout << *it + 1 << ((i + 1 == top_items.size()) ? ".\n" : ", ");
	}
	return 0;
}