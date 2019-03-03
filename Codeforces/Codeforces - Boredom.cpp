#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
long long dp[1000005];
long long freq[1000005];

long long solve(int ind)
{
	if (ind >= 100005)
		return 0;
	long long &ret = dp[ind];
	if (~ret) return ret;
	long long ch1 = solve(ind + 1);
	long long ch2 = solve(ind + 2) + freq[ind] * ind;
	return ret = max(ch1, ch2);
}

int main()
{
	cin >> n;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		++freq[temp];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(0) << endl;
	return 0;
}