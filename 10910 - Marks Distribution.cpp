#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n, t, p;
int memo[71][71];
int dp(int i, int val)
{
	int &ret = memo[i][val];
	if (val > t || i > n) return 0;
	if (i == n)
	{
		if (val == t) return 1;
		return 0;
	}
	if (ret != -1) return ret;
	int max_val = t - n * p;
	ret = 0;
	for (int j = p; j <= p + max_val; ++j)
		ret += dp(i + 1, j + val);
	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> t >> p;
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0) << endl;
	}
	return 0;
}