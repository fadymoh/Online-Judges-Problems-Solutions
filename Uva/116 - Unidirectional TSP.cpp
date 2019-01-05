#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[11][101];
int memo[11][101];
int path[11][101];
int n, m;
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (i < 0 || i > m || j > n) return 100000;
	if (j == n)
		return 0;
	if (ret != 100000) return ret;
	int first = i - 1, second = i, third = i + 1;
	if (i == 0) first = m - 1;
	if (i == m - 1) third = 0;
	int temp = arr[i][j] + dp(first, j + 1);
	if (ret > temp || (ret == temp && path[i][j] > first)) path[i][j] = first, ret = temp;
	temp = arr[i][j] + dp(second, j + 1);
	if (ret > temp || (ret == temp && path[i][j] > second)) path[i][j] = second, ret = temp;
	temp = arr[i][j] + dp(third, j + 1);
	if (ret > temp || (ret == temp && path[i][j] > third)) path[i][j] = third, ret = temp;
	return ret;
}
int main()
{
	while (cin >> m >> n, !cin.eof())
	{
		for (int i = 0; i < 11; ++i)
			for (int j = 0; j < 101; ++j) memo[i][j] = 100000;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];
		int minn = 100000;
		int idx;
		for (int i = 0; i < m; ++i)
		{
			if (dp(i, 0) < minn)
			{
				minn = memo[i][0];
				idx = i;
			}
		}

		for (int i = 0; i < n; ++i)
		{

			cout << idx % m + 1 << ((i == n - 1) ? '\n' : ' ');
			idx = path[idx][i];
		}
		cout << minn << endl;
	}
	return 0;
}