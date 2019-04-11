#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int K = 1000 + 5;
const int M = 50 + 5;
int k, m;
int memo[K][M];
int weight[M];
int value[M];
int dp(int curWeight, int idx)
{
	int &ret = memo[curWeight][idx];
	if (idx >= m || curWeight > k) return 0;

	if (~ret) return ret;
	if (curWeight + weight[idx] > k) return ret = dp(curWeight, idx + 1);
	return ret = max(value[idx] + dp(curWeight + weight[idx], idx + 1), dp(curWeight, idx + 1));
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &k, &m);
		for (int i = 0; i < m; ++i)
			scanf("%d %d", weight + i, value + i);
		memset(memo, -1, sizeof memo);
		printf("Hey stupid robber, you can get %d.\n", dp(0, 0));
	}

	return 0;
}