#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2001;
const int M = 2001;
int dp[N][M];
string firstStr, secondStr;
int firstSize, secondSize;
int editDistance(int n, int m)
{
	if (n == 0) return m;
	if (m == 0) return n;
	int &ret = dp[n - 1][m - 1];
	if (ret != -1) return ret;
	if (firstStr[n - 1] == secondStr[m - 1]) return ret = editDistance(n - 1, m - 1);
	return ret = 1 + min(editDistance(n - 1, m), min(editDistance(n, m - 1), editDistance(n - 1, m - 1)));
}
int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		memset(dp, -1, sizeof dp);
		cin >> firstStr >> secondStr;
		firstSize = firstStr.length();
		secondSize = secondStr.length();
		printf("%d\n", editDistance(firstSize, secondSize));
	}

	return 0;
}