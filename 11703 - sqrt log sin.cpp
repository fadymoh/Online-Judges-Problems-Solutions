#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
int memo[1000001];
int n;
int dp(int i)
{
	int &ret = memo[i];
	if (ret != -1)
		return ret;
	if (i == 0)return 1;
	return ret = (dp(floor(i-sqrt(i))) + dp(floor(log(i))) + dp(floor(i * sin(i) * sin(i)))) % 1000000;
}
int main()
{
	memset(memo, -1, sizeof memo);
	dp(1000000);
	while (cin >> n, n != -1)
	{
		cout << dp(n) << endl;
	}
	return 0;
}