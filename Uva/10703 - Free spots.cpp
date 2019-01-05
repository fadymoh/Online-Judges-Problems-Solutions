#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int w, h, n;
	while (cin >> w >> h >> n, w != 0)
	{
		bool arr[501][501] = { 0 };
		for (int x = 0; x < n; ++x) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			for (int i = x1; i <= x2; ++i)
			{
				for (int j = y1; j <= y2; ++j)
				{
					arr[i][j] = 1;
				}
			}
		}
		int counter = 0;
		for (int i = 1; i <= w; ++i)
			for (int j = 1; j <= h; ++j)
				counter += !(arr[i][j]);
		if (counter == 0)
			cout << "There is no empty spots.\n";
		else if (counter == 1)
			cout << "There is one empty spot.\n";
		else cout << "There are " << counter << " empty spots.\n";
	}
}