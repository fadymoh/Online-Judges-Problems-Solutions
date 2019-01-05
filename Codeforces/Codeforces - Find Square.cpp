#include <iostream>
#include <cmath>
using namespace std;
int arr[116][116];

int main()
{
	int n, m, save_x, save_y, counter = 0;
	cin >> n >> m;
	bool first = true, found = false;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char x;
			cin >> x;
			arr[i][j] = x;
			if (arr[i][j] == 66)
			{
				if (first)
					save_x = i, save_y = j, first = false;
				++counter;
			}
		}
	}

	int size = sqrt(counter);
	cout << save_x + size / 2 << ' ' << save_y + size / 2 << endl;
	return 0;
}