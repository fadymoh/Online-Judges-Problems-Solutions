#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000 + 10;
int weight[N];
int n, maxWeight;
int memo[N][N];
int dp(int idx, int curWeight)
{
	int &ret = memo[idx][curWeight];
	if (idx == n) return 0;
	if (~ret) return ret;
	if (weight[idx] + curWeight > maxWeight) return ret = dp(idx+1, curWeight);
	return ret = max(dp(idx + 1, curWeight), weight[idx] + dp(idx + 1, curWeight + weight[idx]));
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &maxWeight);
		for (int i = 0; i < n; ++i)
			scanf("%d", weight + i);
		memset(memo, -1, sizeof memo);
		printf("%d\n", dp(0, 0));
	}
	return 0;
}