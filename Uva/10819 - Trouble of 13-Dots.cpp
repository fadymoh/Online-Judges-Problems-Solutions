#include <iostream>
#include <algorithm>
using namespace std;
int m, n;
int p[101];
int v[101];
int memo[101][10001];
int dp(int i, int j)
{
	int &ret = memo[i][j];
	if (j > m && m < 1800) return -100000;
	if (j > m + 200) return -100000;
	if (i == n)
	{
		if (j > m && j <= 2000)
			return -100000;
		return 0;
	}
	if (ret != -1) return ret;
	return ret = max(dp(i + 1, j), v[i] + dp(i + 1, j + p[i]));
}
int main()
{
	while (cin >> m >> n, !cin.eof())
	{
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; ++i)
		{
			cin >> p[i] >> v[i];
		}
		cout << dp(0, 0) << endl;
	}
	system("pause");
	return 0;
}