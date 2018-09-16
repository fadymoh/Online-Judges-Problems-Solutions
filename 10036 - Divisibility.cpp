#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n, k;
int arr[10001];
int memo[10001][101];
bool dp(int i, int mod)
{
	if (i == n)
	{
		if (mod == 0)
		{
			return 1;
		}
		return 0;
	}
	int &ret = memo[i][mod];
	if (ret != -1) return ret;
	ret = 0;
	if (dp(i + 1, (((mod + arr[i]) % k) + k) % k)) return true;
	if (dp(i + 1, (((mod - arr[i]) % k) + k) % k)) return true;
	return false;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> k;
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		int temp = dp(1, (arr[0] + k) % k);
		cout << ((temp) ? "Divisible" : "Not divisible" )<< endl;
	}
	return 0;
}