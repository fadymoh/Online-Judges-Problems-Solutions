#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int N = 101;
const int M = 21;
int n, m;
pair<int, int> girlfriend[M];
int dp[M][N];
int recurse(int i, int rem)
{
	if (rem == 0 && i == m) return 1;
	if (i > m && rem > 0) return 0;
	int &ret = dp[i][rem];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = girlfriend[i].first; j <= girlfriend[i].second; ++j)
		if (rem - j >= 0) ret += recurse(i + 1, rem - j);
	return ret;
}
int main()
{
	while (scanf("%d %d", &m, &n), n != 0 || m != 0) {
		for (int i = 0; i < m; ++i)
			scanf("%d %d", &girlfriend[i].first, &girlfriend[i].second);
		memset(dp, -1, sizeof dp);
		cout << recurse(0, n) << endl;
	}
	return 0;
}