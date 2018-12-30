#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int k, n;
short values[10000];
bool dp[10000][101];
bool DPFunc(int lvl, int sum)
{
	bool &ret = dp[lvl][sum];
	if (lvl == n) return (sum % k) == 0;
	if (ret != 1) return ret;
	ret = 0;
	return DPFunc(lvl + 1, (sum + values[lvl]) % k ) || DPFunc(lvl + 1, (sum - values[lvl]) % k);
}
int main()
{
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			cin >> values[i];
			values[i] %= k;
		}
		memset(dp, 1, sizeof dp);
		if (DPFunc(1, values[0])) cout << "Divisible\n";
		else cout << "Not divisible\n";
	}

	return 0;
}