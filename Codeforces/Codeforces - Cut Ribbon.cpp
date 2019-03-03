#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int arr[3];
int dp[100005];
int dp2[100005][3];
int solve(int len)
{
	int &ret = dp[len];
	if (len == 0) return 0;
	if (len < 0) return -1e9;
	if (ret != -1) return ret;
	int mx = 0;
	for (int i = 0; i < 3; ++i)
		mx = max(mx, solve(len - arr[i]) + 1);
	return ret = mx;
}
int solve2(int len, int currentRope)
{
	if (len == 0) return 0;
	if (len < 0) return -1e9;
	int &ret = dp2[len][currentRope];
	if (ret != -1) return ret;
	return ret = max(solve2(len - arr[currentRope], currentRope) + 1, solve2(len, currentRope + 1));
}
int main()
{
	cin >> n >> arr[0] >> arr[1] >> arr[2];
	//memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp2);
	cout << solve2(n, 0) << endl;
	return 0;
}