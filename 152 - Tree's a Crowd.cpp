#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
#define EPS 1e-9
struct point {
	double x, y, z;   // only used if more precision is needed
	point() { x = y = z = 0.0; }                      // default constructor
	point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}        // user-defined
	bool operator < (point other) const { // override less than operator
		if (fabs(x - other.x) > EPS)                 // useful for sorting
			return x < other.x;          // first criteria , by x-coordinate
		else if (fabs(y - other.y) > EPS)
			return y < other.y;
		return z < other.z;
	}          // second criteria, by y-coordinate
	//		   // use eps (1e-9) when testing equality of two floating points
	//bool operator == (point other) const {
	//	return (fabs(x - other.x) < eps && (fabs(y - other.y) < eps));
	//}
};
int dist(point p1, point p2) {                // Euclidean distance
												 // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + ( p1.z - p2.z) * (p1.z - p2.z));
}           // return double
int main()
{
	point arr[5001];
	double x, y, z;
	int i = 0;
	while (cin >> x >> y >> z, x != 0 || y != 0 || z != 0) arr[i++] = point(x, y, z);
	sort(arr, arr + i);
	int final_arr[10] = { 0 };
	for (int x = 0; x < i; ++x)
	{
		int minn = 100000;
		bool flag = false;
		for (int y = 0; y < i; ++y)
		{
			if (x == y) continue;
			int temp = dist(arr[x], arr[y]);
			if (temp < 10)
			if (temp < minn)
			{
				minn = temp;
				flag = true;
			}
		}
		if (flag)
			final_arr[minn] += 1;
	}

	for (int i = 0; i < 9; ++i)
		cout <<fixed <<setw(4) <<final_arr[i];
	cout << fixed <<setw(4)<<final_arr[9] << endl;
	return 0;
}