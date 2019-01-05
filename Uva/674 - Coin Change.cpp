#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int coins[5] = { 1, 5, 10, 25, 50 };
int n = 5;
int memo[6][7500];
int dp(int type, int value)
{
	int &ret = memo[type][value];

	if (value == 0)
		return 1;
	if (value < 0 || type == n)
		return 0;

	if (ret != -1) return ret;

	return ret = dp(type + 1, value) + dp(type, value - coins[type]);
}
int main()
{
	memset(memo, -1, sizeof(memo));
	int v;
	while (cin >> v, !cin.eof())
		cout << dp(0, v) << "\n";
	return 0;
}