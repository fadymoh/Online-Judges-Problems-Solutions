#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int oxy, nit, n;
const int N = 1002;
const int M = 80;
int oxygen[N], nitrogen[N], weight[N];
int dp[N][M][M];
int recurse(int i, int curOxy, int curNit)
{
	if (curOxy >= oxy && curNit >= nit) return 0;
	if (i >= n) return 10000000;
	int &ret = dp[i][curOxy][curNit];
	if (ret != -1) return ret;
	return ret = min(recurse(i + 1, curOxy, curNit),
		weight[i] + recurse(i + 1, min(curOxy + oxygen[i], oxy), min(curNit + nitrogen[i], nit)));
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &oxy, &nit);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", &oxygen[i], &nitrogen[i], &weight[i]);
		memset(dp, -1, sizeof dp);
		cout << recurse(0, 0, 0) << endl;
	}
	return 0;
}