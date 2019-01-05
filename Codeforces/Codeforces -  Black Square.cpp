#include <iostream>
#include <vector>
#include <algorithm>
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
struct coord {
	int x, y;
	coord(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (coord other) const {
		if (x > other.x) return x < other.x;
		else return y < other.y;
	}
};
int main()
{
	int n, m;
	cin >> n >> m;
	bool grid[101][101] = {0};
	vector<coord> mVector;
	char temp;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			if (temp == 'B') mVector.push_back(coord(i+1, j+1));
		}
	int minimum_x = 200, minimum_y = 200, maximum_x = -1, maximum_y = -1;
	for (int i = 0; i < mVector.size(); ++i)
	{
		coord first = mVector[i];
		minimum_x = min(minimum_x, first.x);
		minimum_y = min(minimum_y, first.y);
		maximum_x = max(maximum_x, first.x);
		maximum_y = max(maximum_y, first.y);
	}
	int width = maximum_x - minimum_x + 1;
	int height = maximum_y - minimum_y + 1;
	if (mVector.size() == 0)
		cout << 1 << endl;
	if (height < width)
	{
		if (width > n)
			cout << -1 << endl;
		else
			cout << width * width - mVector.size() << endl;
	}
	else if (height > width)
		if (height > m)
			cout << -1 << endl;
		else cout << height * height - mVector.size() << endl;
	else
		cout << height * width - mVector.size() << endl;
	return 0;

}