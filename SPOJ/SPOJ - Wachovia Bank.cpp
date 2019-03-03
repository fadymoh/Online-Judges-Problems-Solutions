#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int M = 51;
int k, m;
int weight[M], value[M];
int dp[51][1251];

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &k, &m);
		for (int i = 1; i <= m; ++i)
			scanf("%d %d", &weight[i], &value[i]);
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= m; ++i)
		{
			for (int curWeight = 0; curWeight <= k; ++curWeight)
			{
				dp[i][curWeight] = dp[i - 1][curWeight];
				if (curWeight >= weight[i])
					dp[i][curWeight] = max(dp[i][curWeight], 
						dp[i - 1][curWeight - weight[i]] + value[i]);
			}
		}
		printf("Hey stupid robber, you can get %d.\n", dp[m][k]);
	}
	return 0;
}