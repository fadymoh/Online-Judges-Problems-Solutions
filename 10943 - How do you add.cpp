#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n, k;
int memo[110][110];
int dp(int num, int rem)
{
	int &ret = memo[num][rem];
	if (rem == 1) return 1;
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= num; ++i)
		ret = (ret + dp(num - i, rem - 1)) % 1000000;
	return ret;
}
int main()
{
	while (cin >> n >> k, n != 0)
	{
		memset(memo, -1, sizeof(memo));
		cout << dp(n, k)<< endl;
	}
	return 0;
}