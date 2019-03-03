#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <intrin.h>
using namespace std;

int n, m;
int adjMat[20][20];
int sat[20];
int dp[1 << 18][20];
int solve(int msk, int lst)
{
	if (__popcnt(msk) == m) return 0;
	int &ret = dp[msk][lst];
	if (~ret) return ret;
	ret = 0;
	for (int i = 0; i < (1 << n); ++i)
	{
		if (((msk >>i) & 1) == 0)
			ret = max(ret, sat[i] + adjMat[lst][i] + solve(msk | (1 << i, i)));
	}
	return ret;
}

int main()
{
	int k;
	cin >> n >> m >> k;
	while (--k)
	{
		int x, y, z;
		cin >> x >> y >> z;
		adjMat[x][y] = z;
	}
	cout << solve(0, 0);
	return 0;
}