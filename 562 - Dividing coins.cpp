#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int tc, n, temp;
int memo[101][101*501];
int p[101];
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == n) return ret = 0;
	return ret = (j < p[i]) ?
		dp(i + 1, j) :
		max(dp(i + 1, j), p[i] + dp(i + 1, j - p[i]));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		int sum = 0;
		memset(memo, -1, sizeof(memo[0][0]) * 101 * 101*501);
		for (int i = 0; i < n; ++i)
		{
			cin >> p[i];
			sum += p[i];
		}
		int temp = dp(0, sum / 2);

		cout << sum - temp *2 << endl;
	}
	system("pause");
	return 0;
}