#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int memo[101][20000];
int coins[101];
int x[101], cnt = 0;
int dp(int i, int j)
{
	if (j == 0) return 0;

	if (i == n || j < 0) return 100000;
	int &ret = memo[i][j];
	if (ret != -1) return ret;
	return ret = min(dp(i + 1, j), dp(i+1, j - coins[i]) + 1);
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cnt = 0;
		memset(memo, -1, sizeof(memo));
		cin >>s  >> n;
		for (int i = 0; i < n; ++i)
			cin >> coins[i];
		int val = 0, i = s;
		for (; i <= s + 10000; ++i)
		{
			int temp = dp(0, i);
			if (temp <= 10001)
			{
				val = temp;
				break;
			}
		}
		cout << i << ' ' << val << endl;
	}
	return 0;
}