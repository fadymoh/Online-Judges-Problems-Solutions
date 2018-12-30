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
struct vec {
	double x, y;  // name: `vec' is different from STL vector
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}
point translate(point p, vec v) {        // translate p according to v
	return point(p.x + v.x, p.y + v.y);
}
int main()
{
	point one, two, three, four;
	while (cin >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y >> four.x >> four.y, !cin.eof())
	{
		vec first = toVec(one, two);
		vec second = toVec(three, four);
		if (one.x == three.x && one.y == three.y)
		{
			cout << fixed << setprecision(3) <<two.x + four.x - one.x << ' ' << two.y + four.y - one.y << endl;
		}
		else if (one.x == four.x && one.y == four.y)
		{
			cout << fixed << setprecision(3) << two.x + three.x - one.x << ' ' << two.y + three.y - one.y << endl;
		}
		else if (two.x == three.x && two.y == three.y)
		{
			cout << fixed << setprecision(3)<< one.x + four.x - two.x << ' ' << one.y + four.y - two.y << endl;
		}
		else {
			cout << fixed << setprecision(3)<< one.x + three.x - two.x << ' ' << one.y + three.y - two.y << endl;

		}
	}
	return 0;
}