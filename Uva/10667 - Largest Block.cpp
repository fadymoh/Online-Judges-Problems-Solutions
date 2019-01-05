#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int arr[102][102], n, blocks;
		cin >> n >> blocks;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				arr[i][j] = 1;
		for (int no = 0; no < blocks; ++no)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int i = x1; i <= x2; ++i)
			{
				for (int j = y1; j <= y2; ++j)
				{
					arr[i][j] = -10000;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i > 1) arr[i][j] += arr[i - 1][j];
				if (j > 1) arr[i][j] += arr[i][j - 1];
				if (i > 1 && j > 1) arr[i][j] -= arr[i - 1][j - 1];
			}
		}

		int maxx = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int x = i; x <= n; ++x)
					for (int y = j; y <= n; ++y)
					{
						int sub = arr[x][y];
						if (i > 1) sub -= arr[i - 1][y];
						if (j > 1) sub -= arr[x][j - 1];
						if (i > 1 && j > 1) sub += arr[i - 1][j - 1];
						maxx = max(maxx, sub);
					}
		cout << maxx << endl;
	}
	system("pause");
	return 0;
}