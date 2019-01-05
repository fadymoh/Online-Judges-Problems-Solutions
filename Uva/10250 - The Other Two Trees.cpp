#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }
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
point rotate(point p, double theta, point about) {
	double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
	p.x -= about.x;
	p.y -= about.y;
	double s = sin(rad);
	double c = cos(rad);
	point nw;
	nw.x = p.x * c - p.y * s;
	nw.y = p.x * s + p.y * c;

	return point(nw.x + about.x, nw.y + about.y);
}
int main()
{
	point a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> a.x >> a.y >> b.x >> b.y, !cin.eof())
	{
		point w_r_t((a.x + b.x) / 2, (a.y + b.y) / 2);
		point a_rotated = rotate(a, -90, w_r_t);
		point b_rotated = rotate(b, -90, w_r_t);
		cout << fixed << setprecision(10)<<a_rotated.x << ' ' << a_rotated.y << ' ' << b_rotated.x << ' ' << b_rotated.y << endl;
	}
	return 0;
}