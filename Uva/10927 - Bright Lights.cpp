#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define EPS 1e-9
#define INF 1e9
int counter = 0;
struct point {
	double x, y;   // only used if more precision is needed
	point() { x = y = 0.0; }                      // default constructor
	point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
	bool operator < (point other) const;      // second criteria, by y-coordinate
			   // use EPS (1e-9) when testing equality of two floating points
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
bool point::operator<(point other) const
{
	point origin(0, 0);
	double angle_mine = angle(*this, origin, point(1, 0));
	double angle_other = angle(other, origin, point(1, 0));
	if (fabs(angle_mine - angle_other) > EPS)
		return angle_mine < angle_other;
	return dist(*this, origin) < dist(other, origin);
}
bool cmp(point &first, point& second)
{
	if (fabs(first.x - second.x) > EPS)                 // useful for sorting
		return first.x < second.x;          // first criteria , by x-coordinate
	return first.y < second.y;

}
int main()
{
	pair<point, int> arr[100001];
	int n;
	while (cin >> n, n != 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> arr[i].first.x >> arr[i].first.y >> arr[i].second;
		sort(arr, arr + n);
		point origin(0, 0);
		double current_angle = angle(arr[0].first, origin, point(INF, 0));
		current_angle *= ccw(arr[0].first, origin, point(INF, 0)) ? 1 : -1;
		int max_h = arr[0].second;
		vector<point> output;
		for (int i = 1; i < n; ++i)
		{
			double temp_angle = angle(arr[i].first, origin, point(INF, 0));
			temp_angle *= ccw(arr[i].first, origin, point(INF, 0)) ? 1 : -1;
			if (fabs(current_angle - temp_angle) < EPS)
			{
				if (arr[i].second <= max_h)
					output.push_back(arr[i].first);
				else max_h = arr[i].second;
			}
			else
			{
				current_angle = temp_angle;
				max_h = arr[i].second;
			}
		}
		sort(output.begin(), output.end(), cmp);
		cout << "Data set " << ++counter << ":\n";
		if (output.size() == 0)
			cout << "All the lights are visible.\n";
		else {
			cout << "Some lights are not visible:\n";
			int size = output.size();
			for (int i = 0; i < size; ++i)
				cout << "x = " << output[i].x << ", y = " << output[i].y << ((i == size-1) ? ".\n" : ";\n");
		}
	}
	return 0;
}