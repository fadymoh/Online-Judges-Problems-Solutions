#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int mod = 998244353;
int dp[1001][2001][4];
int n, k;

int solve(int i, int cmp, int mask)
{
	if (cmp > k) return 0;
	if (i == n) return cmp == k;
	int &ret = dp[i][cmp][mask];
	if (~ret) return ret;
	ret = 0;
	if (mask == 1 || mask == 2) {
		ret += solve(i + 1, cmp, mask), ret %= mod;
		ret += solve(i + 1, cmp, mask ^ 1), ret %= mod;
		ret += solve(i + 1, cmp, mask ^ 2), ret %= mod;
		ret += solve(i + 1, cmp + 2, mask ^ 3), ret %= mod;
	}
	else
	{
		ret += solve(i + 1, cmp, mask), ret %= mod;
		ret += solve(i + 1, cmp + 1, mask ^ 1), ret %= mod;
		ret += solve(i + 1, cmp + 1, mask ^ 2), ret %= mod;
		ret += solve(i + 1, cmp + 1, mask ^ 3), ret %= mod;
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	int res = 0;
	memset(dp, -1, sizeof dp);
	res += solve(1, 1, 0), res %= mod;
	res += solve(1, 2, 1), res %= mod;
	res += solve(1, 2, 2), res %= mod;
	res += solve(1, 1, 3), res %= mod;
	cout << res << endl;
	return 0;
}