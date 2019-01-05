#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, n != 0)
	{
		int arr[101][101];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
				arr[i][j] = (arr[i][j] == 1) ? -10000 : 1;
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}
		int maxx = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int x = i; x < n; ++x)
					for (int y = j; y < m; ++y)
					{
						int sub = arr[x][y];
						if (i > 0) sub -= arr[i - 1][y];
						if (j > 0) sub -= arr[x][j - 1];
						if (i > 0 && j > 0) sub += arr[i - 1][j - 1];
						maxx = max(maxx, sub);
					}
		cout << maxx << endl;
	}
	system("pause");
	return 0;
}