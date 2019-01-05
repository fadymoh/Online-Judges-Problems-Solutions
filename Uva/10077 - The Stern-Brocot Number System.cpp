#include <iostream>
using namespace std;

int main()
{
	int  x, y, e, f;
	while (cin >> x >> y, x != 1 || y != 1)
	{
		int a = 0, b = 1, c = 1, d = 0;
		while (true)
		{
			e = a + c, f = b + d;
			if (e == x && f == y) break;
			else if (e * y > x * f) {
				c = e, d = f;
				cout << "L";
			}
			else {
				a = e, b = f;
				cout << "R";
			}
		}
		cout << endl;
	}
	return 0;
}