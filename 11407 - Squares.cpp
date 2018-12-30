#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int dp[10001];
int backtrack(int N)
{
	int &ret = dp[N];
	if (ret != -1) return ret;
	if (N == 0) return 0;
	ret = 101;
	for (int i = 0; i*i <= N; ++i)
	{
		ret = min(ret, 1 + backtrack(N - i * i));
	}
	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	memset(dp, -1, sizeof dp);
	while (tc--)
	{
		cin >> n;
		cout << backtrack(n) << endl;
	}
	return 0;
}