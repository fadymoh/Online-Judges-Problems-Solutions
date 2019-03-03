#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;

int arr[101];
int dp[101][101];
int solve(int start, int end)
{
	if (start == end) return 0;
	int &ret = dp[start][end];
	if (~ret) return ret;
	int sumC = 0;
	for (int i = start; i <= end; ++i)
		sumC += arr[i];
	int leftColor = 0;
	ret = 1e9;
	for (int i = start; i <= end; ++i)
	{
		int sub1 = solve(start, i);
		int sub2 = solve(i + 1, end);
		int cost = sub1 + sub2;
		leftColor += arr[i];
		int rc = (sumC - leftColor) % 100;
		leftColor %= 100;
		ret = min(ret, cost + leftColor*rc);
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n)!= EOF)
	{
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		printf("%d\n", solve(0, n));
	}
	return 0;
}